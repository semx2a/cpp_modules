/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:03:01 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 16:41:37 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <exception>
# include <cstdlib>

# include "Bureaucrat.hpp"
# include "Display.hpp"

class Bureaucrat;
class AForm {

	public:

		AForm();
		AForm(std::string);
		AForm(std::string, unsigned int, unsigned int);
		AForm(AForm const & src);
		virtual ~AForm(void);

		AForm &	operator=(AForm const & rhs);

		void				setIsSigned(bool const);

		const std::string &	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;

		unsigned int		checkGrade(const int);

		void				beSigned(Bureaucrat const &);
		virtual void		execute(Bureaucrat const &) const;

		std::string			announce(void) const;

		class GradeTooHighException : public std::exception {
  			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		
		const std::string 	_name;
		bool				_isSigned;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

};

std::ostream &	operator<<(std::ostream & o, AForm const &);

#endif