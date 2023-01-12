FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y && apt-get install -y mariadb-server && apt-get install -y vim

COPY ./conf/config.sh /

COPY ./tools/init.sql /

RUN rm /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

RUN ["bash" ,"/config.sh"]

CMD mysqld_safe
