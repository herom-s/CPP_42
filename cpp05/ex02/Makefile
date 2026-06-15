# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/08 11:51:16 by hermarti          #+#    #+#              #
#    Updated: 2026/06/15 11:38:28 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = aform

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Bureaucrat.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp \
	   AForm.cpp \
	   main.cpp

OBJS = $(SRCS:%.cpp=%.o)

RM = rm -f

DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g3
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
