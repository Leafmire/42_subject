/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:16:38 by gson              #+#    #+#             */
/*   Updated: 2022/08/04 17:11:14 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <unistd.h>
#include <sys/types.h>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n-----------------------------\n" << std::endl;

	// const Animal animal;

	// animal.makeSound();
	std::cout << getpid() << std::endl;
	while(1)
	{
		
	}
	return 0;
}