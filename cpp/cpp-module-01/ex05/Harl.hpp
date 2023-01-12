/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 03:12:12 by gson              #+#    #+#             */
/*   Updated: 2022/07/19 19:15:07 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl;

typedef struct s_complain {
	std::string level;
	void (Harl::*func)(void);
} t_complain;

class Harl
{
	private:
		t_complain complains[4];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		Harl(void);
		~Harl(void);

		void complain( std::string level );
};

#endif