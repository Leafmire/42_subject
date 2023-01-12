/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:16:38 by gson              #+#    #+#             */
/*   Updated: 2022/08/04 16:20:19 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n-----------------------------\n" << std::endl;

	const Animal *animals[10];

	for (size_t i = 0 ; i < 5; i++) 
	{
		animals[i] = new Dog();
	}
	for (size_t i = 5 ; i < 10; i++) 
	{
		animals[i] = new Cat();
	}

	std::cout << "\n-----------------------------\n" << std::endl;

	for (size_t i = 0 ; i < 10; i++)
	{
		animals[i]->makeSound();
	}

	std::cout << "\n-----------------------------\n" << std::endl;

	for (size_t i = 0 ; i < 10; i++)
	{
		delete animals[i];
	}

	std::cout << "\n-----------------------------\n" << std::endl;

	Brain brain;

	brain.setIdea("idea1");

	const Dog* k = new Dog(brain);
	const Dog* m = new Dog(*k);

	k->makeSound();
	m->makeSound();

	k->getBrain()->setIdea("idea2");

	std::cout << k->getBrain()->getIdea() << std::endl;
	std::cout << m->getBrain()->getIdea() << std::endl;

	delete k;
	delete m;

	return 0;
}