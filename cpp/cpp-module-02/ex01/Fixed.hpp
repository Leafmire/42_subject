/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:32:27 by gson              #+#    #+#             */
/*   Updated: 2022/07/20 21:42:30 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{

	public:

		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &operator=( Fixed const & rhs );

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:

		int	fixed_point;
		static const int fractional_bits;
};

std::ostream &operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */