# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 00:04:31 by kfaustin          #+#    #+#              #
#    Updated: 2023/02/15 22:18:33 by kfaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable file
BINARY	= push_swap

# Push_swap library
PSLIB	= push_swap.a

# My ft_printf
PDIR	= ./includes/ft_printf/
PLIB	= libftprintf.a

# Compiler and shell scripts
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

# Source files
SRCDIR	= ./src/
SRC		= check_args.c ft_split.c list_utils.c moves.c multiples_argv.c push_swap.c \
			pushswap3.c pushswap5.c pushswap100.c pushswap500.c single_argv.c \
			sort_stack.c sort_stack2.c str_to_number.c utils.c

# Object files
#OBJ		= $(SRCDIR)$(SRC:.c=.o)
OBJ		= $(addprefix $(SRCDIR), $(SRC:.c=.o))

# Target and rules

all: $(PSLIB) $(PLIB)
		$(CC) $(CFLAGS) $(PSLIB) $(PLIB) -o $(BINARY)
#		make clean

$(PLIB):
		make -C $(PDIR)
		cp $(PDIR)$(PLIB) .

$(PSLIB): $(OBJ)
		$(AR) $(PSLIB) $(OBJ)

#%.o:%.c
#		$(CC) $(CFLAGS) -c -o $@ $^

clean:
#		make -C $(PDIR) clean
		$(RM) $(OBJ)
		$(RM) $(PSLIB) $(PLIB)

fclean: clean
		make -C $(PDIR) fclean
		$(RM) $(BINARY)

re: fclean all
