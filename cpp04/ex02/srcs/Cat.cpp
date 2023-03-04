/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:25:42 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 00:00:38 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/Cat.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Cat::Cat(void) { 

    std::cout << "Cat constructor" << std::endl;
        
    this->setType("Cat");
    this->_noggin = new Brain();
}

Cat::Cat(std::string const type) { this->setType(type); }

Cat::Cat(Cat const & src) { *this = src; }

Cat::~Cat(void) {

    std::cout << "Cat destructor" << std::endl;

    delete this->getBrain();
}

Cat &	Cat::operator=(Cat const & rhs) {

    if (this != &rhs) {
        this->setType(rhs.getType());
        this->setBrain(rhs.getBrain());
    }
    
	return *this;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void        Cat::setBrain(Brain* const ideas) { this->_noggin = ideas; }

Brain*      Cat::getBrain(void) const { return this->_noggin; }

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void Cat::makeSound(void) const {
    
    std::cout << this->getType() << " says \"Meow\"" << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, Cat const & a) {
        
		return o << a.getType() << std::endl; 
}