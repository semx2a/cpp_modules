/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:25:42 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/04 19:11:06 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/WrongCat.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

WrongCat::WrongCat(void) { this->setType("WrongCat"); }

WrongCat::WrongCat(std::string const type) { this->setType(type); }

WrongCat::WrongCat(WrongCat const & src) { *this = src; }

WrongCat::~WrongCat(void) { }

WrongCat &	WrongCat::operator=(WrongCat const & rhs) {

    if (this != &rhs) {
        this->setType(rhs.getType());
	}
    
	return *this;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, WrongCat const & a) {
        
		return o << a.getType() << std::endl; 
}