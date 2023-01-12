/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:21:28 by gson              #+#    #+#             */
/*   Updated: 2022/08/09 03:36:54 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	public:

		Span();
		Span( Span const & src );
		Span( unsigned int N );
		~Span();

		void addNumber( int num );

		int shortestSpan( void );
		int longestSpan( void );

		unsigned int	getN( void ) const;
		std::vector<int>	getVector( void ) const;

		template< typename T >
		void	addNumber( T range )
		{
			if (store.size() + range.size() > N)
				throw SpanNotStoreException();

			store.insert(store.end(), range.begin(), range.end());
		}
		Span &		operator=( Span const & rhs );

		class SpanNotStoreException : public std::exception{
			public :
				const char *what() const throw();
		};

		class SpanNotFoundException : public std::exception{
			public :
				const char *what() const throw();
		};

	private:
		unsigned int N;
		std::vector<int> store;
};

#endif