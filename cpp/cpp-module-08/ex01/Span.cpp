/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:19:40 by gson              #+#    #+#             */
/*   Updated: 2022/08/10 13:27:47 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	this->N = 0;
}

Span::Span( unsigned int N )
{
	this->N = N;
}

Span::Span( Span const & src )
{
	*this = src;
}

Span::~Span()
{
	
}

Span &	Span::operator=( Span const & rhs )
{
	if (this != &rhs)
	{
		this->N = rhs.N;
		this->store = rhs.store;
	}
	return (*this);
}

int Span::shortestSpan( void )
{
	if (this->store.size() < 2)
		throw SpanNotFoundException();

	std::vector<int> sorted(this->store);
	std::sort(sorted.begin(), sorted.end());

	int	front_it = sorted.front();
	std::vector<int>::iterator it = sorted.begin() + 1;
	int	diff = *it - front_it;

	for (; it != sorted.end(); it++) {
		if (*it - front_it < diff)
			diff = *it - front_it;
		front_it = *it;
    }

	return (diff);
}

int Span::longestSpan( void )
{
	if (this->store.size() < 2)
		throw SpanNotFoundException();

	std::vector<int> sorted(this->store);
	std::sort(sorted.begin(), sorted.end());

	int diff = sorted.back() - sorted.front();

	return (diff);
}

void	Span::addNumber( int num )
{
	if (this->store.size() == this->N)
		throw SpanNotStoreException();

	store.push_back(num);
}

unsigned int	Span::getN( void ) const
{
	return (this->N);
}

std::vector<int>	Span::getVector( void ) const
{
	return (this->store);
}

const char * Span::SpanNotStoreException::what() const throw()
{
	return "Span is full. You can't store number.";
}

const char * Span::SpanNotFoundException::what() const throw()
{
	return "Span is not found.";
}
