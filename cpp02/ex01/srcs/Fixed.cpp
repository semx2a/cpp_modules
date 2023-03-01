/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:06:48 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/01 14:47:14 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "../inc/Fixed.hpp"

Fixed::Fixed(void) : _val(0) { 
	
	std::clog << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	
	std::clog << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const val) : _val(val << _fractionalBits) { 
	
	std::clog << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const val) : _val((int)roundf(val * (1 << _fractionalBits))) {

	std::clog << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) { 
	
	std::clog << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	
	std::clog << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_val = rhs.getRawBits();

	return *this;
}

int	Fixed::getRawBits(void) const {

	return this->_val;
}

void	Fixed::setRawBits(int const raw) {
	
	this->_val = raw;
}

float	Fixed::toFloat(void) const {

	return ((float)this->_val) / (1 << this->_fractionalBits);
}

int		Fixed::toInt(void) const {
	
	return this->_val >> this->_fractionalBits;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & f) {
	
	o << f.toFloat();

	return o;
}