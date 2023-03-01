/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:44:36 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/22 21:05:51 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>
# include <string>

class Zombie {
	
public:

	Zombie (std::string name);
	~Zombie (void);

	void		announce( void );
	
private:

	std::string	_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif