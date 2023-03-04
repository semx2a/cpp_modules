/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:25:42 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/04 20:43:45 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/Dog.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Dog::Dog(void) { this->setType("Dog"); }

Dog::Dog(std::string const type) { this->setType(type); }

Dog::Dog(Dog const & src) { *this = src; }

Dog::~Dog(void) { }

Dog &	Dog::operator=(Dog const & rhs) {

    if (this != &rhs) {
        this->setType(rhs.getType());
    }
    
	return *this;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void Dog::makeSound(void) const {
    
    std::cout << this->getType() << " says \"Waf\"" << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, Dog const & a) {
        
		return o << a.getType() << std::endl; 
}