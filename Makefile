NAME = webserv
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = srcs/main.cpp \
	   srcs/Config/Config.cpp \
	   srcs/Config/ConfigFileReader.cpp \
	   srcs/Config/ConfigParser.cpp \
	   srcs/Config/ConfigServer.cpp \
	   srcs/Server/Cluster.cpp \
	   srcs/Server/Server.cpp \
	   srcs/Utils/Strhelper.cpp
OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean