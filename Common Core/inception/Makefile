NAME            :=  inception
VERSION         :=  1.0

# -----------------------------------------------------------------------------
# COMPILATION
# -----------------------------------------------------------------------------
SRCS_DIR        :=  srcs

COMPOSE_FILE    :=  ${SRCS_DIR}/docker-compose.yml
ENV_FILE        :=  ${SRCS_DIR}/.env

FLAGS           :=  -f ${COMPOSE_FILE} \
					-p ${NAME}

# -----------------------------------------------------------------------------
# COLORS
# -----------------------------------------------------------------------------
__RED           :=	"\033[1;31m"
__GREEN			:=	"\033[1;32m"
__YELLOW        :=	"\033[1;33m"
__BLUE          :=	"\033[1;36m"
__WHITE         :=	"\033[1;37m"
__EOC           :=	"\033[0;0m"
# -----------------------------------------------------------------------------
# RULES
# -----------------------------------------------------------------------------
all: build

build:
	@mkdir -p ~/data/database
	@mkdir -p ~/data/www
	@docker-compose ${FLAGS} up -d --build
	@echo ${__GREEN}"ready"${__WHITE}" - docker services are up"${__EOC}

start:
	@docker-compose ${FLAGS} start > /dev/null
	@echo ${__GREEN}"ready"${__WHITE}" - docker services have been started"${__EOC}

stop:
	@docker-compose ${FLAGS} stop > /dev/null
	@echo ${__RED}"stopped"${__WHITE}" - docker services have been stopped"${__EOC}

status:
	@docker-compose ${FLAGS} ps

clean: stop
	@docker system prune -af
	@sudo rm -rf ~/data/www/* > /dev/null
	@sudo rm -rf ~/data/database/* > /dev/null
	@echo ${__BLUE}"info"${__WHITE}" - cleaned docker data"${__EOC}

fclean: clean
	@docker volume prune -f
	@sudo rm -rf home/nbled/data/database
	@echo ${__BLUE}"info"${__WHITE}" - full cleaned docker data"${__EOC}

re: stop fclean all

.PHONY: all start stop status fclean clean re
