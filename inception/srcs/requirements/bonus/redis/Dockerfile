FROM debian:buster

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y redis && apt-get install -y vim

COPY ./conf/config.sh /

COPY ./conf/redis.conf /etc/redis/

CMD ["bash", "/config.sh"]