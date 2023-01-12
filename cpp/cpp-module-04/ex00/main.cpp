/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:16:38 by gson              #+#    #+#             */
/*   Updated: 2022/08/04 16:03:14 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;

		std::cout << "\n\n----------------------------------\n\n" << std::endl;

		const WrongAnimal* wrong_a = new WrongAnimal();
		const WrongAnimal* wrong_cat = new WrongCat();
		std::cout << wrong_a->getType() << " " << std::endl;
		std::cout << wrong_cat->getType() << " " << std::endl;
		wrong_cat->makeSound(); //will output the wronganimal sound!
		wrong_a->makeSound();

		delete wrong_a;
		delete wrong_cat;
	return 0;
}