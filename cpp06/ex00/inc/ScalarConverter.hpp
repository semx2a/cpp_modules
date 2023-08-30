/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:52 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/30 17:45:12 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <ios>
# include <typeinfo>
# include <cstdlib>

# include "utils.hpp"

typedef enum e_type {
	INVALID = -1,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	_NAN,
	INF
}	t_type;

class ScalarConverter
{
	public:
		ScalarConverter(std::string);
		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &s);

		const std::string &	getStr(void) const;
		char				getC(void) const;
		int					getI(void) const;
		float				getF(void) const;
		double				getD(void) const;
		bool				getIsPossible(void) const;
		bool				getIsNegative(void) const;
		
		void				setStr(const std::string);
		void				setC(const char);
		void				setI(const int);
		void				setF(const float);
		void				setD(const double);
		void				setIsPossible(const bool);
		void				setIsNegative(const bool);
		void				setConvert(void);
		
		void				convert(void);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &s);
		
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		std::string _str;
		bool		_isPossible;
		bool		_isNegative;
		void		(ScalarConverter::*_convert[6])(void);

		t_type 		_findType(void);
		t_type		_whichNumType(std::string str);
		void		_convertChar(void);
		void		_convertInt(void);
		void		_convertFloat(void);
		void		_convertDouble(void);
		void		_convertNan(void);
		void		_convertInf(void);


};

std::ostream & operator<<(std::ostream &o, ScalarConverter const &s);

#endif