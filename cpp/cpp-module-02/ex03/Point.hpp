/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 06:44:05 by gson              #+#    #+#             */
/*   Updated: 2022/07/24 20:56:50 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{

	public:

		Point();
		Point( const float x, const float y);
		Point( Point const & src );
		~Point();

		Point &		operator=( Point const & rhs );
		const Fixed & getX() const;
		const Fixed & getY() const;

	private:
		const Fixed x;
		const Fixed y;
		float cross;

};

std::ostream &			operator<<( std::ostream & o, Point const & i );
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* *********************************************************** POINT_H */