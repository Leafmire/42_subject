/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:15:36 by gson              #+#    #+#             */
/*   Updated: 2022/08/06 21:05:25 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Test
{
	public:
		Test() { this->c = 'Z'; }
		char getC() const { return (this->c); }
	private:
		char c;
};

std::ostream& operator<<( std::ostream & o, Test const & i )
{
	o << i.getC();
	return (o);
}

int main(void)
{
	
	int array_i[5] = {1, 2, 3, 4, 5};
	iter(array_i, 5, print);

	std::cout << "----------------------------" << std::endl;

	std::string array_s[5] = {"alice", "bruce", "crux", "dan", "eater"};
	iter(array_s, 5, print);
	
	std::cout << "----------------------------" << std::endl;

	Test array_c[5];
	iter(array_c, 5, print);

	return 0;
}