/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:21:28 by gson              #+#    #+#             */
/*   Updated: 2022/08/06 20:55:37 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T& a, T& b)
{
	T temp;

	temp = a;
	a = b;
	b = temp; 
}

template <typename T>
const T & min(T& a, T& b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

template <typename T>
T const & max(T& a, T& b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

#endif