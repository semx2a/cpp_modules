/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:10:39 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/23 19:01:57 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

Intern::Intern(void) {

	setList();	
}

Intern::Intern(Intern const& src) { *this = src; }

Intern::~Intern() {}

Intern &	Intern::operator=(Intern const& rhs) {

	if (this != &rhs) {
		(void)rhs;
	}
	return (*this);
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void		Intern::setList(void) {

	this->_list[PRESIDENTIAL_PARDON].name = "presidential pardon";
	this->_list[PRESIDENTIAL_PARDON].ptr = &Intern::_makePresidentialPardonForm;
	this->_list[ROBOTOMY_REQUEST].name = "robotomy request";
	this->_list[ROBOTOMY_REQUEST].ptr = &Intern::_makeRobotomyRequestForm;
	this->_list[SHRUBBERY_CREATION].name = "shrubbery creation";
	this->_list[SHRUBBERY_CREATION].ptr = &Intern::_makeShrubberyCreationForm;
}

t_lookup const &	Intern::getList(int key) const { return (this->_list[key]); }

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::

AForm *		Intern::_makePresidentialPardonForm(std::string const & target) {
	
	return (new PresidentialPardonForm(target));
}

AForm *		Intern::_makeRobotomyRequestForm(std::string const & target) {
	
	return (new RobotomyRequestForm(target));
}

AForm *		Intern::_makeShrubberyCreationForm(std::string const & target) {
	
	return (new ShrubberyCreationForm(target));
}

AForm *		Intern::makeForm(std::string const & formName, std::string const & target) {
	
	int i = 0;
	
	for (; i < 3; i++)
		if (this->getList(i).name == formName)
			break;
	if (i == 3)
		throw Intern::UndefinedForm();
	return (this->*getList(i).ptr)(target);
}
