# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 17:45:43 by frromero          #+#    #+#              #
#    Updated: 2025/12/21 19:12:25 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = array
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCLUDES = -I .

SRC =	main.cpp
		
OBJ = $(SRC:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(NAME) created."

clean:
	@rm -f $(OBJ)
	@echo "Object files deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted."

re: fclean all

.PHONY: all clean fclean re