NAME = webserv
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = srcs/main.cpp \
	   srcs/Config/Config.cpp \
	   srcs/Server/Cluster.cpp
OBJS = $(SRCS:.cpp=.o)
# INCS = Bureaucrat.hpp
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean