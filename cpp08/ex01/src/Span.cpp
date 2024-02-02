/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:45:10 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/05 17:20:07 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::CONSTRUCTORS::

Span::Span(void) : _span(), _maxElements(0) {}

Span::Span(unsigned int n) : _span(), _maxElements(n) {}

Span::~Span(void) {}

Span::Span(Span const& rhs) {
	
	if (this != &rhs)
		*this = rhs;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::OPERATORS::

Span&	Span::operator=(Span const& rhs) {
	if (this != &rhs)
	{
		this->setSpan(rhs.getSpan());
		this->setMaxElements(rhs.getMaxElements());
	}
	return (*this);
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::ACCESSORS::

void	Span::setSpan(std::vector<int> span) { this->_span = span; }

void	Span::setMaxElements(unsigned int n) { this->_maxElements = n; }

std::vector<int> const &	Span::getSpan(void) const { return (this->_span); }

unsigned int	Span::getMaxElements(void) const { return (this->_maxElements); }

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::METHODS::

void 	Span::addNumber(int n) {
	
	if (this->getSpan().size() == this->getMaxElements())
		throw std::exception();
	this->_span.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

	if (this->getSpan().size() + std::distance(begin, end) > this->getMaxElements())
		throw std::exception();
	this->_span.insert(this->_span.end(), begin, end);
}

unsigned int 	Span::shortestSpan(void) {
	
	try {

		if (this->getSpan().size() <= 1)
			throw std::runtime_error("Not enough numbers");
	}
	catch (std::runtime_error &re) {
		std::cerr << "shortestSpan: " << re.what() << std::endl;
	}
	
	std::vector<int> tmp = this->getSpan();
	std::sort(tmp.begin(), tmp.end());
	unsigned int ret = tmp[1] - tmp[0];
	
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++) {
		unsigned int comp = *(it + 1) - *it;
		ret = std::min(ret, comp);
	}

	return (ret);
}

unsigned int 	Span::longestSpan(void) {
	
	try {
	
		if (this->getSpan().size() <= 1)
			throw std::runtime_error("Not enough numbers");
	}
	catch (std::runtime_error &re) {
		std::cerr << "longestSpan: " << re.what() << std::endl;
	}
	
	unsigned int min = 0, max = 0;
	
	min = *std::min_element(this->getSpan().begin(), this->getSpan().end());
	max = *std::max_element(this->getSpan().begin(), this->getSpan().end());
	return (max - min);
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::OVERTLOADING OPERATORS::

std::ostream &operator<<(std::ostream &o, Span const &s) {
	
	std::vector<int> tmp(s.getSpan());
	
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		
		if (it == tmp.begin())
			o << '{';
		
		o << *it;
		
		if (it + 1 != tmp.end())
			o << ", ";
		else
			o << '}';
	}
	return (o);
}