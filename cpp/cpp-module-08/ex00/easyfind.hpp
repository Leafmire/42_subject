/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:21:28 by gson              #+#    #+#             */
/*   Updated: 2022/08/10 13:18:14 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

class NotFoundException : public std::exception{
	public :
		const char *what() const throw() {
			return "Not found";
		}
};

template <typename T>
int & easyfind(T& container, int n)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), n);

	if (iter == container.end())
		throw NotFoundException();

	return *iter;
}


#endif