/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:31:18 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 16:39:09 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		virtual ~ClapTrap();

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		virtual void blockBehavior(std::string name);

		void setName(std::string name);
		void setHitPoint(int hit_p);
		void setEnergyPoint(int energy_p);
		void setAttackDamage(int attack_d);

		std::string getName() const;
		int getHitPoint() const;
		int getEnergyPoint() const;
		int getAttackDamage() const;

		ClapTrap &		operator=( ClapTrap const & rhs );

		virtual void guardGate();
		virtual void highFivesGuys( void );

	private:

		std::string name;
		int hit_p;
		int energy_p;
		int attack_d;

};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */