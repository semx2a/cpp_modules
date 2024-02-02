/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 17:20:15 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# define NO_COLOR	"\033[m"
# define BHIGREEN	"\033[1;92m"
# define BHIORANGE	"\033[1;93m"
# define BHIBLUE	"\033[1;94m"
# define BHIPURPLE	"\033[1;95m"

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