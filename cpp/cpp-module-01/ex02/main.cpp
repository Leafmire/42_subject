/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:43:38 by gson              #+#    #+#             */
/*   Updated: 2022/07/28 18:57:31 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string string;
	std::string *stringPTR;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string 주소   : " << &string << "\n";
	std::cout << "stringPTR 주소: " << stringPTR << "\n";
	std::cout << "stringREF 주소: " << &stringREF << "\n\n";

	std::cout << "stringPTR 문자열: " << *stringPTR << "\n";
	std::cout << "stringREF 문자열: " << stringREF << "\n";
}