/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:07:25 by gson              #+#    #+#             */
/*   Updated: 2022/07/13 03:44:11 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

std::string	ellipsis_str(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	return (str);
}

int	make_ui(Contact contacts[8])
{
	char		index_char;
	int			index_int;
	int			i;
	std::string	str;

	index_char = '1';
	i = 0;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (index_char <= '8')
	{
		index_int = index_char - 1 - '0';
		if (contacts[index_int].get_firstname().size())
		{
			str = index_char;
			str = ellipsis_str(str);
			std::cout << "|" << std::setw(10) << str;
			str = ellipsis_str(contacts[index_int].get_firstname());
			std::cout << "|" << std::setw(10) << str;
			str = ellipsis_str(contacts[index_int].get_lastname());
			std::cout << "|" << std::setw(10) << str;
			str = ellipsis_str(contacts[index_int].get_nickname());
			std::cout << "|" << std::setw(10) << str;
			std::cout << "|" << "\n";
			i++;
		}
		index_char++;
	}
	std::cout << "+-------------------------------------------+" << "\n";
	return (i);
}

int main(void)
{
	Phonebook	pb;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "Waiting for command... > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pb.add_contact();
		else if (str == "SEARCH")
			pb.search_contact();
		if (std::cin.eof())
		{
			std::cout << "\n";
			return (0);
		}
	}
	return (0);
}