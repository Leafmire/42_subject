#!/bin/bash

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

chmod 775 -R /var/www/html/

cd /var/www/html

if [ ! -d "/var/www/html/wp-admin/" ]
then
    wp core download --locale=ko_KR --allow-root
fi
if [ ! -f "/var/www/html/wp-config.php" ]
then
    wp config create --dbname=${MYSQL_DATABASE} --dbuser=${MYSQL_ROOT_USER} --dbpass=${MYSQL_ROOT_PASSWORD} --dbhost=${MYSQL_HOST} --allow-root
    wp core install --admin_user=${MYSQL_ROOT_USER} --admin_password=${MYSQL_ROOT_PASSWORD} --admin_email=gson@gmail.com --title=test --url=https://localhost --allow-root
    wp user create ${WORDPRESS_USER} ${WORDPRESS_EMAIL} --user_pass=${WORDPRESS_PASSWORD} --role=author --allow-root
fi
wp config set --add WP_REDIS_HOST redis:6379 --allow-root
wp config set --add WP_REDIS_DATABASE 0 --allow-root
wp config set --add WP_CACHE true --raw --allow-root
wp config set --add WP_REDIS_PORT 6379 --allow-root

wp plugin install redis-cache --activate --allow-root

wp plugin update --all --allow-root

wp redis enable --allow-root

mkdir -p /var/www/html/adminer
wget https://www.adminer.org/latest.php -O /var/www/html/adminer/index.php

php-fpm7.3 -F