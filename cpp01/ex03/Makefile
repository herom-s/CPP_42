# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 17:54:18 by hermarti          #+#    #+#              #
#    Updated: 2026/02/25 11:47:09 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = attack

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = HumanA.cpp \
	   HumanB.cpp \
	   Weapon.cpp \
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
