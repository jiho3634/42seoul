FROM debian:bullseye-slim

# Update package lists and upgrade packages
RUN apt-get update && apt-get upgrade -y

# Install MariaDB server and client
RUN apt-get install -y mariadb-server mariadb-client

# Ensure the MariaDB directory is present
RUN mkdir -p /run/mysqld/ && chown mysql:mysql /run/mysqld/

# Copy the MariaDB configuration file from your local directory
COPY ./conf/mariadb-server.cnf /etc/mysql/mariadb.conf.d/

# Copy your setup script into the container
COPY ./tools/setup.sh /setup.sh

# Ensure the setup script is executable
RUN chmod +x /setup.sh

# Expose port 3306 for MariaDB connections
EXPOSE 3306

# Set entrypoint to the setup script
ENTRYPOINT ["/setup.sh"]
