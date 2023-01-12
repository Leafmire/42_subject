/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:42:09 by gson              #+#    #+#             */
/*   Updated: 2022/08/06 18:57:54 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data data = {'*', 42, 3.14f, 2.7};
	uintptr_t serial_ptr;
	Data *deserial_ptr;

	serial_ptr = serialize(&data);
	deserial_ptr = deserialize(serial_ptr);
	std::cout << "c: " << deserial_ptr->c << std::endl;
	std::cout << "i: " << deserial_ptr->i << std::endl;
	std::cout << "f: " << deserial_ptr->f << std::endl;
	std::cout << "d: " << deserial_ptr->d << std::endl;
	return (0);
}