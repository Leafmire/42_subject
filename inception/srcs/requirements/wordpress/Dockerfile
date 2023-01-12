FROM debian:buster

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y wget && apt-get install -y php7.3 && apt-get install -y vim

RUN apt-get install -y php-xml \
    mariadb-client \
    php-mbstring \
    php-mysql \
    php-fpm \
    php-cli \
    curl

COPY ./tools/websetting.sh /

RUN mkdir -p /var/run/php/

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

RUN mkdir -p /var/www/html/myweb

COPY ./tools/index.html /var/www/html/myweb/

CMD ["bash", "./websetting.sh"]