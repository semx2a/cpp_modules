/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:57:44 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/03 16:09:33 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

# include <iostream>
# include <string>

class ClapTrap {
	
	public:

		ClapTrap(void);
		ClapTrap(std::string const);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap &		operator=(ClapTrap const & rhs);

		void			setName(std::string const);
		void			setHitPoints(unsigned int const);
		void			setEnergyPoints(unsigned int const);
		void			setAttackDamage(unsigned int const);
		
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;

		void			attack(const std::string & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	private:

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

std::ostream &	operator<<(std::ostream & o, ClapTrap const & c);

#endif
