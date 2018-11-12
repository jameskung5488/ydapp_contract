cleos wallet unlock --password PW5JaGpLtoM1vtD1WxiAC4RDsr82FRUczmKgocw1KJZqVahB4LZ1u
/usr/local/eosio/bin/eosiocpp -g ydappiotoken/ydappiotoken.abi  ydappiotoken/ydappiotoken.cpp
/usr/local/eosio/bin/eosiocpp -o ydappiotoken/ydappiotoken.wast ydappiotoken/ydappiotoken.cpp





cleos -u http://api.eosbeijing.one push action eosio.token transfer '[ "ydappiotoken", "pralaobai123", "989.9997 EOS" "Thank you for test ydappiotoken. Have a nice day!"]' -p ydappiotoken@active





cleos -u http://api.eosbeijing.one set contract ydappiotoken ydappiotoken -p ydappiotoken@active
cleos -u http://api-direct.eosasia.one push action ydappiotoken init '[]' -p ydappiotoken@active