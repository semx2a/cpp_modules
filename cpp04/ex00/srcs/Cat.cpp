/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
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
#include "../inc/Cat.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Cat::Cat(void) { this->setType("Cat"); }

Cat::Cat(std::string const type) { this->setType(type); }

Cat::Cat(Cat const & src) { *this = src; }

Cat::~Cat(void) { }

Cat &	Cat::operator=(Cat const & rhs) {

    if (this != &rhs) {
        this->setType(rhs.getType());
    }
    
	return *this;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void Cat::makeSound(void) const {
    
    std::cout << this->getType() << " says \"Meow\"" << std::endl;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, Cat const & a) {
        
		return o << a.getType() << std::endl; 
}