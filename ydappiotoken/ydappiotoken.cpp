/**
 *  @dev minakokojima
 *  @copyright Andoromeda
 */

#include "ydappiotoken.hpp"

void ydappiotoken::init() {
    require_auth(_self);    
    auto g = _global.get_or_create(_self, global{});
    g.st = 1542067200;
    g.quota = 20000000;
    _global.set(g, _self); 
}  

void ydappiotoken::clear() {
    require_auth(_self);
}  

void ydappiotoken::onTransfer(account_name from, account_name to, extended_asset quantity, string memo){
    if (to != _self) return;
    require_auth(from);

    eosio_assert(quantity.contract == N(eosio.token), "must use EOS to buy YDAPP");
    eosio_assert(quantity.symbol == EOS_SYMBOL, "must use EOS to buy YDAPP");    

    eosio_assert(quantity.is_valid(), "Invalid token transfer");
    eosio_assert(quantity.amount > 0, "must buy a positive amount");

    auto g = _global.get();

    eosio_assert(now() >= g.st, "Ydapp crowdfunding event will start at 11/13/2018 @ 12:00pm (UTC).");
    eosio_assert(g.quota > 0, "All quota has been sold out, thank you!");

    if (quantity.amount <= g.quota) {
        action(
            permission_level{_self, N(active)},
            N(dacincubator), N(transfer),
            make_tuple(_self, from, asset(quantity.amount*2500, YDAPP_SYMBOL),
                std::string("exceed EOS refund"))
        ).send();         
        g.quota -= quantity.amount;

    } else {
        auto exceed = quantity.amount - g.quota;
        action(
            permission_level{_self, N(active)},
            N(eosio.token), N(transfer),
            make_tuple(_self, from, asset(exceed, EOS_SYMBOL),
                std::string("exceed EOS refund"))
        ).send();                     
        action(
            permission_level{_self, N(active)},
            N(dacincubator), N(transfer),
            make_tuple(_self, from, asset(g.quota*5000, YDAPP_SYMBOL),
                std::string("exceed EOS refund"))
        ).send();         
        g.quota = 0;
    }
    _global.set(g, _self);
}