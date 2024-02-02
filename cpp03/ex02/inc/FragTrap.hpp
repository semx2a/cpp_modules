/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:14 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/03 16:11:50 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	
	public:

		FragTrap(void);
		FragTrap(std::string const);
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const & rhs);

		void		attack(const std::string & target);
		void		highFivesGuys(void);
};

std::ostream &	operator<<(std::ostream & o, FragTrap const & f);

#endif
