/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:01:59 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 16:10:45 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) : AForm(src) { *this = src; }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src) {
	
	if (this != &src) {
		
		this->setTarget(src.getTarget());
	}
	return (*this);
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ACCESSORS::

void 					ShrubberyCreationForm::setTarget(std::string target) { this->_target = target; }

const std::string &		ShrubberyCreationForm::getTarget() const { return (this->_target); }

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::

void					ShrubberyCreationForm::_makeTree(std::stringstream & fileContent) const {
	
		fileContent << std::endl;
		fileContent << "              * *           	" << std::endl;
		fileContent << "            *    *  *			" << std::endl;
		fileContent << "       *  *    *     *  *		" << std::endl;
		fileContent << "      *     *    *  *    *		" << std::endl;
		fileContent << "  * *   *    *    *    *   *	" << std::endl;
		fileContent << "  *     *  *    * * .#  *   *	" << std::endl;
		fileContent << "  *   *     * #.  .# *   *		" << std::endl;
		fileContent << "   *     \"#.  #: #\" * *    *	" << std::endl;
		fileContent << "  *   * * \"#. ##\"       *		" << std::endl;
		fileContent << "    *       \"###				" << std::endl;
		fileContent << "              \"##				" << std::endl;
		fileContent << "               ##.				" << std::endl;
		fileContent << "               .##:				" << std::endl;
		fileContent << "               :###				" << std::endl;
		fileContent << "               ;###				" << std::endl;
		fileContent << "             ,####.				" << std::endl;
		fileContent << "////////////.######.////////////" << std::endl;

}

void					ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	
	AForm::execute(executor);
	std::string			fileName(this->getTarget() + "_shrubbery");
	std::stringstream	fileContent;
	std::fstream		fs(fileName.c_str(), std::ios::out | std::ios::trunc);
	
	this->_makeTree(fileContent);
	fs << fileContent.str();
	fs.close();
	
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}
