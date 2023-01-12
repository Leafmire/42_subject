/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:42:09 by gson              #+#    #+#             */
/*   Updated: 2022/08/06 19:58:45 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base * generate(void)
{
	int random;
	Base *base;
	srand(time(0));

	random = rand() % 3;

	switch (random) {
		case 0 : 
			base = new A;
			break;
		case 1 : 
			base = new B;
			break;
		case 2 : 
			base = new C;
			break;
	}
	
	return (base);
}

void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	if (a == NULL)
	{
		B *b = dynamic_cast<B *>(p);
		if (b == NULL)
		{
			C *c = dynamic_cast<C *>(p);
			if (c == NULL)
			{
				std::cout << "Can not cast these type." << std::endl;
			}
			else
				std::cout << "C" << std::endl;
		}
		else
			std::cout << "B" << std::endl;
	}
	else
		std::cout << "A" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception  & e)
	{
		(void) e;
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void) b;
			std::cout << "B" << std::endl;
		}
		catch (std::exception  & e)
		{
			(void) e;
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void) c;
				std::cout << "C" << std::endl;
			}
			catch (std::exception  & e)
			{
				(void) e;
				std::cout << "Can not cast these type." << std::endl;
			}			
		}
	}
}

int main(void)
{
	Base *random_base = generate();

	identify(random_base);
	identify(*random_base);

	Base *origin_base = new Base;

	identify(origin_base);
	identify(*origin_base);

	delete random_base;
	delete origin_base;

	return (0);
}