FROM debian:buster

RUN apt-get update && apt-get install -y nginx && apt-get install -y vim && apt-get install -y openssl

RUN openssl req -new -newkey rsa:2048 -nodes -keyout cert.key -out cert.csr -subj "/C=KR/ST=Seoul/L=Gang-nam/O=SecureSignKR/OU=Dev Team/CN=example.com"

RUN openssl x509 -req -days 365 -in cert.csr -signkey cert.key -out cert.crt

RUN cp cert.key cert.key.secure
RUN openssl rsa -in cert.key.secure -out cert.key

RUN mv cert.crt cert.key /etc/ssl/certs/

RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

RUN rm -rf /etc/nginx/sites-enabled/default

COPY ./conf/default /etc/nginx/sites-enabled/

CMD nginx;
