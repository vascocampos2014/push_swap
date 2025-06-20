# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 11:44:19 by vaires-m          #+#    #+#              #
#    Updated: 2024/10/22 12:29:45 by vaires-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libft.a

SOURCES_DIR = ./src
SOURCES = ft_atoi.c ft_bzero.c ft_strlen.c ft_calloc.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_split.c ft_strchr.c ft_strdup.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_isalnum.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c 

GNL_DIR = get_next_line
GNL_SOURCES = get_next_line.c get_next_line_utils.c get_next_line_utils_bonus.c get_next_line_bonus.c

PRINTF_DIR = ft_printf
PRINTF_SOURCES = ft_basic.c ft_printf.c ft_printhex.c ft_ptr.c

SRC = 	$(addprefix $(GNL_DIR)/, $(GNL_SOURCES)) \
		$(addprefix $(PRINTF_DIR)/, $(PRINTF_SOURCES)) \
		$(addprefix $(SOURCES_DIR)/,(SOURCES))

OBJ_DIR = ./obj
OBJS =	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o)) \
		$(addprefix $(OBJ_DIR)/, $(PRINTF_SOURCES:.c=.o)) \
		$(addprefix $(OBJ_DIR)/, $(GNL_SOURCES:.c=.o))

RESET = \033[0m
GREEN = \033[0;32m
CC = cc
FLAGS = -Wall -Wextra -Werror -fPIC -I$(INC_DIR)
AR = ar
INC_DIR = include

# Default target
all: $(NAME)

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build the library
$(NAME): $(OBJS) | $(OBJ_DIR)
	@echo "$(GREEN)Creating $(NAME)...$(RESET)"
	@$(AR) rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Succefuly created $(NAME) $(RESET)"

# Compile object files into the obj directory
$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling libft...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Finished libft$(RESET)"

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling get_next_line...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Finished get_next_line$(RESET)"

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling ft_printf...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Finished ft_printf$(RESET)"

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re