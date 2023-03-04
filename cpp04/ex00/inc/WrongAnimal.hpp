/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/04 20:47:31 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class WrongAnimal {

	public:
		WrongAnimal(void);
        WrongAnimal(std::string const);
        WrongAnimal(WrongAnimal const & src);
        virtual ~WrongAnimal(void);
        
		WrongAnimal &	operator=(WrongAnimal const & rhs);
		                
		void		setType(std::string const);
		
		std::string	getType(void) const;

		void		makeSound(void) const;
	
	private:
		std::string	_type;
};

std::ostream &  operator<<(std::ostream & o, WrongAnimal const & wa);

#endif