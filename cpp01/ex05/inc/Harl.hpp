/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:33:20 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/22 21:09:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

typedef enum e_levels {
	
	DEBUG,
	INFO,
	WARNING,
	ERROR
}	t_levels;

class	Harl;

typedef struct s_complain {
	
	std::string	level;
	void		(Harl::*lvl_ptr)(void);
}	t_complain;

class Harl {

public:
	
	Harl ( void );
	~Harl ( void );

	void		complain ( std::string level );

private:

	void		debug ( void );
	void		info ( void );
	void		warning ( void );
	void		error ( void );
	t_complain	list[4];
	
};

#endif
