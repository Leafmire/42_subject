/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:15:36 by gson              #+#    #+#             */
/*   Updated: 2022/08/06 17:30:05 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <ios>

int checkArgs(int argc)
{
	if (argc > 2)
	{
		std::cerr << "Too many arguments." << std::endl;
		return (1);
	}
	if (argc < 2)
	{
		std::cerr << "No argument." << std::endl;
		return (1);
	}

	return (0);
}

int main(int argc, char** argv)
{
	Convert converts;
	
	if (checkArgs(argc))
	{
		return (1);
	}

	converts.convertType(argv[1]);

	converts.printChar();
	converts.printInt();
	converts.printFloat();
	converts.printDouble();

	return (0);
}