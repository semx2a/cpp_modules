/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:56 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/30 17:44:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string str) : _c(0), _i(0), _f(0), _d(0),  _str(str), _isPossible(true), _isNegative(false) {
	
	this->setConvert();
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs) { *this = rhs; }

ScalarConverter::~ScalarConverter() {}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: OPERATOR::

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
		this->setStr(rhs.getStr());
		this->setConvert();
	}
	return (*this);
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

const std::string &	ScalarConverter::getStr(void) const { return (this->_str); }

char				ScalarConverter::getC(void) const { return (this->_c); }

int					ScalarConverter::getI(void) const { return (this->_i); }

float				ScalarConverter::getF(void) const { return (this->_f); }

double				ScalarConverter::getD(void) const { return (this->_d); }

bool				ScalarConverter::getIsPossible(void) const { return (this->_isPossible); }

bool				ScalarConverter::getIsNegative(void) const { return (this->_isNegative); }

void 				ScalarConverter::setStr(const std::string str) { this->_str = str; }

void 				ScalarConverter::setC(const char c) { this->_c = c; }

void 				ScalarConverter::setI(const int i) { this->_i = i; }

void 				ScalarConverter::setF(const float f) { this->_f = f; }

void 				ScalarConverter::setD(const double d) { this->_d = d; }

void 				ScalarConverter::setIsPossible(const bool isPossible) { this->_isPossible = isPossible; }

void 				ScalarConverter::setIsNegative(const bool isNegative) { this->_isNegative = isNegative; }

void				ScalarConverter::setConvert(void) {
	
	this->_convert[CHAR] = &ScalarConverter::_convertChar;
	this->_convert[INT] = &ScalarConverter::_convertInt;
	this->_convert[FLOAT] = &ScalarConverter::_convertFloat;
	this->_convert[DOUBLE] = &ScalarConverter::_convertDouble;
	this->_convert[_NAN] = &ScalarConverter::_convertNan;
	this->_convert[INF] = &ScalarConverter::_convertInf;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::


t_type ScalarConverter::_whichNumType(std::string str) {

	int		len = str.length();
	bool	decimal = false;

	for (int i = 0; i < len; i++) {
		
		if (i == 0 && (str.at(i) == '+' || str.at(i) == '-')) 
			i++;
		if (str.at(i) == 'f' && (i + 1 == len) && std::isdigit(this->getStr().at(i - 1))) {
			return FLOAT;
		}
		else if (str.at(i) == '.') {
			if (decimal == false)
				decimal = true;
			else
				return INVALID;
    	}
		else if (!std::isdigit(str.at(i))) {
			return INVALID;
    	}
	}	
	if (decimal == true)
		return DOUBLE;
	else
		return INT;
}

t_type ScalarConverter::_findType(void) {
	
	if (this->getStr().length() == 1 && !std::isdigit(this->getStr().at(0)))
		return CHAR;
	else if (this->getStr() == "nan" || this->getStr()== "nanf")
		return _NAN;
	else if (this->getStr() == "+inf" || this->getStr() == "-inf" || this->getStr() == "+inff" || this->getStr() == "-inff")
		return INF;
	else
		return this->_whichNumType(this->getStr());
}

void	ScalarConverter::_convertChar(void) {
	
	try {
		this->setC(static_cast<char>(this->getStr().at(0)));
		this->setI(static_cast<int>(this->getC()));
		this->setF(static_cast<float>(this->getC()));
		this->setD(static_cast<double>(this->getC()));
	}
	catch (std::bad_cast &bc) {
		std::cout << bc.what();
	}
}

void	ScalarConverter::_convertInt(void) {

	try {
		this->setI(atoi(this->getStr().c_str()));
		this->setC(static_cast<char>(this->getI()));
		this->setF(static_cast<float>(this->getI()));
		this->setD(static_cast<double>(this->getI()));
	}
	catch (std::bad_cast &bc) {
		std::cout << bc.what();
	}
}

void	ScalarConverter::_convertFloat(void) {

	try {
		this->setF(strtof(this->getStr().c_str(), NULL));
		this->setC(static_cast<char>(this->getF()));
		this->setI(static_cast<int>(this->getF()));
		this->setD(static_cast<double>(this->getF()));
	}
	catch (std::bad_cast &bc) {
		std::cout << bc.what();
	}
}

void ScalarConverter::_convertDouble(void) {

	try {
		this->setD(strtod(this->getStr().c_str(), NULL));
		this->setC(static_cast<char>(this->getD()));
		this->setI(static_cast<int>(this->getD()));
		this->setF(static_cast<float>(this->getD()));
	}
	catch (std::bad_cast &bc) {
		std::cout << bc.what();
	}
}

void ScalarConverter::_convertNan (void) {
	
	this->setIsPossible(false);
	try {
		if (this->getStr().compare("nanf")) {
			std::cout << "nanf" << std::endl;
			this->setF(std::numeric_limits<float>::quiet_NaN());
			this->setD(static_cast<double>(this->getF()));
		}
		else if (this->getStr().compare("nan")) {
			std::cout << "nan" << std::endl;
			this->setD(std::numeric_limits<double>::quiet_NaN());
			this->setF(static_cast<float>(this->getD()));
		}
	}
	catch (std::bad_cast &bc) {
		std::cout << bc.what();
	}
}

void ScalarConverter::_convertInf (void) {
	
	this->setIsPossible(false);
	try {
		if (this->getStr()[0] == '-')
			this->setIsNegative(true);
		
		if (!this->getStr().compare(1, 5, "inff")) {
			this->setF(std::numeric_limits<float>::infinity());
			this->setD(static_cast<double>(this->getF()));
		}
		else if (!this->getStr().compare(1, 4, "inf")) {
			this->setD(std::numeric_limits<double>::infinity());
			this->setF(static_cast<float>(this->getD()));
		}
	}
	catch (std::bad_cast &bc) {
		std::cout << bc.what();
	}
}

void	ScalarConverter::convert(void) {
		
	t_type type = this->_findType();
	
	if (type == INVALID) {
		std::cout << "Value cannot be converted!" << std::endl;
		return;
	}

	std::stringstream s;
	
	(this->*_convert[type])();
			
	s << display(this->getC(), this->getIsPossible());
	s << display(this->getI(), this->getIsPossible());
	s << display(this->getF(), this->getIsNegative());
	s << display(this->getD(), this->getIsNegative());
		
	std::cout << s.str();
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT STREAM OVERLOAD::

std::ostream &operator<<(std::ostream &o, ScalarConverter const &s) {

	o << s.getStr();
	o << s.getC();
	o << s.getI();
	o << s.getF();
	o << s.getD();
	return (o);
}