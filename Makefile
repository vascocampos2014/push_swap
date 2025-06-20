NAME = push_swap

CC = cc
CC_FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCBAZ = aux_core handle_error split add_numbers main s_movement r_movement p_movement target node_functions push_price init_nodes core handle_args
SRC = $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(SRCBAZ)))
SRC_DIR = src

OBJ_DIR = obj
OBJ = $(SRC: $(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_INCLU = -L $(LIBFT_DIR) -lft

INCLUDE = -I ./include

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.o
	$(CC) $(CC_FLAGS) -I$(LIBFT_PATH)$(SRC) -c $< -o $@ $(INCLUDE)

all: $(NAME)
	@echo "\033[32m[Program is ready for use]\033[0m"

$(NAME):$(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -o $(NAME) $(LIB_INCLU)
	@echo "\033[32m[push_swap created]\033[0m"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all -s
	@echo "\033[32m[Libft created]\033[0m"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)
		@echo "\033[33m[Cleaned up]\033[0m"

fclean:	clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(NAME)
		@echo "\033[33m[Fully cleaned up]\033[0m"

re:	fclean 
		make all

.PHONY:	all clean fclean re bonus libft