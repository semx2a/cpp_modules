/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
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
#include "../inc/Cat.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Cat::Cat(void) { 

    std::cout << BHIORANGE << "Cat " << RESET << "constructor" << std::endl;
        
    this->setType("Cat");
    this->_noggin = new Brain();
}

Cat::Cat(std::string const type) { this->setType(type); }

Cat::Cat(Cat const & src) { 
    
    this->_type = src.getType();
    this->_noggin = new Brain(*src.getBrain());
}

Cat::~Cat(void) {

    std::cout << BHIORANGE << "Cat " << RESET <<  "destructor" << std::endl;

    delete this->getBrain();
}

Cat &	Cat::operator=(Cat const & rhs) {

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

void        Cat::setBrain(Brain* const ideas) { this->_noggin = ideas; }

Brain*      Cat::getBrain(void) const { return this->_noggin; }

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void Cat::makeSound(void) const {
    
    std::cout << BHIORANGE << this->getType() << RESET << " says \"Meow\"" << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, Cat const & a) {
        
		return o << a.getType() << std::endl; 
}