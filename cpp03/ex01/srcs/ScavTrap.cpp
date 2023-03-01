/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:18 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/01 17:52:36 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/ScavTrap.hpp"


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

ScavTrap::ScavTrap(void) { 
	
	std::cout << "ScavTrap Default constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string const name) { 

	std::cout << "ScavTrap Custom constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap const & src) { 

	std::cout << "ScavTrap Copy constructor called." << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void) { 
	
	std::cout << "ScavTrap Destructor called." << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs) {

	std::cout << "ScavTrap Copy assignment constructor called." << std::endl;
	if (this != &rhs) {
		
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	
	return *this;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void	ScavTrap::guardGate(void) {
	
	std::cout << this->getName() << " entered Gate Keeper mode." << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &	operator<<(std::ostream & o, ScavTrap const & s) {
	return o << s.getName() << " has " << s.getHitPoints() << " hit points, "
				<< s.getEnergyPoints() << " energy points, and " 
				<< s.getAttackDamage() << " attack damage points." << std::endl; 

}
