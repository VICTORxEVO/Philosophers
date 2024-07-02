
#bonus program name
NAME_B=philo_bonus

#cc compiler with all flags
CCF=cc -Wall -Wextra -Werror

#bonus
SRC_B=$(shell find "./source" -type f )
OBJ_B=$(SRC_B:.c=.o)

#include header
INC= -I includes

#debuging
ifeq ($(DEBUG), YES)
   GDB = -g
endif

.PHONY: clean fclean re clear bonus

bonus: $(NAME_B)


$(NAME_B): $(OBJ_B)
		@$(CCF) $(INC) $^ -o $@
		@echo "compiling"
		@sleep 0.5
		@echo "$(NAME_B) is ready"


%.o: %.c
		@$(CCF) $(GDB) $(INC) -c $< -o $@ 


clean:
		@rm -f $(OBJ_B)
		@echo "cleaning..."


fclean: clean
		@rm -f $(NAME_B)
		@echo "cleaning program..."


re: fclean all


clear: clean

bclear: bonus clean

norm :
		@norminette $(SRC_B) includes/
