/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 16:59:40 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# define NO_COLOR	"\033[m"
# define BHIGREEN	"\033[1;92m"
# define BHIORANGE	"\033[1;93m"
# define BHIBLUE	"\033[1;94m"
# define BHIPURPLE	"\033[1;95m"

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
	
	protected:
		std::string	_type;
};

std::ostream &  operator<<(std::ostream & o, Animal const & a);

#endif