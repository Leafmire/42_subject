/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:54:17 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 02:02:56 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	public:

		FragTrap();
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap();

		void highFivesGuys( void );
		FragTrap &		operator=( FragTrap const & rhs );

	private:

};

#endif /* ******************************************************** FragTrap_H */