/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:02:15 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/06 13:02:16 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);
	~BitcoinExchange();

	void	addExchange(const std::string &dateStr, float val);
	void	readData(const std::string &data_file);
	float	findDate(const std::string &date_str);
	void	readFile(const std::string &file_name);

private:
	std::map<std::string, float> _exchange;

	void	processDataLine(const std::string &line);
	void	processInputLine(const std::string &line);
};

#endif
