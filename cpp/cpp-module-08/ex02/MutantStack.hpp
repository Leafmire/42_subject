/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:24:19 by gson              #+#    #+#             */
/*   Updated: 2022/08/10 13:47:30 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define  MUTANTSTACK_HPP

#include <deque>
# include <iostream>
# include <algorithm>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		MutantStack(void)
		{
		}
		
		MutantStack(const MutantStack & src)
		{ 
			*this = src;
		}

		~MutantStack(void)
		{
		}

		MutantStack & operator= (MutantStack const & rhs)
		{
			if (this != &rhs)
			{
				this->std::stack<T>::operator=(rhs);
			}
			return *this;
		}

		
		iterator begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}

		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}

		reverse_iterator rend()
		{
			return (this->c.rend());
		}

	private:
};

#endif