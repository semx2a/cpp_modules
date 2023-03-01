/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:51:54 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/27 19:51:47 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	public:
	
		Fixed(void);
		Fixed(Fixed const & src );
		Fixed(int const val);
		Fixed(float const val);
		~Fixed(void);
		
		Fixed &				operator=(Fixed const & rhs);

		int					getRawBits(void) const;
	
		void				setRawBits(int const raw);
	
		float				toFloat(void) const;
		int					toInt(void) const;
		
	private:
		
		int					_val;
		static int const	_fractionalBits = 8;
};

std::ostream &				operator<<(std::ostream & o, Fixed const & i);

#endif
