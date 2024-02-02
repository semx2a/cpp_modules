/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:06:48 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/03 12:28:56 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "../inc/Fixed.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Fixed::Fixed(void) : _val(0) { }

Fixed::Fixed(Fixed const & src) { *this = src; }

Fixed::Fixed(int const val) : _val(val << _fractionalBits) { }

Fixed::Fixed(float const val) : _val((int)roundf(val * (1 << _fractionalBits))) {
	
	if (this->getRawBits() < _minVal || this->getRawBits() > _maxVal)
		std::cout << "Fixed point value is out of range." << std::endl;
 }

Fixed::~Fixed(void) { }

// Copy Constructor
Fixed &	Fixed::operator=(Fixed const & rhs) {
	
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());

	return *this;
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::: ARITHMETIC OPERATORS::

Fixed Fixed::operator+(const Fixed & rhs) const {
    
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed & rhs) const {
    
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed & rhs) const {
    
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed & rhs) const {
    
	return Fixed(this->toFloat() / rhs.toFloat());
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::: COMPARISON OPERATORS::

bool Fixed::operator<(const Fixed & rhs) const {
    
	return this->_val < rhs._val;
}

bool Fixed::operator>(const Fixed & rhs) const {
    
	return this->_val > rhs._val;
}

bool Fixed::operator<=(const Fixed & rhs) const {
    
	return this->_val <= rhs._val;
}

bool Fixed::operator>=(const Fixed & rhs) const {
    
	return this->_val >= rhs._val;
}

bool Fixed::operator==(const Fixed & rhs) const {
    
	return this->_val == rhs._val;
}

bool Fixed::operator!=(const Fixed & rhs) const {
    
	return this->_val != rhs._val;
}
// ::::::::::::::::::::::::::::: INCREMENT AND DECREMENT OPERATOR OVERLOADING ::

// PREFIX INCREMENT
Fixed&			Fixed::operator++(void) {
	
	this->_val++;
	
	return *this;
}

// POSTFIX INCREMENT
Fixed 			Fixed::operator++(int) {
	
	Fixed	tmp = *this;
	++*this;

	return tmp;	
}

// PREFIX DECREMENT
Fixed&			Fixed::operator--(void) {
	
	this->_val--;

	return *this;
}

// POSTFIX DECREMENT
Fixed 			Fixed::operator--(int) {
	
	Fixed	tmp = *this;
	--*this;

	return tmp;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

int	Fixed::getRawBits(void) const {

	return this->_val;
}

void	Fixed::setRawBits(int const raw) {
	
	this->_val = raw;
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

float	Fixed::toFloat(void) const { 
	
	return (float)this->getRawBits() / (1 << this->_fractionalBits);
}

int	Fixed::toInt(void) const {
	
	return this->getRawBits() >> this->_fractionalBits; 
}

Fixed	Fixed::min(Fixed & lhs, Fixed & rhs) {

	return ( lhs < rhs ) ? lhs : rhs;
}

Fixed	Fixed::min(Fixed const & lhs, Fixed const & rhs) {
	
	return ( lhs < rhs ) ? lhs : rhs;
}

Fixed	Fixed::max(Fixed & lhs, Fixed & rhs) {
	
	return (lhs > rhs) ? lhs : rhs;
}

Fixed	Fixed::max(Fixed const & lhs, Fixed const & rhs) {
	
	return (lhs > rhs) ? lhs : rhs;
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &	operator<<(std::ostream & o, Fixed const & f) {
	
	o << f.toFloat();
	
	return o;
}