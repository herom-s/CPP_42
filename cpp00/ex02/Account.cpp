/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 09:46:27 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/24 10:51:34 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <cstddef>
#include <iostream>
#include <ctime>
#include <ostream>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
: _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_amount += initial_deposit;
	this->_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";"
				<< "amount:" << this->_amount
				<< ";"
				<< "created"
				<< std::endl;
}

Account::Account(void)
: _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";"
				<< "amount:" << this->_amount
				<< ";"
				<< "created"
				<< std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";"
				<< "amount:" << this->_amount
				<< ";"
				<< "closed"
				<< std::endl;
	_nbAccounts--;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";"
				<< "p_amount:" << this->_amount
				<< ";"
				<< "deposit:" << deposit
				<< ";";
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout	<< "amount:" << this->_amount
				<< ";"
				<< "nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";"
				<< "p_amount:" << this->_amount
				<< ";"
				<< "withdrawal:";
	if (this->_amount - withdrawal > 0)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout	<< withdrawal
					<< ";"
					<< "amount:" << this->_amount
					<< ";"
					<< "nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		return (true);
	}
	else
	{
		std::cout	<< "refused"
					<< std::endl;
		return (false);
	}
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";"
				<< "amount:" << this->_amount
				<< ";"
				<< "deposits:" << this->_nbDeposits
				<< ";"
				<< "withdrawals:" << this->_nbWithdrawals
				<< std::endl;

}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts
				<< ";"
				<< "total:" << _totalAmount
				<< ";"
				<< "deposits:" << _totalNbDeposits
				<< ";"
				<< "withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm		*local_time = std::localtime(&now);
	char		buffer[80];

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local_time);
	std::cout << buffer;
}
