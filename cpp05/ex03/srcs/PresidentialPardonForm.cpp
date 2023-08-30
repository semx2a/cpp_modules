/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:02:05 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 16:08:49 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("criminal") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src) { *this = src; }

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& src) {
	
	if (this != &src) {
		
		this->setTarget(src.getTarget());
	}
	return (*this);
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void 				PresidentialPardonForm::setTarget(std::string target) {	this->_target = target; }

const std::string &	PresidentialPardonForm::getTarget() const {	return (this->_target); }

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::

void				PresidentialPardonForm::execute(Bureaucrat const& executor) const {

	AForm::execute(executor);
	std::cout << "Zaphod Beeblebrox pardons " << this->getTarget() << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}
