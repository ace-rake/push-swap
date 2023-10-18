CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
BONUS_NAME := checker

PRINTF_SRCS = $(wildcard src/printf2/src/*.c)
GNL_SRCS = $(wildcard src_bonus/gnl/*.c)
BASIC_SRCS = $(wildcard src/basic/*.c)
T_STACK_SRCS = $(wildcard src/t_stack/*.c)
LST_SRCS = $(wildcard src/lst/*.c)
ALGO_SRCS = $(wildcard src/algorithm/*.c)
OPT_SRCS = $(wildcard src/optimize/*.c)
ERR_SRCS = $(wildcard src/error_checking/*.c)
BONUS_SRCS = $(wildcard src_bonus/*.c)


OBJDIR = obj
OBJPRINTF = $(PRINTF_SRCS:%.c=$(OBJDIR)/%.o)
OBJBASIC = $(BASIC_SRCS:%.c=$(OBJDIR)/%.o)
OBJTSTACK = $(T_STACK_SRCS:%.c=$(OBJDIR)/%.o)
OBJLST = $(LST_SRCS:%.c=$(OBJDIR)/%.o)
OBJALGO = $(ALGO_SRCS:%.c=$(OBJDIR)/%.o)
OBJOPT = $(OPT_SRCS:%.c=$(OBJDIR)/%.o)
OBJERR = $(ERR_SRCS:%.c=$(OBJDIR)/%.o)
OBJBONUS = $(BONUS_SRCS:%.c=$(OBJDIR)/%.o)
OBJGNL = $(GNL_SRCS:%.c=$(OBJDIR)/%.o)


NEC_OBJS =  $(OBJPRINTF) $(OBJBASIC) $(OBJTSTACK) $(OBJLST) $(OBJALGO) $(OBJOPT) $(OBJERR)

all: $(NAME)

$(NAME): $(NEC_OBJS) main.o
	make -C src/libft
	$(CC) $(CFLAGS) $(NEC_OBJS) main.o -Lsrc/libft -lft -o $(NAME)
	echo "compiled $@"

bonus: $(NEC_OBJS) $(OBJBONUS) $(OBJGNL)
	make -C src/libft
	$(CC) $(CFLAGS) $(NEC_OBJS) $(OBJBONUS) $(OBJGNL) -Lsrc/libft -lft -o $(BONUS_NAME)
	echo "compiled $@"

$(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	echo "compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o: main.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) main.o basic_test_main.o basic_test

fclean: clean
	make fclean -C src/libft
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: 
	make fclean
	make all
.SILENT:
.PHONY: all clean fclean re
