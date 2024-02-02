/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:25:42 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 01:17:28 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/WrongAnimal.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

WrongAnimal::WrongAnimal(void) :_type("WrongAnimal"){

    std::cout << "WrongAnimal constructor" << std::endl;
 }

WrongAnimal::WrongAnimal(std::string const type) :_type(type) { }

WrongAnimal::WrongAnimal(WrongAnimal const & src) { *this = src; }

WrongAnimal::~WrongAnimal(void) {

    std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & rhs) {

    if (this != &rhs) {
        this->_type = rhs.getType();
    }
    
	return *this;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void        WrongAnimal::setType(std::string const type) { this->_type = type; }

std::string WrongAnimal::getType(void) const { return this->_type; }

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void WrongAnimal::makeSound(void) const {
    
    std::cout << this->getType() << " says \"distorted noise\"" << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, WrongAnimal const & a) {
        
		return o << a.getType() << std::endl; 
}