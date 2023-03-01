/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:04:50 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/22 21:07:12 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <iomanip>
# include <string>

class	Weapon {

public:
	
	Weapon (std::string const &);
	~Weapon (void);

	void				setType( std::string const & );
	std::string const &	getType( void ) const;
	
private: 

	std::string			_type;
};

#endif
