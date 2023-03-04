/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/04 20:50:22 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {

	public:
		Animal(void);
        Animal(std::string const);
        Animal(Animal const & src);
        virtual ~Animal(void);
        
		Animal &	operator=(Animal const & rhs);
		                
		void		setType(std::string const);
		
		std::string	getType(void) const;

		virtual void	makeSound(void) const;
	
	private:
		std::string	_type;
};

std::ostream &  operator<<(std::ostream & o, Animal const & a);

#endif