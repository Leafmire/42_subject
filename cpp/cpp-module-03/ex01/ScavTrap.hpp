/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:54:17 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 16:34:33 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		void attack(const std::string& target);
		void guardGate();
		void blockBehavior(std::string name);
		ScavTrap &		operator=( ScavTrap const & rhs );

	private:

};

#endif /* ******************************************************** SCAVTRAP_H */