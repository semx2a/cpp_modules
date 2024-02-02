/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:02:02 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 16:09:52 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src) {	*this = src; }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& src) {
	
	if (this != &src) {
		
		this->setTarget(src.getTarget());
	}
	return (*this);
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void 					RobotomyRequestForm::setTarget(std::string target) { this->_target = target ;}

const std::string &		RobotomyRequestForm::getTarget() const { return (this->_target); }

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::

void					RobotomyRequestForm::execute(Bureaucrat const& executor) const {

	AForm::execute(executor);
	std::cout << "Rizzzzzz" << std::endl;
	std::cout << "R-R-Riizz" << std::endl;
	std::cout << "RiiiIIIZzzzzz" << std::endl;
	
	if ((rand() % 2) == 1)
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	else
		throw RobotomyFailed();
}
