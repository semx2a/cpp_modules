/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:44:36 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/22 21:07:02 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

# include <iostream>
# include <iomanip>
# include <string>
# include "Weapon.hpp"

class HumanB {
	
public:

	HumanB (std::string);
	~HumanB (void);

	void			attack (void);
	
	void			setName (std::string);
	void			setWeapon (Weapon &);
	
	std::string		getName (void) const;
	Weapon const *	getWeapon (void) const;
	
private:

	std::string		_name;
	Weapon*			_type;
};

#endif
