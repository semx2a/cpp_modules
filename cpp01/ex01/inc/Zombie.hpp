/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:44:36 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/22 21:06:00 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>
# include <string>

class Zombie {
	
public:

	Zombie (void);
	~Zombie (void);

	void		announce( void );
	void		setName( std::string );
	std::string	getName( void ) const;

	
private:

	std::string	_name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif