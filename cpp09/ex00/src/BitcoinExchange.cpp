/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:10:56 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 13:18:38 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

BitcoinExchange::BitcoinExchange() : 
_inputPath(),
_databasePath("data.csv"),
_file(),
_buffer(),
_dataBase() {}

BitcoinExchange::BitcoinExchange(std::string const path) : _inputPath(path), _databasePath("data.csv"), _file(), _buffer(), _dataBase() {
	
	this->_parseDatabase(this->_databasePath);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) { *this = rhs; }

BitcoinExchange::~BitcoinExchange() {}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: OPERATORS::

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	
	if (this != &rhs) {

		this->setInputPath(rhs.getInputPath());
		this->setDatabasePath(rhs.getDatabasePath());
		this->setDataBase(rhs.getDataBase());
	}
	return (*this);
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

std::string	BitcoinExchange::getInputPath(void) const { return this->_inputPath; }

std::string	BitcoinExchange::getDatabasePath(void) const { return this->_databasePath; }

t_map	BitcoinExchange::getDataBase(void) const { return this->_dataBase; }

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MUTATORS::

void	BitcoinExchange::setInputPath(std::string const path) { this->_inputPath = path; }

void	BitcoinExchange::setDatabasePath(std::string const path) { this->_databasePath = path; }

void	BitcoinExchange::setDataBase(t_map const dataBase) { this->_dataBase = dataBase; }

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::

bool	BitcoinExchange::_checkValue(float const value) {
	
	if (value < 0) {
		this->_buffer << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (value > 1000) {
		this->_buffer << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::_checkDate(std::string const date) {

	std::stringstream	s(date);
	int 				day, month, year;
	char				sep;
	
	s >> year >> sep >> month >> sep >> day;
	
	if (!isValidDate(day, month, year)) {
		this->_buffer << "Error: bad input => " << date << std::endl;
		return false;
	}
	
	return true;
}



void	BitcoinExchange::_makeMap() {

	for (std::string line; std::getline(this->_file, line, '\n'); ) {

		std::stringstream s(line);
		std::string	date;
		float		value;

		std::getline(s, date, ',');
		s >> value;
		
		if (!date.compare(0, 4, "date"))
			continue;
		
		this->_dataBase.insert(std::pair<std::string, float>(date, value));
	}
}

void	BitcoinExchange::_openFile(std::string const &filePath) {

	this->_file.open(filePath.c_str(), std::ifstream::in);
	if (!this->_file.is_open())
		throw std::runtime_error("could not open \'" + filePath + "\'.");
}

void	BitcoinExchange::_parseDatabase(std::string const &filePath) {
	
	this->_openFile(filePath);
	this->_makeMap();
	this->_file.close();
}

float BitcoinExchange::_getExchangeRate(std::string const date) {
	
    t_map::iterator it = this->_dataBase.lower_bound(date);

    // If the iterator points to the beginning, then the closest key is the first key
    if (it == this->_dataBase.begin() || it->first == date) {
        return it->second;
    }
	else {
		--it;
		return it->second;
	}
}

void BitcoinExchange::displayValuePrice(void) {


	this->_openFile(this->_inputPath);

	for (std::string line; std::getline(this->_file, line, '\n');) {
		std::stringstream s2(line);
		std::string	key;
		float		value;
		char		sep;
	
		s2 >> std::skipws >> key >> sep >> value;
	
		if (!key.compare(0, 4, "date"))
			continue;
	
		if (!this->_checkDate(key))
			continue;
		if (!this->_checkValue(value))
			continue;
	
		float price;
		price = value * this->_getExchangeRate(key);
		this->_buffer << key << " => " << value << " = " << price << std::endl;
	}
		
	this->_file.close();
	std::cout << this->_buffer.str();
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::: OVERLOAD OPERATORS::

std::ostream &	operator<<(std::ostream &o, BitcoinExchange const &btc) {

	(void)btc;
	o << "Hello, I'm the BitcoinExchange, and I'm here to help you." << std::endl;
	return (o);
}