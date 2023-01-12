/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:49:13 by gson              #+#    #+#             */
/*   Updated: 2022/07/19 16:52:35 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->index = 0;
}

Phonebook::~Phonebook(void)
{
}

void Phonebook::add_contact(void)
{
	std::string str;

	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Firstname: ";
		std::getline(std::cin, str);
		if (str != "")
			this->contacts[this->index % 8].set_firstname(str);
	}
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Lastname: ";
		std::getline(std::cin, str);
		if (str != "")
			this->contacts[this->index % 8].set_lastname(str);
	}
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, str);
		if (str != "")
			this->contacts[this->index % 8].set_nickname(str);
	}
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, str);
		if (str != "")
			this->contacts[this->index % 8].set_phone_number(str);
	}
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, str);
		if (str != "")
			this->contacts[this->index % 8].set_secret(str);
	}
	this->index++;
}

void Phonebook::show_contact(Contact contact)
{
	std::cout << "Firstname: " << contact.get_firstname() << "\n";
	std::cout << "Lastname: " << contact.get_lastname() << "\n";
	std::cout << "Nickname: " << contact.get_nickname() << "\n";
	std::cout << "Phone number: " << contact.get_phone_number() << "\n";
	std::cout << "Secret: " << contact.get_secret() << "\n";
}

void Phonebook::search_contact(void)
{
	std::string	str;
	int	index;
	int i;

	index = 0;
	i = make_ui(this->contacts);
	while (!std::cin.eof())
	{
		if (i == 0)
			break;
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			index = str[0] - 1 - '0';
			if (str[0] >= '1' && str[0] <= '8' && this->contacts[index].get_firstname().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index" << "\n";
	}
	if (i && !std::cin.eof())
		this->show_contact(this->contacts[index]);
	else if (!std::cin.eof())
		std::cout << "\n" << "Now empty" << "\n";
}