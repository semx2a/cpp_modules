/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:27:11 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/08 16:43:04 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

#define RANDOM 	((rand() % 150) + 1)

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

AForm::AForm(void) : 
_name("Undefined AForm"), 
_isSigned(false), 
_signGrade(this->checkGrade(RANDOM)), 
_execGrade(this->checkGrade(RANDOM)) {}

AForm::AForm(std::string name) : 
_name(name),
_isSigned(false),
_signGrade(this->checkGrade(RANDOM)),
_execGrade(this->checkGrade(RANDOM)) {}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int execGrade) :
_name(name),
_isSigned(false),
_signGrade(this->checkGrade(signGrade)),
_execGrade(this->checkGrade(execGrade)) {}

AForm::AForm(AForm const & src) : _signGrade(), _execGrade() { *this = src; }

AForm::~AForm(void) { }

AForm &	AForm::operator=(AForm const & rhs) {

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

void				AForm::setIsSigned(bool const isSigned) { this->_isSigned = isSigned; }

const std::string &	AForm::getName(void) const {	return this->_name; }

bool				AForm::getIsSigned(void) const {	return this->_isSigned; }

unsigned int		AForm::getSignGrade(void) const { return this->_signGrade; }

unsigned int		AForm::getExecGrade(void) const { return this->_execGrade; }

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MEMBER FUNCTIONS::

unsigned int	AForm::checkGrade(const int grade) {
	
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	else if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	return grade;
}

void			AForm::execute(Bureaucrat const & executor) const {
	
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooHighException();
}

void			AForm::beSigned(Bureaucrat const & bureaucrat) {

	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooHighException();
	else
		this->setIsSigned(true);
}

std::string		AForm::announce(void) const {

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

const char *	AForm::GradeTooHighException::what() const throw() {

	return "Form's grade is too high!";
}

const char *	AForm::GradeTooLowException::what() const throw() {

	return "Form's grade is too low!";
}

const char *	AForm::FormNotSignedException::what() const throw() {

	return "Form is not signed!";
}

// ::::::::::::::::::::::::::::::::::::::::::::::: OUTPUT OPERATOR OVERLOADING::

std::ostream &	operator<<(std::ostream & o, AForm const & af) {
	
	return o << af.announce();
}
