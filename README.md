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

Esse problema do ambiente em si, foi minha maior motivação de iniciar esse curso em português(Brasil). O código em si eu sempre uso o inglês para codificar apeans por não te acente e manter os comentários e contants string em um padrão melhor.

O Core do curso é o Apache Kafka, muito ultilizado em sistemas com alto trafégo de informações.


**Importante!** O objetivo desse material é voltado para o aprendizado em C++ de forma mais prática, portanto padrões de projeto, arquitetura , testes unitários não serão obrigatoriamente mencionados/ultilizados.
<!-- AVRO CPP -->
## Exemplo simples em Avro Cpp
Criei um exemplo simples de serialização/desserialização para um objeto Trade referente ao mercado Bitcoin, o intuito desse curso é ser evolutivo, ou seja trabalhar com dados em reais do api, usando libcurl, threads, boost::asio , mongoDb entre outras ferramentas.




A Figura abaixo exibe log de um objeto Trade antes e depois de serializar.

[![avro-img-1]](https://github.com/dedogames/Curso_Kafka_Cpp)
[![avro-img-2]](https://github.com/dedogames/Curso_Kafka_Cpp)
[![avro-img-3]](https://github.com/dedogames/Curso_Kafka_Cpp)



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[avro-img-1]: https://github.com/dedogames/Curso_Kafka_Cpp/blob/main/images/screen_1.PNG
[avro-img-2]: https://github.com/dedogames/Curso_Kafka_Cpp/blob/main/images/screen_2.PNG
[avro-img-3]: https://github.com/dedogames/Curso_Kafka_Cpp/blob/main/images/screen_3.PNG
