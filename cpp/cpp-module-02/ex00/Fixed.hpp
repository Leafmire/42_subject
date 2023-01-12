/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:32:27 by gson              #+#    #+#             */
/*   Updated: 2022/07/20 21:42:11 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &		operator=( Fixed const & rhs );

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:

		int	fixed_point;
		static const int fractional_bits;
};

#endif /* *********************************************************** FIXED_H */