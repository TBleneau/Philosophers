##
## EPITECH PROJECT, 2018
## philosopher unit tests
## File description:
## unit test Makefile
##

CC 		=	gcc

RM		=	rm -rf

MKDIR		=	mkdir

TMPDIRNAME	=	tmp

MV		=	mv

RUN		=	tests_run

PROJECTPATH	=	../sources

TESTPATH	=	./

SRCS		=	$(PROJECTPATH)/create.c		\
			$(PROJECTPATH)/errno.c		\
			$(PROJECTPATH)/error.c		\
			$(PROJECTPATH)/philosopher.c	\
			$(PROJECTPATH)/options.c	\
			$(TESTPATH)tests_create.c	\
			$(TESTPATH)tests_errno.c	\
			$(TESTPATH)tests_error.c	\
			$(TESTPATH)tests_options.c	\

GCNO		=	$(SRCS:.c=.gcno)

GCDA		=	$(SRCS:.c=.gcda)

OBJS		=	$(SRCS:.c=.o)

CFLAGS		= 	-W -Wall -Wextra -coverage -DUNIT_TEST
CFLAGS		+= 	-I ../includes

LDFLAGS		=	-L../library/ -lriceferee
LDFLAGS		+=	-lcriterion -coverage
LDFLAGS		+=	-lpthread

NAME		=	tests

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
	$(MKDIR) $(TMPDIRNAME)
	$(MV) ../sources/*.o ./$(TMPDIRNAME)
	$(MV) ./*.o ./$(TMPDIRNAME)

$(RUN): all
	./$(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(GCDA)
	$(RM) $(GCNO)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TMPDIRNAME)

re: fclean all

.PHONY: all clean fclean tests_run re
