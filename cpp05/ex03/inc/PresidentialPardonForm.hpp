/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:01:31 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 14:59:20 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
	public:
		
		PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		~PresidentialPardonForm();
		
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& src);

		const std::string &		getTarget() const;
		void 					setTarget(std::string);
		
		virtual void			execute(Bureaucrat const&) const;
	
	private:
		std::string	_target;
};

#endif