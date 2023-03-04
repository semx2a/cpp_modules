/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 00:41:39 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal {

	public:
		AAnimal(void);
        AAnimal(std::string const);
        AAnimal(AAnimal const & src);
        virtual ~AAnimal(void);
        
		AAnimal &	operator=(AAnimal const & rhs);
		                
		void		setType(std::string const);
		
		std::string	getType(void) const;

		virtual void	makeSound(void) const = 0;
	
	protected:
		std::string	_type;
};

std::ostream &  operator<<(std::ostream & o, AAnimal const & a);

#endif