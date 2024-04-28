FROM alpine:3.18.5

# Update APK repositories and upgrade all packages
RUN apk update && apk upgrade

# Install necessary PHP packages
RUN apk add --no-cache php81 php81-fpm php81-mysqli php81-json php81-openssl php81-curl \
    php81-zlib php81-xml php81-phar php81-intl php81-dom php81-xmlreader php81-ctype \
    php81-session php81-mbstring php81-gd curl

# Create the /var/www/ directory
RUN mkdir -p /var/www/

# Install wp-cli
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Download and install WordPress via wp-cli
RUN wp core download --path=/var/www/wordpress --allow-root

# Set ownership and permissions
RUN chown -R nobody:nobody /var/www/wordpress && \
    find /var/www/wordpress -type d -exec chmod 755 {} \; && \
    find /var/www/wordpress -type f -exec chmod 644 {} \;

# Add initialization script
COPY ./tools/setup-wordpress.sh /setup-wordpress.sh
COPY ./conf/www.conf /etc/php81/php-fpm.d/www.conf
RUN chmod +x /setup-wordpress.sh

# 컨테이너가 시작될 때 WordPress 초기화 스크립트를 실행한 후 PHP-FPM을 시작합니다.
ENTRYPOINT ["/setup-wordpress.sh"]
