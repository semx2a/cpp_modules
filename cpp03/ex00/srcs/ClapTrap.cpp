/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:15:53 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/02 17:32:58 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/ClapTrap.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0) { 
	
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){ 

	std::cout << "Custom constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) { 

	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) { 
	
	std::cout << "Default Destructor called." << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs) {

	std::cout << "Copy assignment constructor called." << std::endl;

	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}

	return *this;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void	ClapTrap::setName(std::string const name) { this->_name = name; }

void	ClapTrap::setHitPoints(unsigned int const val) { this->_hitPoints = val; }

void	ClapTrap::setEnergyPoints(unsigned int const val) { this->_energyPoints = val; }

void	ClapTrap::setAttackDamage(unsigned int const val) { this->_attackDamage = val; }

std::string	ClapTrap::getName(void) const { return this->_name; }

unsigned int	ClapTrap::getHitPoints(void) const { return this->_hitPoints; }

unsigned int	ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }

unsigned int	ClapTrap::getAttackDamage(void) const { return this->_attackDamage; }

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void	ClapTrap::attack(const std::string & target) {
	
	if (this->getEnergyPoints() > 0) {
		
		std::cout << this->getName() << " attacks " << target << ", causing "
		<< this->getAttackDamage() << " points of damage!" << std::endl;
		
		this->_energyPoints--;
	}
	else
		std::cout << this->getName() << " has not enough energy to attack " 
		<< target << "." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	
	std::cout << this->getName() << " takes " << amount 
	<< " points of damage !" << std::endl;
	
	if (this->getEnergyPoints() >= amount)
		this->_energyPoints -= amount;
	else
		this->setEnergyPoints(0);
}

void	ClapTrap::beRepaired(unsigned int amount) {
	
	if (this->getEnergyPoints() > 0) {
		
		std::cout << this->getName() << " gets " << amount 
		<< " energy points!" << std::endl;
		
		if (this->getHitPoints() < std::numeric_limits<unsigned int>::max() 
			&& this->getHitPoints() + amount < std::numeric_limits<unsigned int>::max())
			this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << this->getName() << " has no energy left to be repaired." << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &	operator<<(std::ostream & o, ClapTrap const & c) {
	return o << c.getName() << " has " << c.getHitPoints() << " hit points, "
				<< c.getEnergyPoints() << " energy points, and " 
				<< c.getAttackDamage() << " attack damage points." << std::endl; 

}
