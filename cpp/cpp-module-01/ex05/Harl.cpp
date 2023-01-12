/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 03:12:10 by gson              #+#    #+#             */
/*   Updated: 2022/07/19 03:44:37 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	complains[0].level = "DEBUG";
	complains[1].level = "INFO";
	complains[2].level = "WARNING";
	complains[3].level = "ERROR";

	complains[0].func = &Harl::debug;
	complains[1].func = &Harl::info;
	complains[2].func = &Harl::warning;
	complains[3].func = &Harl::error;
}

Harl::~Harl(void)
{
}

void Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (complains[i].level == level)
		{
			(this->*complains[i].func)();
			return ;
		}
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << "\n";
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << "\n";
	std::cout << "I just love it!" << "\n\n";
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << "\n";
	std::cout << "I cannot believe adding extra bacon cost more money." << "\n";
	std::cout << "You don't put enough! If you did I would not have to ask for it!" << "\n\n";	
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << "\n";
	std::cout << "I think I deserve to have some extra bacon for free." << "\n";
	std::cout << "I've been coming here for years and you just started working here last month." << "\n\n";
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << "\n";
	std::cout << "This is unacceptable, I want to speak to the manager now." << "\n\n";
}