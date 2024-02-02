/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:47:24 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/20 15:17:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon( std::string const & type ) : _type(type) {
	
	return ;
}

Weapon::~Weapon( void ) { 
	
	return ;
}

void	Weapon::setType( std::string const & type) {

	this->_type = type;
}

std::string const & Weapon::getType( void ) const {

	return this->_type;
}
