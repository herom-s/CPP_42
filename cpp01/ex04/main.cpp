/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:16:23 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/26 17:28:03 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void	replace_string(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream	in(filename.c_str());
	std::ofstream	out((filename + ".replace").c_str());
	std::size_t		found;
	std::string		line;

	while (std::getline(in, line))
	{
		found = line.find(s1);
		if (found != std::string::npos)
		{
			line.erase(found, s1.length());
			line.insert(found, s2);
		}
		out << line << std::endl;
	}
	in.close();
	out.close();
}

int main (int argc, char *argv[])
{
	std::string	filename;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
	{
		std::cout << "notsed: <filename> <str_to_find> <str_to_sub>" << std::endl;
		return (0);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	replace_string(filename, s1, s2);
	return 0;
}
