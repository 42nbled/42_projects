FROM debian:bullseye

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
    php7.4 \
    php7.4-fpm \
    php7.4-mysql \
    curl

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php
RUN chmod -R 777 /run/php

# Copy your custom configuration file
COPY conf/www.conf /etc/php/7.4/fpm/pool.d

WORKDIR /var/www/html

# Copy WordPress configuration files and entrypoint script

COPY ./conf/entrypoint.sh /usr/local/entrypoint.sh
RUN chmod +x /usr/local/entrypoint.sh
ENTRYPOINT ["/usr/local/entrypoint.sh"]