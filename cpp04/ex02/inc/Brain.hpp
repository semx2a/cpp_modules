/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:20:37 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 17:20:20 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# define NO_COLOR	"\033[m"
# define BHIGREEN	"\033[1;92m"
# define BHIORANGE	"\033[1;93m"
# define BHIBLUE	"\033[1;94m"
# define BHIPURPLE	"\033[1;95m"

class Brain {

	public:
		Brain(void);
        Brain(Brain const & src);
        ~Brain(void);
        
		Brain &	operator=(Brain const & rhs);
		                
		void		setIdeas(std::string* const);
		
		std::string*	getIdeas(void) const;
		
	private:
		std::string*	_ideas;
};

std::ostream &  operator<<(std::ostream & o, Brain const & b);

#endif