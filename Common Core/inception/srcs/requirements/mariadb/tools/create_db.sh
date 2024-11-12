#!/bin/sh

if [ -d "/var/lib/mysql/${MARIADB_DATABASE}" ]
then
	echo "${MARIADB_DATABASE} already exists"
else
	service mariadb start;
	#sleep 2
	mysql -e "CREATE DATABASE IF NOT EXISTS ${MARIADB_DATABASE};"
	mysql -e "CREATE USER IF NOT EXISTS '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"
	mysql -e "GRANT ALL PRIVILEGES ON ${MARIADB_DATABASE}.* TO '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';" # donner tous les droits a l'utilisateur
	mysql -e "GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';"
	mysqladmin -u root -p${MARIADB_ROOT_PASSWORD} shutdown
	#sleep 3
fi	
exec mysqld