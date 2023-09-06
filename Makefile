CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
LIBFT_SRCS = $(wildcard src/libft/*.c)
PRINTF_SRCS = $(wildcard src/printf2/src/*.c)
BASIC_SRCS = $(wildcard src/basic/*.c)
T_STACK_SRCS = $(wildcard src/t_stack/*.c)
LST_SRCS = $(wildcard src/lst/*.c)
ALGO_SRCS = $(wildcard src/algorithm/*.c)
OPT_SRCS = $(wildcard src/optimize/*.c)
ERR_SRCS = $(wildcard src/error_checking/*.c)

OBJDIR = obj
OBJLIBFT = $(LIBFT_SRCS:%.c=$(OBJDIR)/%.o)
OBJPRINTF = $(PRINTF_SRCS:%.c=$(OBJDIR)/%.o)
OBJBASIC = $(BASIC_SRCS:%.c=$(OBJDIR)/%.o)
OBJTSTACK = $(T_STACK_SRCS:%.c=$(OBJDIR)/%.o)
OBJLST = $(LST_SRCS:%.c=$(OBJDIR)/%.o)
OBJALGO = $(ALGO_SRCS:%.c=$(OBJDIR)/%.o)
OBJOPT = $(OPT_SRCS:%.c=$(OBJDIR)/%.o)
OBJERR = $(ERR_SRCS:%.c=$(OBJDIR)/%.o)


NEC_OBJS = $(OBJLIBFT) $(OBJPRINTF) $(OBJBASIC) $(OBJTSTACK) $(OBJLST) $(OBJALGO) $(OBJOPT) $(OBJERR)

all: $(NAME)

$(NAME): $(NEC_OBJS) main.o
	$(CC) $(CFLAGS) $(NEC_OBJS) main.o -o $(NAME)

bat: $(NEC_OBJS) basic_test_main.o
	$(CC) $(CFLAGS) $(NEC_OBJS) basic_test_main.o -o basic_test

$(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o: main.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CFLAGS) -c $< -o $@

$(OBJDIR)/basic_test_main.o: basic_test_main.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) main.o basic_test_main.o  $(NAME) basic_test

