#program name
NAME=philo

#bonus program name
NAME_B=philo_bonus

#cc compiler with all flags
CCF=cc -Wall -Wextra -Werror

#mandatory
SRC=$(shell find "./source" -type f )
OBJ=$(SRC:.c=.o)

#bonus
SRC_B=$(shell find "./source_bonus" -type f )
OBJ_B=$(SRC_B:.c=.o)

#include header
INC= -I includes

#debuging
ifeq ($(DEBUG), YES)
   GDB = -g
endif

.PHONY: all clean fclean re clear bonus

all: $(NAME)


$(NAME): $(OBJ)
		@$(CCF) $(INC) $^ -o $@
		@echo "compiling"
		@sleep 0.5
		@echo "$(NAME) is ready"


bonus: $(OBJ_B)
		@$(CCF) $(INC) $^ -o $(NAME_B)
		@echo "compiling"
		@sleep 0.5
		@echo "$(NAME_B) is ready"


%.o: %.c
		@$(CCF) $(GDB) $(INC) -c $< -o $@ 


clean:
		@rm -f $(OBJ) $(OBJ_B)
		@echo "cleaning..."


fclean: clean
		@rm -f $(NAME) $(NAME_B)
		@echo "cleaning program..."


re: fclean all


clear: all clean

bclear: all bonus clean

norm :
		@norminette $(SRC) $(SRC_B) includes/
