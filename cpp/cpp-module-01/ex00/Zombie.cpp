/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:31:32 by gson              #+#    #+#             */
/*   Updated: 2022/07/17 03:54:06 by gson             ###   ########.fr       */
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

void Zombie::announce(void)
{
	std::cout << "<" << name << ">" << " BraiiiiiiinnnzzzZ..." << "\n";
}