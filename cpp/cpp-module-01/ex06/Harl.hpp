/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 03:12:12 by gson              #+#    #+#             */
/*   Updated: 2022/07/19 19:08:40 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string>

class Harl;

typedef struct s_complain {
	int index;
	std::string level;
	void (Harl::*func)(void);
} t_complain;

class Harl
{
	private:
		t_complain complains[5];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void other( void );
	public:
		Harl(void);
		~Harl(void);

		void complain( std::string level );

};

#endif