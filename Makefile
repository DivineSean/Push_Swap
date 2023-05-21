
NAME = push_swap
NAME_BONUS = checker
SRC =	push_swap.c push_swap_utils.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c push_swap_utils6.c push_swap_utils7.c push_swap_utils8.c push_swap_utils9.c push_swap_utils10.c push_swap_utils11.c
SRC_BONUS = bonus.c push_swap_utils.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c push_swap_utils6.c push_swap_utils7.c push_swap_utils8.c push_swap_utils9.c push_swap_utils10.c get_next_line.c get_next_line_utils.c push_swap_utils11.c bonus_utils.c bonus_utils1.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
R        := $(shell tput -Txterm setaf 1)
G        := $(shell tput -Txterm setaf 2)
Y       := $(shell tput -Txterm setaf 3)

all: $(NAME)
	@echo $(G) "ALL functions are done!"

all_bonus: $(NAME_BONUS)
	@echo $(G) "ALL functions are done!"

$(NAME): $(OBJS)
	@echo $(Y) Compiling: $< ... Done!
	@cc $(CFLAGS) $(OBJS) -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	@echo $(Y) Compiling: $< ... Done!
	@cc $(CFLAGS) $(OBJS) -o $@

%.o: %.c push_swap.h
	@echo $(Y) Compiling: $< ... Done!
	@cc $(CFLAGS) -c $<

bonus: ${OBJS_BONUS}
	@echo $(Y) Compiling: $< ... Done!
	@cc $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	@echo $(R) Cleaned
	@rm -f $(OBJS)

fclean: clean
	@echo $(R) Fully cleaned
	@rm -f $(NAME) $(NAME_BONUS) $(OBJS_BONUS)

re: fclean all

.PHONY: clean fclean re bonus all