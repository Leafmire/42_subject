/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:21:28 by gson              #+#    #+#             */
/*   Updated: 2022/08/06 21:07:09 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void iter(T* array, int array_len, void (*f)(T const &))
{
	for (int i = 0; i < array_len; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void print(T const &element)
{
	std::cout << element << std::endl;
}

#endif