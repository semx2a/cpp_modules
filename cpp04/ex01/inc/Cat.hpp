/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 16:59:53 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

# define NO_COLOR	"\033[m"
# define BHIGREEN	"\033[1;92m"
# define BHIORANGE	"\033[1;93m"
# define BHIBLUE	"\033[1;94m"
# define BHIPURPLE	"\033[1;95m"

class Cat : public Animal {

	public:
		Cat(void);
        Cat(std::string const);
        Cat(Cat const & src);
        ~Cat(void);
        
		Cat &	operator=(Cat const & rhs);
		
		void	setBrain(Brain* const);

		Brain*	getBrain(void) const;
		
		void	makeSound(void) const;
	
	private:
		Brain*	_noggin;
};

std::ostream &  operator<<(std::ostream & o, Cat const & c);

#endif