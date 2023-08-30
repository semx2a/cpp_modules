/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:01:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 14:59:10 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
	public:
		
		RobotomyRequestForm();
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		~RobotomyRequestForm();
		
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& src);
		
		const std::string &		getTarget() const;
		void 					setTarget(std::string);

		virtual void			execute(Bureaucrat const&) const;

		class RobotomyFailed : public std::exception {
			virtual const char* what() const throw() {
				return ("Robotomy failed!");
			}
		};
	
	private:
		std::string	_target;
};

#endif