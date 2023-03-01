/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:56:23 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/23 14:40:25 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {
	
	this->_type = NULL;
	return ;
} 

HumanB::~HumanB( void ) {
	
	std::clog << this->_name << " : has been destroyed." << std::endl;
	return ;
}

void	HumanB::setName( std::string name ) {
	
	this->_name = name;
	return ;
}

void	HumanB::setWeapon( Weapon & ref ) {
	
	this->_type = &ref;
	return ;
}


std::string	HumanB::getName( void ) const {

	return this->_name;
}

Weapon const * HumanB::getWeapon( void ) const {

	return this->_type;
	
}

void	HumanB::attack( void ) {
	
	if (this->_type)
		std::cout << this->getName() << " attacks with their " << this->getWeapon()->getType() << std::endl;
}
