/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:25:42 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 17:01:51 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/Animal.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Animal::Animal(void) : _type("Animal") {

    std::cout << BHIBLUE <<"Animal " << NO_COLOR << "constructor" << std::endl;
 }

Animal::Animal(std::string const type) :_type(type) { }

Animal::Animal(Animal const & src) { *this = src; }

Animal::~Animal(void) {

    std::cout << BHIBLUE << "Animal " << NO_COLOR "destructor" << std::endl;
}

Animal &	Animal::operator=(Animal const & rhs) {

    if (this != &rhs) {
        this->_type = rhs.getType();
    }
    
	return *this;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void        Animal::setType(std::string const type) { this->_type = type; }

std::string Animal::getType(void) const { return this->_type; }

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void Animal::makeSound(void) const {
    
    std::cout << BHIBLUE << this->getType() << NO_COLOR <<" says \"GrrrRRRrrrRRRrrr\"" << std::endl;
}
// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, Animal const & a) {
        
		return o << a.getType() << std::endl; 
}