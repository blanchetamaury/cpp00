CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

NAME = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) -c $(SRC) $(FLAGS)
	$(CPP) -o $(NAME) $^ $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re