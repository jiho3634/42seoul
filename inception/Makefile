# Makefile for Docker-based System Administration Infrastructure Project

# Variables
DC = docker-compose
DC_FILE = ./srcs/docker-compose.yml
DATA_DIR = /home/jihokim2/data

# Phony targets for make commands
.PHONY: all build up down clean fclean re ps init clean-data logs ps-extended exec-nginx exec-wordpress exec-mariadb

# Default target
all: init up

# Build docker images
build:
	@$(DC) -f $(DC_FILE) build --no-cache

# Start all containers
up: build
	@$(DC) -f $(DC_FILE) up -d

# Stop all containers
down:
	@$(DC) -f $(DC_FILE) down

# Stop containers and remove containers, networks, volumes, and images created by `up`
clean: down clean-data
	@$(DC) -f $(DC_FILE) down --rmi all --volumes --remove-orphans

# Full clean (like `clean` but more thorough)
fclean: clean
	docker volume prune -f
	docker network prune -f
	docker system prune -a -f

# Rebuild the project
re: fclean all

# List all running containers
ps:
	@$(DC) -f $(DC_FILE) ps

# Display logs for containers
logs:
	@$(DC) -f $(DC_FILE) logs

# List all containers (not just running)
ps-extended:
	@$(DC) -f $(DC_FILE) ps -a

# Initialize data directories
init:
	@mkdir -p $(DATA_DIR)/mariadb
	@mkdir -p $(DATA_DIR)/wordpress

# Clean data directories
clean-data:
	@sudo rm -rf $(DATA_DIR)/mariadb
	@sudo rm -rf $(DATA_DIR)/wordpress

# Execute an interactive shell on the nginx container
nx:
	@$(DC) -f $(DC_FILE) exec nginx sh

# Execute an interactive shell on the wordpress container
wp:
	@$(DC) -f $(DC_FILE) exec wordpress sh

# Execute an interactive shell on the mariadb container
db:
	@$(DC) -f $(DC_FILE) exec mariadb sh

# You can add more specific rules if needed
