# Curso_Kafka_Cpp
Repositório contendo examplos simples para usar o Apache Kafka com C++

<!-- CONTEUDO -->
<details open="open">
  <summary>Conteudo</summary>
  <ol>
    <li>
      <a href="#avro-cpp">Exemplo simples em Avro Cpp</a> 
    </li>    
  </ol>
</details>

<!-- INTRO -->
## Introdução
A linguagem C++ é temida por muitos, porém a linguagem em si não é o problema, mas o ambiente para compilação/deploy é o que mais chateia em um ambiente profissional, em C/C++ lidamos com Make, CMake, libs e dll's e essa parte ainda se manteve em um processo mais manual, diferente de Java ou C#, em sistemas maiores, preparar um ambiente do zero não é algo trivial.

Esse problema do ambiente em si, foi minha maior motivação de iniciar esse curso em português(Brasil). O código em si eu sempre uso o 100% inglês pois há projetos ondem desenvolvedores de outros paises podem interagir.

O objetivo principal do curso é o Apache Kafka, muito ultilizado em sistemas com alto trafégo de informações, porém com pouca documentação em inglês, quanto mais em português.

**Importante!** Esse curso não é voltado para iniciantes, caso queria aprender mais sobre os tópicos como C++, Apache Kafka, há diversos materais na internet que são uteis, abaixo cito algumas das minhas fontes.

[Livro do mestre(C++)](https://www.amazon.com.br/C-Programming-Language-Bjarne-Stroustrup/dp/0321563840)
Livro Apache Kafka(Java): (https://www.confluent.io/resources/kafka-the-definitive-guide/)
Integração usando padrões: (https://www.amazon.com.br/gp/product/0321200683?pf_rd_r=5EXGARCAFTPM52TSJR5E&pf_rd_p=72a7651a-a7d8-4551-b248-c61480b6ce6e&pd_rd_r=ff720a8b-821d-4a4a-8cbb-893912f407da&pd_rd_w=W2FIe&pd_rd_wg=lBDya&ref_=pd_gw_unk)
Concorrência(C++): (https://www.amazon.com/C-Concurrency-Action-Anthony-Williams/dp/1617294691)

**Importante!** O objetivo desse material é voltado para o aprendizado em C++ de forma mais prática, portanto padrões de projeto, arquitetura , testes unitários não serão obrigatoriamente mencionados/ultilizados.
<!-- AVRO CPP -->
## Exemplo simples em Avro Cpp

Criei um exemplo simples de serialização/desserialização para um objeto Trade referente ao mercado Bitcoin, o intuito desse curso é ser evolutivo, ou seja trabalhar com dados em reais do api, usando libcurl, threads, boost::asio , mongoDb entre outras ferramentas.

A Figura abaixo exibe log de um objeto Trade antes e depois de serializar.



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[avro-img-1]: https://github.com/dedogames/Curso_Kafka_Cpp/blob/main/images/screen_1.PNG
[avro-img-2]: https://github.com/dedogames/Curso_Kafka_Cpp/blob/main/images/screen_2.PNG
[avro-img-3]: https://github.com/dedogames/Curso_Kafka_Cpp/blob/main/images/screen_3.PNG
