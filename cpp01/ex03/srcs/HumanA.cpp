/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:48:49 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/20 16:10:19 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA( std::string name, Weapon & ref ) : _name(name), _type(ref) {
	
	return ;
}

HumanA::~HumanA( void ) { 
	
	std::clog << this->_name << " : has been destroyed." << std::endl;
	return ;
}

void	HumanA::setName( std::string name ) {
	
	this->_name = name;
	return ;
}

std::string	HumanA::getName( void ) const {

	return this->_name;
}

Weapon const &	HumanA::getWeapon( void ) const {
  
	return this->_type;
}

void	HumanA::attack( void ) {
	
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}

