#!/bin/sh

if [ ! -e "/var/www/wordpress/wp-config.php" ]; then
    mkdir -p /var/www/wordpress
    cd /var/www/wordpress
    wp core download --allow-root
    wp config create --dbname=$WORDPRESS_DB_NAME --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_PASSWORD --dbhost=$WORDPRESS_DB_HOST --skip-check
    wp core install --url=$DOMAIN_NAME --title="inception" --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL
    wp user create ${GUEST_USER} $GUEST_EMAIL --user_pass=$GUEST_PASSWORD
fi

# PHP-FPM 실행
exec php-fpm81 -F
