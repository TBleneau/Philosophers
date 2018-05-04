##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Created by Thomas BLENEAU
##

CC		= gcc

RM		= rm -f

SRCS		= sources/create.c	\
		sources/errno.c		\
		sources/error.c		\
		sources/main.c		\
		sources/philosopher.c	\
		sources/options.c	\

CFLAGS		= -I includes/
CFLAGS		+= -W -Wall -Wextra -std=gnu99

LDFLAGS		= -L./library/ -lriceferee
LDFLAGS		+= -lpthread

NAME		= philo

GCNO		= $(SRCS:.c=.gcno)

GCDA		= $(SRCS:.c=.gcda)

OBJS		= $(SRCS:.c=.o)

CLEAN		= clean

FCLEAN		= fclean

RUN		= tests_run

$(NAME)		: $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

all		: $(NAME)

$(RUN)		: all
		make $(RUN) -C ./tests/

$(CLEAN)	:
		$(RM) $(OBJS)
		$(RM) $(GCDA)
		$(RM) $(GCNO)
		make $(CLEAN) -C ./tests/

$(FCLEAN)	: $(CLEAN)
		$(RM) $(NAME)
		make $(FCLEAN) -C ./tests/

re		: $(FCLEAN) all

.PHONY : all $(CLEAN) $(FCLEAN) $(RUN) re
