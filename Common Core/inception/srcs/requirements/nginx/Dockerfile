FROM debian:bullseye

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y nginx openssl && \
    mkdir -p /var/www/html/ /etc/nginx/ssl

COPY conf/default.conf /etc/nginx/sites-available/default

RUN openssl req \
    -newkey rsa:4096 \
    -x509 \
    -sha256 \
    -days 365 \
    -nodes \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=nbled" \
    -keyout /etc/nginx/ssl/inception.key \
    -out /etc/nginx/ssl/inception.pem

CMD ["nginx", "-g", "daemon off;"]
