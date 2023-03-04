/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:25:42 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 00:16:15 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "../inc/Brain.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Brain::Brain(void) {
    
    std::cout << "Brain constructor" << std::endl;

    this->_ideas = new std::string[100];
 }

Brain::Brain(Brain const & src) { *this = src; }

Brain::~Brain(void) {

    std::cout << "Brain destructor" << std::endl;

    delete [] this->getIdeas();
}

Brain &	Brain::operator=(Brain const & rhs) {

    if (this != &rhs) {
        this->_ideas = rhs.getIdeas();
    }
    
	return *this;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void        Brain::setIdeas(std::string* const ideas) { this->_ideas = ideas; }

std::string* Brain::getIdeas(void) const { return this->_ideas; }

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &  operator<<(std::ostream & o, Brain const & b) {
        
		return o << b.getIdeas() << std::endl; 
}