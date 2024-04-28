#!/bin/sh

# MySQL 데이터 디렉토리 초기화
mysql_install_db --user=mysql --datadir=/var/lib/mysql

# setup.sql 파일 생성
cat << EOF > /setup.sql
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
DELETE FROM mysql.user WHERE user='';
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
FLUSH PRIVILEGES;
EOF

# setup.sql 스크립트를 사용하여 MySQL 서버를 --bootstrap 모드로 실행
mysqld --bootstrap --user=mysql --datadir='/var/lib/mysql' < /setup.sql

# MySQL 서버를 전경에서 실행하여 PID 1이 되도록 함
exec mysqld --user=mysql --datadir='/var/lib/mysql'
