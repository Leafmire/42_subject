/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:34:49 by gson              #+#    #+#             */
/*   Updated: 2022/08/04 20:39:42 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat alice("Alice", 2);
	Bureaucrat bruce("Bruce", 3);
	Form receipt("receipt", 2, 2);
	Form documents("documents", 2, 2);

	std::cout << "----------------------" << std::endl;
	
	alice.signForm(receipt);
	std::cout << receipt << std::endl;

	std::cout << "----------------------" << std::endl;

	bruce.signForm(documents);
	std::cout << documents << std::endl;

	std::cout << "----------------------" << std::endl;

	try
	{
		Form receipt2("receipt", 0, 0);
		std::cout << receipt2 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}