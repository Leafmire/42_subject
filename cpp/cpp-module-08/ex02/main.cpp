/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:15:36 by gson              #+#    #+#             */
/*   Updated: 2022/08/10 13:48:46 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> list;

	mstack.push(5);
	mstack.push(17);
	list.push_back(5);
	list.push_back(17);

	std::cout << "MutantStack: " << mstack.top() << std::endl;
	std::cout << "List: " << list.back() << std::endl;
	std::cout << "\n-------------------------------\n";
	
	mstack.pop();
	list.pop_back();

	std::cout << "MutantStack size: " << mstack.size() << std::endl;
	std::cout << "List size: " << list.size() << std::endl;
	std::cout << "\n-------------------------------\n";

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator list_it = list.begin();
	std::list<int>::iterator list_ite = list.end();

	++it;
	--it;

	std::cout << "MutantStack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n-------------------------------\n";

	std::cout << "List" << std::endl;
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}
	std::cout << "\n-------------------------------\n";

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::list<int>::reverse_iterator list_rit = list.rbegin();
	std::list<int>::reverse_iterator list_rite = list.rend();

	std::cout << "MutantStack" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << "\n-------------------------------\n";

	std::cout << "List" << std::endl;
	while (list_rit != list_rite)
	{
		std::cout << *list_rit << std::endl;
		++list_rit;
	}
	std::cout << "\n-------------------------------\n";

	MutantStack<int> s(mstack);
	MutantStack<int>::iterator its = s.begin();
	MutantStack<int>::iterator ites = s.end();
	std::cout << "MutantStack s" << std::endl;
	while (its != ites)
	{
		std::cout << *its << std::endl;
		++its;
	}
	std::cout << "\n-------------------------------\n";
	return 0;
}