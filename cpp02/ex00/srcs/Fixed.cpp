/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:06:48 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/27 19:54:31 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Fixed.hpp"

Fixed::Fixed(void) : _val(0) { 
	
	std::clog << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	
	std::clog << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) { 
	
	std::clog << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {

	std::clog << "getRawBits member function called" << std::endl;
	
	return this->_val;
}

void	Fixed::setRawBits(int const raw) {
	
	this->_val = raw;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	
	std::clog << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_val = rhs.getRawBits();

	return *this;
}