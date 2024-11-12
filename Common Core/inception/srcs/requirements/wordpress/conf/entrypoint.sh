#!/bin/sh
# set -eux

	sleep 5

if [ ! -f ./wp-config.php ]; then



	wp core download --path=/var/www/html --allow-root

	wp config create --allow-root \
		--dbname=$MARIADB_DATABASE \
		--dbuser=$MARIADB_USER \
		--dbpass=$MARIADB_PASSWORD \
		--dbhost=mariadb:3306 --path='/var/www/html'

	wp core install --title=$WORDPRESS_TITLE \
		--admin_user=$WORDPRESS_ADMIN_USER \
		--admin_password=$WORDPRESS_ADMIN_PASSWORD \
		--admin_email=$WORDPRESS_ADMIN_EMAIL \
		--url=$WORDPRESS_HOST --allow-root --skip-email


	wp user create --allow-root $WORDPRESS_USER $WORDPRESS_EMAIL --user_pass=$WORDPRESS_PASSWORD --role='author'


fi



/usr/sbin/php-fpm7.4 -F
