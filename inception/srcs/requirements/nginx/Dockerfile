FROM alpine:3.18.5

# Update APK repositories and upgrade all packages
RUN apk update && apk upgrade

# Nginx 및 OpenSSL 설치
RUN apk add --no-cache nginx openssl

# 웹 루트 디렉토리 생성 및 권한 설정
RUN mkdir -p /var/www/html && \
    chown -R nginx:nginx /var/www/html && \
    mkdir -p /run/nginx

# SSL 인증서와 개인 키를 위한 디렉토리 생성
RUN mkdir -p /etc/nginx/ssl

# 자체 서명된 SSL 인증서 생성
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=US/ST=Denial/L=Springfield/O=Dis/CN=www.example.com"

# Nginx 구성 파일 복사
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# 포트 443 개방
EXPOSE 443

# Nginx 실행
CMD ["nginx", "-g", "daemon off;"]
