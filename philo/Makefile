#program name
NAME = philo

#cc compiler with all flags
CCF = cc -Wall -Wextra -Werror

#some colors
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
SRC:= ./source/clear+exit/puterr_msg.c ./source/clear+exit/destroy.c ./source/clear+exit/exit_v2.c \
	./source/external/ft_isdigit.c ./source/external/ft_memcpy.c ./source/external/ft_calloc.c  \
	./source/external/ft_strlen.c ./source/external/ft_atoi.c ./source/external/ft_strdup.c \
	./source/external/puterr.c ./source/external/ft_strlcpy.c ./source/external/ft_bzero.c ./source/external/ft_strjoin.c \
	./source/init/parser.c ./source/init/ccu_init.c \
	./source/threads_monitor/monitor_join.c ./source/threads_monitor/thread_func.c  \
	./source/utils/printt.c ./source/utils/parent_utils.c ./source/utils/time.c ./source/utils/thread_utils_R1.c \
	./source/utils/thread_utils.c ./source/philo.c
	   
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))


#include header
INC= -I./includes

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
		@echo "compiling"
		@sleep 0.5
		@echo "$(NAME) is ready"

$(OBJ_DIR)/%.o: $(SRC)
		@mkdir -p $(OBJ_DIR)
		@echo -n "$(RETURN)$(YELLOW)Compiling:  $(notdir $(filter %/$*.c, $(SRC)))....$(CLEAR)$(RESET)"
		@$(CCF) $(GDB) $(INC) -c $(filter %/$*.c, $(SRC)) -o $@
		@sleep 0.062


clean:
		@rm -rf $(OBJ_DIR)
		@echo "cleaning..."


fclean: clean
		@rm -f $(NAME)
		@echo "cleaning program..."


re: fclean all

clear: re clean

bclear: all clean

norm :
		@norminette $(SRC) includes/

show:
	@echo $(SRC)
