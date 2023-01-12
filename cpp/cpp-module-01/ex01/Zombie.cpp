/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:31:32 by gson              #+#    #+#             */
/*   Updated: 2022/07/18 19:36:58 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{

}

Zombie::~Zombie(void)
{
	std::cout << name << " is disappear..." << "\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << "<" << name << ">" << " BraiiiiiiinnnzzzZ..." << "\n";
}