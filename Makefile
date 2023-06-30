NAME = pipex

LIBFT_DIR = libft

LIBFT =  $(LIBFT_DIR)/libft.a

OBJECTS_DIR = objs
	
SRCS = $(addprefix srcs/, pipex.c )

OBJS = $(patsubst srcs/%.c,$(OBJECTS_DIR)/%.o, $(SRCS))

CFLAGS = -Wall -Werror -Wextra -I inc/ 

all: make_libft $(NAME) 

$(NAME) : $(OBJS) inc/pipex.h 
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

objs/%.o : srcs/%.c | $(OBJECTS_DIR)
	gcc -c $(CFLAGS) $< -o $@

$(OBJECTS_DIR) :
	mkdir -p $(OBJECTS_DIR)

make_libft:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf objs
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean all bonus clean fclean re