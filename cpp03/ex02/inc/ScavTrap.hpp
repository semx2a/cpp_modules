/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:14 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/03 16:11:54 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	public:

		ScavTrap(void);
		ScavTrap(std::string const);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap &	operator=(ScavTrap const & rhs);

		void		attack(const std::string & target);
		void		guardGate(void);
};

std::ostream &	operator<<(std::ostream & o, ScavTrap const & c);

#endif
