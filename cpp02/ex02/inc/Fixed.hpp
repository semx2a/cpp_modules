/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:51:54 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/03 12:30:21 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const val);
		Fixed(float const val);
		~Fixed(void);
		
		Fixed &				operator=(Fixed const & rhs);
		Fixed 				operator+(Fixed const & rhs) const;
		Fixed 				operator-(Fixed const & rhs) const;
		Fixed 				operator*(Fixed const & rhs) const;
		Fixed 				operator/(Fixed const & rhs) const;
		
		bool				operator>(Fixed const & rhs) const;
		bool				operator<(Fixed const & rhs) const;
		bool				operator>=(Fixed const & rhs) const;
		bool				operator<=(Fixed const & rhs) const;
		bool				operator==(Fixed const & rhs) const;
		bool				operator!=(Fixed const & rhs) const;
	
		Fixed&				operator++(void);
		Fixed 				operator++(int);
		Fixed&				operator--(void);
		Fixed 				operator--(int);
		
		int					getRawBits(void) const;
		
		void				setRawBits(int const raw);
		
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		min(Fixed & lhs, Fixed & rhs);
		static Fixed		min(Fixed const & lhs, Fixed const & rhs);
		static Fixed		max(Fixed & lhs, Fixed & rhs);
		static Fixed		max(Fixed const & lhs, Fixed const & rhs);
	
	private:
	
		int					_val;
		static int const	_fractionalBits = 8;
		static int const	_wholeBits = 8;
		static int const	_maxVal = (1 << (_wholeBits + _fractionalBits - 1)) - 1;
		static int const	_minVal = -_maxVal;
};

std::ostream &				operator<<(std::ostream & o, Fixed const & i);

#endif
