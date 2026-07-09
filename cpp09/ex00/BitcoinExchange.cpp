/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:02:23 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/06 21:03:35 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _exchange(other._exchange) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		this->_exchange = other._exchange;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool	parseDate(const std::string &str, std::tm &date) {
    if (str.size() != 10 || str[4] != '-' || str[7] != '-')
        return false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    int year  = std::atoi(str.substr(0, 4).c_str());
    int month = std::atoi(str.substr(5, 2).c_str());
    int day   = std::atoi(str.substr(8, 2).c_str());

    date.tm_year = year - 1900;
    date.tm_mon  = month - 1;
    date.tm_mday = day;
    return true;
}

static bool	isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool	isValidDate(const std::tm &date) {
    int year  = date.tm_year + 1900;
    int month = date.tm_mon + 1;
	int day   = date.tm_mday;

    if (month < 1 || month > 12)
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1])
        return false;
    return true;
}

void	BitcoinExchange::addExchange(const std::string &date_str, float val) {
    std::tm date = {};
    if (!parseDate(date_str, date) || !isValidDate(date))
        throw std::runtime_error("Error: bad input => " + date_str);
    this->_exchange[date_str] = val;
}

void	BitcoinExchange::processDataLine(const std::string &line) {
	size_t pos = line.find(',');
    if (pos == std::string::npos) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    std::string date_str = line.substr(0, pos);
	date_str.erase(remove_if(date_str.begin(), date_str.end(), ::isspace), date_str.end());
    std::string val_str  = line.substr(pos + 1);
	val_str.erase(remove_if(val_str.begin(), val_str.end(), ::isspace), val_str.end());

	float val;
	std::istringstream iss(val_str);
	if (!(iss >> val)) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	try {
		addExchange(date_str, val);
	} catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


void	BitcoinExchange::processInputLine(const std::string &line) {
    size_t pos = line.find('|');
    if (pos == std::string::npos) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    std::string date_str = line.substr(0, pos);
	date_str.erase(remove_if(date_str.begin(), date_str.end(), ::isspace), date_str.end());
    std::string val_str = line.substr(pos + 1);
	val_str.erase(remove_if(val_str.begin(), val_str.end(), ::isspace), val_str.end());
    std::tm date = {};
    if (!parseDate(date_str, date) || !isValidDate(date)) {
        std::cerr << "Error: bad input => " << date_str << std::endl;
        return;
    }

    float val;
    std::istringstream iss(val_str);
    if (!(iss >> val)) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    if (val < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if (val > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }

	float rate;
	try {
		rate = findDate(date_str);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return;
	}
	std::cout << date_str << " => " << val << " = " << (val * rate) << std::endl;
}

void	BitcoinExchange::readData(const std::string &data_file) {
    std::ifstream file(data_file.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data.csv.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
        processDataLine(line);
}

float	BitcoinExchange::findDate(const std::string &date_str) {
    if (_exchange.empty())
        throw std::runtime_error("Error: no exchange rate data available.");

    std::map<std::string, float>::iterator it = _exchange.lower_bound(date_str);

    if (it != _exchange.end() && it->first == date_str)
        return it->second;
    if (it == _exchange.begin())
        throw std::runtime_error("Error: no earlier date available.");
    --it;
    return it->second;
}

void	BitcoinExchange::readFile(const std::string &file_name) {
    std::ifstream file(file_name.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line);
	while (std::getline(file, line))
        processInputLine(line);
}
