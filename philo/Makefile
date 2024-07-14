#program name
NAME=philo

#cc compiler with all flags
CCF=cc -Wall -Wextra -Werror -fsanitize=thread

#mandatory
SRC=$(shell find "./source" -type f )
OBJ=$(SRC:.c=.o)

#include header
INC= -I includes

#debuging
ifeq ($(DEBUG), YES)
   GDB = -g
endif

.PHONY: all clean fclean re clear

all: $(NAME)


$(NAME): $(OBJ)
		@$(CCF) $(INC) $^ -o $@
		@echo "compiling"
		@sleep 0.5
		@echo "$(NAME) is ready"


%.o: %.c
		@$(CCF) $(GDB) $(INC) -c $< -o $@ 


clean:
		@rm -f $(OBJ)
		@echo "cleaning..."


fclean: clean
		@rm -f $(NAME)
		@echo "cleaning program..."


re: fclean all

clear: all clean

bclear: all clean

norm :
		@norminette $(SRC) includes/
