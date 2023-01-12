/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:15:35 by gson              #+#    #+#             */
/*   Updated: 2022/08/06 18:27:31 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <climits>
# include <limits>

class Convert
{

	public:

		Convert();
		Convert( Convert const & src );
		~Convert();

		void convertType(char* arg);

		char getChar(void) const;
		int getInt(void) const;
		float getFloat(void) const;
		double getDouble(void) const;

		bool myIsinf( float val );
		bool myIsinf( double val );

		bool checkDisplay() const;
		bool checkIsNan() const;
		bool checkIsInf();
		bool checkIsInt() const;

		void printChar();
		void printInt();
		void printFloat();
		void printDouble();

		Convert &		operator=( Convert const & rhs );

	private:

		char c;
		int i;
		float f;
		double d;

};

#endif /* ********************************************************* CONVERT_H */