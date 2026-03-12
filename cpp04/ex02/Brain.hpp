/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:13:34 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/10 17:34:23 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void	setIdeas(const std::string ideas[100]);
	const std::string	(&getIdeas(void) const)[100];

	void	setIdea(const unsigned int i, const std::string &idea);
	const std::string	&getIdea(const unsigned int i) const;

private:
	std::string	ideas[100];
};
#endif
