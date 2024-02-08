/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:02:05 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/08 16:43:04 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

#define RANDOM 	((rand() % 150) + 1)

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Bureaucrat::Bureaucrat(void) : _name("John Doe"), _grade(this->checkGrade(RANDOM)) { }

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(this->checkGrade(RANDOM)) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(this->checkGrade(grade)) {}

Bureaucrat::Bureaucrat(Bureaucrat const & src) { *this = src; }

Bureaucrat::~Bureaucrat(void) { }

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs) {

	if (this != &rhs) {
		
		std::cerr << ORANGE << std::endl;
		std::cerr << "Warning: Bureaucrat operator= called" << std::endl;
		std::cerr << "Cannot assign Bureaucrat a name: const value" << std::endl;
		std::cerr << RESET << std::endl;
		this->setGrade(rhs.getGrade());
	}
	
	return *this;
}

// ::::::::::::::::::::::::::::: INCREMENT AND DECREMENT OPERATOR OVERLOADING ::

// PREFIX INCREMENT
Bureaucrat&			Bureaucrat::operator++(void) {
	
	this->upperEchelon();
	
	return *this;
}

// POSTFIX INCREMENT
Bureaucrat 			Bureaucrat::operator++(int) {
	
	Bureaucrat	tmp = *this;
	++*this;

	return tmp;	
}

// PREFIX DECREMENT
Bureaucrat&			Bureaucrat::operator--(void) {
	
	this->lowerEchelon();

	return *this;
}

// POSTFIX DECREMENT
Bureaucrat 			Bureaucrat::operator--(int) {
	
	Bureaucrat	tmp = *this;
	--*this;

	return tmp;
}


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

const std::string &	Bureaucrat::getName(void) const { return this->_name; }

unsigned int		Bureaucrat::getGrade(void) const { return this->_grade; }

void				Bureaucrat::setGrade(unsigned int grade) {

	this->checkGrade(grade);
	this->_grade = grade;
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

void			Bureaucrat::upperEchelon() {

	std::cout << this->getName() << " is trying to get promoted!" << std::endl;
	this->setGrade(this->getGrade() - 1); 
}

void			Bureaucrat::lowerEchelon() {

	std::cout << "HR is trying to downgrade " << this->getName() << std::endl;
	this->setGrade(this->getGrade() + 1); 
}

unsigned int	Bureaucrat::checkGrade(const int grade) {
	
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	else if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	return grade;
}

void			Bureaucrat::signForm(AForm & form) {
	
	try {

		form.beSigned(*this);
		std::clog << "Bureaucrat " << ORANGE << this->getName() << RESET
		<< " signed Form " << ORANGE << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e) {

		std::stringstream sstream;

		sstream << this->getName() 
		<< " couldn't sign Form " << form.getName() << " because " 
		<< e.what() << std::endl;

		std::cerr << sstream.str();
	}
}

void			Bureaucrat::executeForm(const AForm & form) {
	
	try {
		form.execute(*this);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
}

std::string	Bureaucrat::announce(void) const {

	std::string			str;
	std::stringstream	iss;
	
	iss << this->getName() << ", bureaucrat grade " << this->getGrade();
	str.append(iss.str());
	
	return str;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: EXCEPTIONS::

const char*		Bureaucrat::GradeTooHighException::what() const throw() {

	return "The grade you're trying to assign is too high!";
}

const char*		Bureaucrat::GradeTooLowException::what() const throw() {

	return "The grade you're trying to asssign is too low!";
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & b) {
	
	return o << b.announce();
} 