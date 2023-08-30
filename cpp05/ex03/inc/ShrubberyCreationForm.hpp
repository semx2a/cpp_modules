/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:01:41 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 14:59:14 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& src);
		
		const std::string &		getTarget() const;
		void 					setTarget(std::string);
		
		virtual void			execute(Bureaucrat const&) const;
	
	private:
		std::string	_target;
		void		_makeTree(std::stringstream&) const;
};

#endif