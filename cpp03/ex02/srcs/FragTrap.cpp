/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:18 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/02 17:26:30 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/FragTrap.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

FragTrap::FragTrap(void) { 
	
	std::cout << "FragTrap Default constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string const name) { 

	std::cout << "FragTrap Custom constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(FragTrap const & src) { 

	std::cout << "FragTrap Copy constructor called." << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void) { 
	
	std::cout << "FragTrap Destructor called." << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs) {

	std::cout << "FragTrap Copy assignment constructor called." << std::endl;
	if (this != &rhs) {
		
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	
	return *this;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void	FragTrap::attack(const std::string & target) {
	
	if (this->getEnergyPoints() > 0) {
		
		std::cout << this->getName() << " walks toward " << target << " attacks them, inflicting a whopping "
		<< this->getAttackDamage() << " damages!" << std::endl;
		
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
		std::cout << this->getName() << " has not enough energy to attack " 
		<< target << "." << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	
	if (this->getEnergyPoints() > 0) {
		
		std::string arg;
		
		while (std::cout << this->getName() << " says \"High Five !\" (yes/no):" 
				&& std::getline(std::cin, arg)) {
			
			if (!arg.compare("yes")){
				
				std::cout << this->getName() << " says \"Yeehaw!\"" << std::endl;
				break ;	
			}
			else if (!arg.compare("no")) {
				
				std::cout << this->getName() << ": 😓" << std::endl;
				break;
			}
		}
	}
	else
		std::cout << this->getName() << " has not enough energy to give a high five." << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &	operator<<(std::ostream & o, FragTrap const & f) {
	return o << f.getName() << " has " << f.getHitPoints() << " hit points, "
				<< f.getEnergyPoints() << " energy points, and " 
				<< f.getAttackDamage() << " attack damage points." << std::endl; 

}
