<p align="center">
<img align="center"   src="/images/Kafka-logo.png">
</p>

Repositório contendo examplos simples para usar o Apache Kafka com C++

<!-- CONTEUDO -->
<details open="open">
  <summary>Conteúdo</summary>
  <ol>
    <li>
      <a href="#introdução">Introdução Cpp</a> 
    </li>   
    <li>
      <a href="#requisitos-para-compilar">Requisitos para compilar</a> 
    </li>     
    <li>
      <a href="#exemplo-simples-em-avro-cpp">Exemplo simples em Avro Cpp</a> 
    </li> 
  </ol>
</details>

<!-- INTRODUÇÃO -->
## Introdução
A linguagem C++ é temida por muitos, porém a linguagem em si não é o problema, mas o ambiente para compilação/deploy é o que mais chateia em um ambiente profissional, em C/C++ lidamos com Make, CMake, libs e dll's e essa parte ainda se manteve em um processo mais manual, diferente de Java ou C#, em sistemas maiores, preparar um ambiente do zero não é algo trivial.

Esse problema do ambiente em si, foi minha maior motivação de iniciar esse curso em português(Brasil). O código em si eu sempre uso o 100% inglês pois há projetos ondem desenvolvedores de outros paises podem interagir.

O objetivo principal do curso é o Apache Kafka, muito ultilizado em sistemas com alto trafégo de informações, porém com pouca documentação em inglês, quanto mais em português.

> ***Esse curso não é voltado para iniciantes, caso queria aprender mais sobre os tópicos como C++,Apache Kafka, há diversos materais na internet que são uteis, abaixo cito algumas das minhas fontes.*** 

* [Livro do mestre(C++)](https://www.amazon.com.br/C-Programming-Language-Bjarne-Stroustrup/dp/0321563840)
* [Livro Apache Kafka(Java)](https://www.confluent.io/resources/kafka-the-definitive-guide/)
* [Livro sobre Integração usando padrões](https://www.amazon.com.br/gp/product/0321200683?pf_rd_r=5EXGARCAFTPM52TSJR5E&pf_rd_p=72a7651a-a7d8-4551-b248-c61480b6ce6e&pd_rd_r=ff720a8b-821d-4a4a-8cbb-893912f407da&pd_rd_w=W2FIe&pd_rd_wg=lBDya&ref_=pd_gw_unk)
* [Livro sobre Concorrência(C++)](https://www.amazon.com/C-Concurrency-Action-Anthony-Williams/dp/1617294691)

**Importante!** O objetivo desse material é voltado para o aprendizado em C++ de forma mais prática, portanto padrões de projeto, arquitetura , testes unitários não serão obrigatoriamente mencionados/ultilizados.

<!-- REQUISITOS PARA COMPILAR -->
## Requisitos para compilar
Para Simplicar as coisas eu criei imagens usando o Dockerhub, com essa ferramenta o programador dedica um esforço apenas uma vez para montar o ambiente salvando em uma imagem em algum repositório, caso não esteja usando ainda, há materiais em português e inglês no youtube so o assunto.

Eu criei 3 imagens:

1. **CentosOs 8** 
   - Nela já baixei o gcc 8, cmake 3, make, perl,boost 1.6 entre outras ferramentas.

2. **Bibliotecas para compilar**   
   - Nessa imagem todas as libs que compilo a partir do código(librdkafka, avro-cpp, avro-c, libserdes) e instalo elas no /user/local

3. **Código exemplos**   
   - Essa é a imagem do desenvolvimento em sí, dela contém os exemplos com Avro-cpp, librdkafka e libserdes e também a partir dela rodo a imagem [**Landoop**](https://github.com/lensesio/fast-data-dev) para rodar a kafka em si.
   
Para rodar o ambiente é necessário apenas instalar o **DockerHub** e **DockerCompose**, após instalar apenas rodar o comando dentro do diretório onde esta projeto.
```json
docker-compose.exe up -d --build 
```
Para parar os containers,digite no terminal
```json
docker-compose.exe down
```

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

 
