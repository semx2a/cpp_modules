/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
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
#include "../inc/Brain.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Brain::Brain(void) {
    
    std::cout << BHIPURPLE <<"Brain " << RESET << "constructor" << std::endl;

    this->_ideas = new std::string[100];
    
    for (int i = 0; i < 100; i++) {
        
        this->_ideas[i] = "Original idea";
    }
 }

Brain::Brain(Brain const & src) { 
    
    std::string *tmp = src.getIdeas();
    
    this->_ideas = new std::string[100];
    for (int i = 0; i < 100; i++) {
            
        this->_ideas[i] = tmp[i];
    }
}

Brain::~Brain(void) {

    std::cout << BHIPURPLE << "Brain " << RESET << "destructor" << std::endl;

    delete [] this->getIdeas();
}

Brain &	Brain::operator=(Brain const & rhs) {

    if (this != &rhs) {
        

        for (int i = 0; i < 100; i++) {
            
            this->_ideas[i] = rhs._ideas[i];
        }
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