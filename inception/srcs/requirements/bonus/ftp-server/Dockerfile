FROM debian:buster

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y vsftpd && apt-get install -y vim

COPY ./conf/config.sh /

COPY ./conf/vsftpd.conf /etc/

CMD ["bash", "/config.sh"]