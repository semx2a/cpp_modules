/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:25:42 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 00:41:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/AAnimal.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

AAnimal::AAnimal(void) : _type("AAnimal") {

    std::cout << "AAnimal constructor" << std::endl;
 }

AAnimal::AAnimal(std::string const type) :_type(type) { }

AAnimal::AAnimal(AAnimal const & src) { *this = src; }

AAnimal::~AAnimal(void) {

    std::cout << "AAnimal destructor" << std::endl;
}

AAnimal &	AAnimal::operator=(AAnimal const & rhs) {

    if (this != &rhs) {
        this->_type = rhs.getType();
    }
    
	return *this;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void        AAnimal::setType(std::string const type) { this->_type = type; }

std::string AAnimal::getType(void) const { return this->_type; }

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void AAnimal::makeSound(void) const {
    
    std::cout << this->getType() << " says \"GrrrRRRrrrRRRrrr\"" << std::endl;
}
// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, AAnimal const & a) {
        
		return o << a.getType() << std::endl; 
}