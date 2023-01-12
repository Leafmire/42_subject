/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:49:16 by gson              #+#    #+#             */
/*   Updated: 2022/07/19 16:52:48 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iomanip>
#include "Contact.hpp"

class Phonebook {
	private:
		Contact	contacts[8];
		int		index;
	public:
		Phonebook(void);
		~Phonebook(void);
		void	add_contact(void);
		void	search_contact(void);
		void	show_contact(Contact contact);
		Contact get_contact(int index);
};

std::string	ellipsis_str(std::string str);
int	make_ui(Contact contacts[8]);

#endif