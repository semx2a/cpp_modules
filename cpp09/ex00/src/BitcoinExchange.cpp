/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:10:56 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/07 23:54:18 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

BitcoinExchange::BitcoinExchange() : _filePath(), _data() {}

BitcoinExchange::BitcoinExchange(std::string const path) : _filePath(path), _data() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) { *this = rhs; }

BitcoinExchange::~BitcoinExchange() {}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: OPERATORS::

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	
	if (this != &rhs) {
		
		this->setFilePath(rhs.getFilePath());
		this->setData(rhs.getData());
	}
	return (*this);
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void				BitcoinExchange::setFilePath(std::string const filePath) { this->_filePath = filePath; }

void				BitcoinExchange::setData(std::string const data) { this->_data = data; }

std::string const &	BitcoinExchange::getFilePath(void) const { return this->_filePath; }

std::string const &	BitcoinExchange::getData(void) const { return this->_data; }

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::



// :::::::::::::::::::::::::::::::::::::::::::::::::::::::: OVERLOAD OPERATORS::

std::ostream &	operator<<(std::ostream &o, BitcoinExchange const &btc) {

	o << btc.getData();
	return (o);
}