/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:48:49 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/23 17:23:04 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {

	return ;
}

Zombie::~Zombie( void ) { 
	
	std::clog << this->_name << " : has been destroyed." << std::endl;
	return ;
}

void	Zombie::announce( void ) {
	
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}