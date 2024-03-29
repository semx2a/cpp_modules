/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/08 16:43:04 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"
# define RESET	"\033[m"
# define BHIGREEN	"\033[1;92m"
# define BHIORANGE	"\033[1;93m"
# define BHIBLUE	"\033[1;94m"
# define BHIPURPLE	"\033[1;95m"

class Dog : public AAnimal {

	public:
		Dog(void);
        Dog(std::string const);
        Dog(Dog const & src);
        ~Dog(void);
        
		Dog &	operator=(Dog const & rhs);
		
		void	setBrain(Brain* const);

		Brain*	getBrain(void) const;
		
		void	makeSound(void) const;

	private:
		Brain*	_noggin;

};

std::ostream &  operator<<(std::ostream & o, Dog const & d);

#endif