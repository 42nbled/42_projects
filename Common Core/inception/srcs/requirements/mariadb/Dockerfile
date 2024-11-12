FROM debian:bullseye

#basic install
RUN DEBIAN_FRONTEND=noninteractive
RUN apt-get update -y && apt-get upgrade -y 
RUN apt-get install vim -y

#install mariadb
RUN apt-get install -y mariadb-server

#config mariadb
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/create_db.sh /usr/local/bin
RUN chmod +x /usr/local/bin/create_db.sh
 
ENTRYPOINT ["bash", "create_db.sh"]