# SRCS	=  ft_calc_len.c  ft_libft.c   ft_printf.c    \
# 			ft_put_base.c ft_putptr.c  ft_type1.c ft_type2.c ft_memset.c minitalk_server_utils.c minitalk_client_utils.c 

# OBJS	= ${SRCS:.c=.o}


# NAME	= libftprintf.a

# CC		= cc

# RM		= rm -f

# CFLAGS	= -Wall -Wextra -Werror

# .c.o:
# 			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# %.o: %.c
# 	$(CC) -c $(CFLAGS) -g $< -o $@

# ${NAME}: ${OBJS}
# 		ar -rcs ${NAME} ${OBJS}	 

# # $(NAME): $(OBJS)
# # 		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

# all:		${NAME}

# clean:
# # @$(MAKE) 
# 	${RM} $(OBJS)

# fclean: clean
# # @$(MAKE)
# 	${RM} $(NAME) $(OBJS)

# re:			fclean all

# 			ar -rcs ${NAME}  ${OBJS}

# .PHONY:		all clean fclean re 


# Source files
SRCS = ft_calc_len.c ft_libft.c ft_printf.c \
       ft_put_base.c ft_putptr.c ft_type1.c ft_type2.c \
       ft_memset.c minitalk_server_utils.c minitalk_client_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Library name
NAME = libftprintf.a

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Remove files command
RM = rm -f

# Default target
all: $(NAME)

# Rule to create object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the library from object files
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

# Clean object files
clean:
	$(RM) $(OBJS)

# Clean object files and the library
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
