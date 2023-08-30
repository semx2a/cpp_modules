/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:01:27 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/23 18:54:25 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>

# include "Display.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

typedef enum e_form {
	
	PRESIDENTIAL_PARDON,
	ROBOTOMY_REQUEST,
	SHRUBBERY_CREATION
}	t_form;

class Intern;

typedef struct s_lookup {
	
	std::string	name;
	AForm *		(Intern::*ptr)(std::string const &);
}	t_lookup;

class Intern {

	public:

		Intern(void);
		Intern(Intern const & intern);
		~Intern();
		
		Intern &	operator=(Intern const & rhs);

		void				setList(void);
		t_lookup const &	getList(int key) const;

		AForm *		makeForm(std::string const &, std::string const & );

		class UndefinedForm : public std::exception {
			virtual const char * what() const throw() {
				return "Undefined form!";
			}
		};

	private:
		
		t_lookup	_list[3];
		AForm *		_makePresidentialPardonForm(std::string const &);
		AForm *		_makeRobotomyRequestForm(std::string const &);
		AForm *		_makeShrubberyCreationForm(std::string const &);
};

#endif