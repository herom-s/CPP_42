# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/08 11:51:16 by hermarti          #+#    #+#              #
#    Updated: 2026/03/12 15:58:33 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interface

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = AMateria.cpp\
	   Cure.cpp \
	   Ice.cpp \
	   ICharacter.cpp \
	   Character.cpp \
	   IMateriaSource.cpp \
	   MateriaSource.cpp \
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
