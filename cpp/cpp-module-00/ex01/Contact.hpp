/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:32:44 by gson              #+#    #+#             */
/*   Updated: 2022/07/13 02:32:13 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phone_number;
		std::string secret;
public:
    Contact(void);
    ~Contact(void);
    void set_firstname(std::string str);
    void set_lastname(std::string str);
    void set_nickname(std::string str);
    void set_phone_number(std::string str);
    void set_secret(std::string str);

    std::string get_firstname(void);
    std::string get_lastname(void);
    std::string get_nickname(void);
    std::string get_phone_number(void);
    std::string get_secret(void);
};

#endif