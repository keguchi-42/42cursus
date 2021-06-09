# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/09 09:40:06 by keguchi           #+#    #+#              #
#    Updated: 2021/05/12 15:06:08 by keguchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update \
	&& apt-get install -y \
	vim \
	wget \
	sudo \
	nginx \
	mariadb-server \
	supervisor \
	php-cgi \
	php-common \
	php-fpm \
	php-pear \ 
	php-mbstring \
	php-zip \
	php-net-socket \
	php-gd \
	php-xml-util \
	php-gettext \
	php-mysql \
	php-bcmath

COPY	./srcs/ /tmp/
WORKDIR	/tmp/

#wordpress
RUN	wget https://wordpress.org/latest.tar.gz \
	&& tar -xvzf latest.tar.gz \
	&& rm latest.tar.gz \
	&& mv wordpress /var/www/html/ \
	&& mv wp-config.php /var/www/html/wordpress/ \
	&& chown -R www-data:www-data /var/www/html/wordpress \
    && mv default.tmpl /etc/nginx/sites-available/

#phpmyadmin
RUN	wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz \
	&& tar -xvzf phpMyAdmin-5.0.2-all-languages.tar.gz \
	&& rm phpMyAdmin-5.0.2-all-languages.tar.gz \
	&& mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin

#mysql
RUN	service mysql start \
	&& mysql -e "CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'password';" \
	&& mysql -e "CREATE DATABASE wordpress;" \
	&& mysql -e "GRANT ALL ON wordpress.* TO 'wordpress'@'localhost';" \
	&& mysql -e "FLUSH PRIVILEGES;" \
	&& mysql -e "exit"

#ssl
RUN	mkdir /etc/nginx/ssl \
	&& cd /etc/nginx/ssl \
	&& openssl req -newkey rsa:4096 \
		-x509 \
		-sha256 \
		-days 365 \
		-nodes \
		-out server.crt \
		-keyout private.key \
		-subj "/C=JP/ST=Tokyo/L=Roppongi/O=42tokyo/CN=keguchi"

#supervisor
WORKDIR	/tmp/
RUN	mv supervisord.conf /etc/supervisor/conf.d/supervisord.conf \
	&& chmod +x /etc/supervisor/conf.d/supervisord.conf

#entrykit
RUN	wget https://github.com/progrium/entrykit/releases/download/v0.4.0/entrykit_0.4.0_Linux_x86_64.tgz \
	&& tar -xvzf entrykit_0.4.0_Linux_x86_64.tgz \
	&& rm entrykit_0.4.0_Linux_x86_64.tgz \
	&& mv entrykit /bin/entrykit \
	&& entrykit --symlink

ENTRYPOINT	["render", "/etc/nginx/sites-available/default", "--", "/usr/bin/supervisord"]