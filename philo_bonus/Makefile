#program name
NAME = philo_bonus

#cc compiler with all flags
CCF = cc -Wall -Wextra -Werror

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[33;1m
RESET := \033[0m
CLEAR := \033[K
RETURN := \r
BOLD_PURPLE := \033[35;1m
BOLD_UNDER_GREEN := \033[32;1;4m
BOLD_GREEN := \033[32;1m

# Directories
SRC_DIR := source
OBJ_DIR := objects

# Source and Object Files
SRC := ./source/threads+procs/philo_life.c ./source/clear+exit/puterr_msg.c ./source/clear+exit/destroy.c \
	./source/clear+exit/exit_v2.c ./source/philo_bonus.c ./source/external/ft_isdigit.c ./source/external/ft_memcpy.c \
	./source/external/ft_calloc.c ./source/external/ft_strlen.c ./source/external/ft_atoi.c ./source/external/ft_strdup.c \
	./source/external/puterr.c ./source/external/ft_strlcpy.c ./source/external/ft_bzero.c ./source/external/ft_strjoin.c \
	./source/utils/printt.c ./source/utils/time.c ./source/utils/philo_utils.c ./source/utils/philo_utils_R1.c \
	./source/getting_started/starter.c



OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

#include header
INC := -I./includes

#debuging
ifeq ($(DEBUG), GDB)
	CCF += -g
else ifeq ($(DEBUG), THREAD)
	CCF += -g3 -fsanitize=thread
else ifeq ($(DEBUG), ALL)
	CCF += -g3 -fsanitize=address
endif

.PHONY: all clean fclean re clear

all: $(NAME)


$(NAME): $(OBJ)
		@$(CCF) $(OBJ) $(INC) -o $@
		@sleep 0.5
		@echo  "\n$(GREEN)$(NAME) is ready$(RESET)"


$(OBJ_DIR)/%.o: $(SRC)
		@mkdir -p $(OBJ_DIR)
		@echo -n "$(RETURN)$(YELLOW)Compiling:  $(notdir $(filter %/$*.c, $(SRC)))....$(CLEAR)$(RESET)"
		@$(CCF) $(GDB) $(INC) -c $(filter %/$*.c, $(SRC)) -o $@
		@sleep 0.062

clean:
		@rm -rf $(OBJ_DIR)
		@echo  "$(GREEN)cleaning...$(RESET)"
		@sleep 0.2


fclean: clean
		@rm -f $(NAME)
		@echo "$(GREEN)cleaning up program...$(RESET)"
		@sleep 0.19


re: fclean all

clear: re clean

bclear: all clean

norm :
		@norminette $(SRC) includes/

