/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:03:01 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 16:40:42 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <exception>
# include <cstdlib>

# include "Bureaucrat.hpp"
# include "Display.hpp"

class Bureaucrat;

class Form {

	public:
		
		Form(void);
		Form(std::string);
		Form(std::string, unsigned int, unsigned int);
		Form(Form const & src);
		~Form(void);

		Form &	operator=(Form const & rhs);
		
		void			setIsSigned(bool const);

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;

		unsigned int	checkGrade(const int);

		void			beSigned(Bureaucrat const &);
				
		std::string		announce(void) const;

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

std::ostream &	operator<<(std::ostream & o, Form const & b);

#endif
