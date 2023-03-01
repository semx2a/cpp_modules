/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:44:36 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/22 21:06:54 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

# include <iostream>
# include <iomanip>
# include <string>
# include "Weapon.hpp"

class HumanA {
	
public:
	
	HumanA (std::string, Weapon &);
	~HumanA (void);

	void			attack (void);
	
	void			setName (std::string);
	
	std::string		getName (void) const;
	Weapon const &	getWeapon (void) const;

private:

	std::string		_name;
	Weapon&			_type;
};

#endif
