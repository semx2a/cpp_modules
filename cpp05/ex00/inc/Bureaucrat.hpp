/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:03:01 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 16:33:38 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <exception>
# include <sstream>
# include <cstdlib>

# include "Display.hpp"

# define LOWEST_GRADE	150
# define HIGHEST_GRADE	1

class Bureaucrat {

	public:
		
		Bureaucrat(void);
		Bureaucrat(std::string);
		Bureaucrat(std::string, unsigned int);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		Bureaucrat &	operator=(Bureaucrat const & rhs);

		Bureaucrat &	operator++(void);
		Bureaucrat 		operator++(int);
		Bureaucrat &	operator--(void);
		Bureaucrat 		operator--(int);
		
		const std::string &	getName(void) const;
		unsigned int		getGrade(void) const;
		
		void				setGrade(unsigned int);

		void				upperEchelon( void );
		void				lowerEchelon( void );
		unsigned int		checkGrade(const int);
		std::string			announce(void) const;

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		
		const std::string 	_name;
		unsigned int		_grade;		
	
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & b);

#endif
