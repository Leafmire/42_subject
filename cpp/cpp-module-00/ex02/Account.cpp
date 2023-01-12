/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:26:51 by gson              #+#    #+#             */
/*   Updated: 2022/07/19 16:57:16 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>
#include <time.h>

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

void	Account::_displayTimestamp( void )
{
	time_t	timestamp;
	char	time_str[16];

	time(&timestamp);
	strftime(time_str, 16, "%Y%m%d_%H%M%S", localtime(&timestamp));
	std::cout << "[" << time_str << "]";
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << "\n";
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << "\n";
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount - deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal == true)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:" << "refused" << "\n";
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << " index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount + withdrawal;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << "\n";
		return (true);
	}
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << "\n";
}