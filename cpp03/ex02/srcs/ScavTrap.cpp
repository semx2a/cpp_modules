/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:18 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/02 17:02:34 by seozcan          ###   ########.fr       */
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

void	ScavTrap::attack(const std::string & target) {
	
	if (this->getEnergyPoints() > 0) {
		
		std::cout << this->getName() << " attacks " << target << "! "
		<< this->getAttackDamage() << " damages are inflicted." << std::endl;
		
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
		std::cout << this->getName() << " has not enough energy to attack " 
		<< target << "." << std::endl;
}

void	ScavTrap::guardGate(void) {
	
	if (this->getEnergyPoints() > 0)
		std::cout << this->getName() << " entered Gate Keeper mode." << std::endl;
	else
		std::cout << this->getName() << " has not enough energy to enter Gate Keeper mode." << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &	operator<<(std::ostream & o, ScavTrap const & s) {
	return o << s.getName() << " has " << s.getHitPoints() << " hit points, "
				<< s.getEnergyPoints() << " energy points, and " 
				<< s.getAttackDamage() << " attack damage points." << std::endl; 

}
