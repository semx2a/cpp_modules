/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/04 20:50:26 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat(void);
        Cat(std::string const);
        Cat(Cat const & src);
        ~Cat(void);
        
		Cat &	operator=(Cat const & rhs);
		
		void	makeSound(void) const;

};

std::ostream &  operator<<(std::ostream & o, Cat const & c);

#endif