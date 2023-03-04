/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 00:42:41 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {

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