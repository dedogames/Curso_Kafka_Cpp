<!-- AVRO CPP -->
## Exemplo simples em Avro Cpp

Criei um exemplo simples de serialização/desserialização para um objeto Trade referente ao mercado Bitcoin, o intuito desse curso é ser evolutivo, ou seja trabalhar com dados em reais da api, usando libcurl, threads, boost::asio , mongoDb entre outras ferramentas.

Para esse exemplo usei um schema simples representando um negócio do mercado Bitcoin, abaixo o schema no formato .json
```json
{
    "name": "Trade",
    "type": "record",
    "namespace":"Bitcoin",
    "fields":
    [
        {"name":"tid", "type":"string","doc":"Date and time of trading in the Unix Era" },
        {"name":"date", "type":"string","doc":"Negotiation identifier" },
        {"name":"type", "type":"string","doc":"Side trade(buy|sell)" },
        {"name":"price", "type":"string","doc":"Price" },
        {"name":"amount", "type":"string","doc":"Trading amount" }
    ]
 } 
```
E para torna as coisas mais simples abstrai o Avro-cpp, abaixo um exemplo em **C++**de como criar um negócio e serializar/desserialização.
```cpp
bitcoin::Trade trade("8615953", "1613358560", "buy", "263249.83999", "0.03000899");
trade.serialize();
trade.deserialize();
```

* [Referência Avro CPP](http://avro.apache.org/docs/current/api/cpp/html/index.html)

 
