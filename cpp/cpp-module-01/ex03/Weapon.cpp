/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:09:18 by gson              #+#    #+#             */
/*   Updated: 2022/07/18 21:29:21 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{

}

Weapon::~Weapon(void)
{
	
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType(void)
{
	return (this->type);
}