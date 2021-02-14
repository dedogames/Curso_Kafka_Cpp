#########################################################
# Images:kafka_cpp_examples                             #
# Description:Images with source with examples to       #
#             consume/produce in kafka                  #
# Date: 05-02-2021                                      #
# Developer: Gelson Rodrigues                           #
#                                                       #
# Examples                                              #
#                                                       #
#  1 - Hello World: Simples consumer and producer       # 
#########################################################

 FROM kafka_serde_lib:latest


#----------------------------------------------------------------------------
# BUILD: docker build --no-cache -t kafka_cpp_examples:latest .                     
#----------------------------------------------------------------------------
# RUN--: docker run -it --rm --label "version=1.0" --label "maintaner=Gelson Rodrigues <geoldery@gmail.com>" --name kafka_cpp_examples_img kafka_cpp_examples:latest 
#----------------------------------------------------------------------------
 
#------------------------------------------
#          Hello World Avro               -
#------------------------------------------
RUN mkdir -p /projects/hello_avro_cpp/build
COPY /hello_avro_cpp/ /projects/hello_avro_cpp/
WORKDIR /projects/hello_avro_cpp/build 
#RUN cmake ../ &&\
#   make -j10 #10 is a number threads to compile 

#-------------------------------------------
#        Hello World LibKafka              -
#-------------------------------------------
#RUN mkdir -p /projects/hello_libkafka_cpp/build
#COPY /hello_libkafka_cpp/ /projects/hello_libkafka_cpp/
#WORKDIR /projects/hello_libkafka_cpp/build 
#RUN cmake ../ &&\
#   make -j10 #10 is a number threads to compilee
      
#-------------------------------------------
#           Hello World LibSerdes          -
#-------------------------------------------
# RUN mkdir -p /projects/hello_libserdes_cpp/build
# COPY /hello_libserdes_cpp/ /projects/hello_libserdes_cpp/
# WORKDIR /projects/hello_libserdes_cpp/build 
#RUN cmake ../ &&\
#   make -j10 #10 is a number threads to compile 

# CMD [ "/bin/bash" ] 


