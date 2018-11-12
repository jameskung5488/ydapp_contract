cleos wallet unlock --password PW5JaGpLtoM1vtD1WxiAC4RDsr82FRUczmKgocw1KJZqVahB4LZ1u
/usr/local/eosio/bin/eosiocpp -g ydappiotoken/ydappiotoken.abi  ydappiotoken/ydappiotoken.cpp
/usr/local/eosio/bin/eosiocpp -o ydappiotoken/ydappiotoken.wast ydappiotoken/ydappiotoken.cpp
# cleos -u http://api.eosbeijing.one set contract ydappiotoken ydappiotoken -p ydappiotoken@active

