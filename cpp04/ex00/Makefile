# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/08 11:51:16 by hermarti          #+#    #+#              #
#    Updated: 2026/03/10 17:07:27 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = poly

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Animal.cpp\
	   Dog.cpp \
	   Cat.cpp \
	   WrongAnimal.cpp \
	   WrongCat.cpp \
	   WrongDog.cpp \
	   main.cpp

OBJS = $(SRCS:%.cpp=%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
