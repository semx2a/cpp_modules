/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:42:52 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/08 16:43:04 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

#define RANDOM 	((rand() % 150) + 1)

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Form::Form(void) : 
_name("Undefined Form"), 
_isSigned(false), 
_signGrade(this->checkGrade(RANDOM)), 
_execGrade(this->checkGrade(RANDOM)) {}

Form::Form(std::string name) : 
_name(name),
_isSigned(false),
_signGrade(this->checkGrade(RANDOM)),
_execGrade(this->checkGrade(RANDOM)) {}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade) :
_name(name),
_isSigned(false),
_signGrade(this->checkGrade(signGrade)),
_execGrade(this->checkGrade(execGrade)) {}

Form::Form(Form const & src) : _signGrade(), _execGrade() { *this = src; }

Form::~Form(void) { }

Form &	Form::operator=(Form const & rhs) {

	if (this != &rhs) {

		std::cerr << ORANGE << std::endl;
		std::cerr << "Warning: Form operator= called" << std::endl;
		std::cerr << "Cannot assign Form a name: const value" << std::endl;
		std::cerr << "Cannot assign Form a signGrade: const value" << std::endl;
		std::cerr << "Cannot assign Form a execGrade: const value" << std::endl;	
		std::cerr << RESET << std::endl;
		this->setIsSigned(rhs.getIsSigned());
	}
	return *this;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void			Form::setIsSigned(bool const isSigned) { this->_isSigned = isSigned; }

std::string		Form::getName(void) const {	return this->_name; }

bool			Form::getIsSigned(void) const {	return this->_isSigned; }

unsigned int	Form::getSignGrade(void) const { return this->_signGrade; }

unsigned int	Form::getExecGrade(void) const { return this->_execGrade; }

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

unsigned int	Form::checkGrade(const int grade) {
	
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	else if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	return grade;
}

void			Form::beSigned(Bureaucrat const & bureaucrat) {

	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooHighException();
	else
		this->setIsSigned(true);
}


std::string		Form::announce(void) const {

	std::string 		str;
	std::stringstream 	sstream;

	sstream << "Form "
	<< GREEN
	<< this->getName() 
	<< RESET
	<< ", can be signed by Bureacrats with grade " 
	<< GREEN
	<< this->getSignGrade()
	<< RESET
	<< " and can be executed by Bureaucrats with grade " 
	<< GREEN
	<< this->getExecGrade()
	<< RESET;
	str = sstream.str();

	return str;
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: EXCEPTIONS::

const char *	Form::GradeTooHighException::what() const throw() {

	return "Form's grade is too high!";
}

const char *	Form::GradeTooLowException::what() const throw() {

	return "Form's grade is too low!";
}

const char *	Form::FormNotSignedException::what() const throw() {

	return "Form is not signed!";
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &	operator<<(std::ostream & o, Form const & f) {
	
	return o << f.announce();
} 