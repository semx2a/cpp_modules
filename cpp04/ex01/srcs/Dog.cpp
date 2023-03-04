/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:25:42 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/04 23:59:39 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/Dog.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Dog::Dog(void) { 
    
    std::cout << "Dog constructor" << std::endl;
    
    this->setType("Dog");
    this->_noggin = new Brain();
}

Dog::Dog(std::string const type) { this->setType(type); }

Dog::Dog(Dog const & src) { *this = src; }

Dog::~Dog(void) { 
    
    std::cout << "Dog destructor" << std::endl;

    delete this->getBrain();
}

Dog &	Dog::operator=(Dog const & rhs) {

    if (this != &rhs) {
        this->setType(rhs.getType());
        this->setBrain(rhs.getBrain());
    }
    
	return *this;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void        Dog::setBrain(Brain* const ideas) { this->_noggin = ideas; }

Brain*      Dog::getBrain(void) const { return this->_noggin; }

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void Dog::makeSound(void) const {
    
    std::cout << this->getType() << " says \"Waf\"" << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, Dog const & a) {
        
		return o << a.getType() << std::endl; 
}