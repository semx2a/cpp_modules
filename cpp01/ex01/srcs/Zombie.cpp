/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:48:49 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/23 17:23:45 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie( void ) {
	
	return ;
}

Zombie::~Zombie( void ) { 
	
	static int	i = 0;
	
	std::clog << this->_name << " " << i << " : has been destroyed." << std::endl;
	i++;
	return ;
}

void	Zombie::setName( std::string name ) {
	
	this->_name = name;
	return ;
}

std::string	Zombie::getName( void ) const {

	return this->_name;
}

void	Zombie::announce( void ) {
	
	static int	i = 0;
	std::cout << this->getName() << " " << i << " : BraiiiiiiinnnzzzZ..." << std::endl;
	i++;
}

