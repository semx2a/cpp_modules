/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:25:42 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/08 16:43:04 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/Dog.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Dog::Dog(void) { 
    
    std::cout << BHIGREEN << "Dog " << RESET << "constructor" << std::endl;
    
    this->setType("Dog");
    this->_noggin = new Brain();
}

Dog::Dog(std::string const type) { this->setType(type); }

Dog::Dog(Dog const & src) { 
    
    this->_type = src.getType();
    this->_noggin = new Brain(*src.getBrain()); 
}

Dog::~Dog(void) { 
    
    std::cout << BHIGREEN << "Dog " << RESET << "destructor" << std::endl;

    delete this->getBrain();
}

Dog &	Dog::operator=(Dog const & rhs) {

    if (this != &rhs) {
        
        this->setType(rhs.getType());
        if (this->_noggin) {
            delete this->_noggin;
        }
        this->_noggin = new Brain (*rhs.getBrain());
    }
    
	return *this;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void        Dog::setBrain(Brain* const ideas) { this->_noggin = ideas; }

Brain*      Dog::getBrain(void) const { return this->_noggin; }

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void Dog::makeSound(void) const {
    
    std::cout << BHIGREEN << this->getType() << RESET << " says \"Waf\"" << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, Dog const & a) {
        
		return o << a.getType() << std::endl; 
}