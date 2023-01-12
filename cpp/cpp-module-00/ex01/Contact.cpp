/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:49:11 by gson              #+#    #+#             */
/*   Updated: 2022/07/13 02:21:09 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

/* setter */

void Contact::set_firstname(std::string str)
{
	this->firstname = str;
}

void Contact::set_lastname(std::string str)
{
	this->lastname = str;
}

void Contact::set_nickname(std::string str)
{
	this->nickname = str;
}

void Contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}

void Contact::set_secret(std::string str)
{
	this->secret = str;	
}

/* getter */

std::string Contact::get_firstname(void)
{
	return (this->firstname);
}

std::string Contact::get_lastname(void)
{
	return (this->lastname);
}

std::string Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string Contact::get_secret(void)
{
	return (this->secret);	
}
