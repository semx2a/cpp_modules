/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:18:33 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/30 17:22:23 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/utils.hpp"


std::string	demangle(const char *name) {
	
	int			status = -4;
	t_handle	result(abi::__cxa_demangle(name, NULL, NULL, &status));
	
	return (status == 0) ? result.p : name;
}

std::string	display(char c, bool isPossible) {

	std::stringstream s;

	s << demangle(typeid(c).name()) << ": ";
	
	if (isPossible == false)
		s << "impossible";
	else if (std::isprint(c) == false)
		s << "Non displayable";
	else
		s << "'" << c << "'";
	
	s << std::endl;
	
	return s.str();
}


std::string display(int i, bool isPossible) {

	std::stringstream s;
	
	s << demangle(typeid(i).name()) << ": ";
	
	if (isPossible == false)
		s << "impossible";
	else if (i <= std::numeric_limits<int>::min() || i >= std::numeric_limits<int>::max())
		s << "Non displayable";
	else
		s << i;
	
	s << std::endl;
	
	return s.str();
}

std::string display(float f, bool isNegative) {

	std::stringstream s;

	s << demangle(typeid(f).name()) << ": " << std::fixed;
	if (isNegative == true)
		f = -f;
	
	if (f == std::numeric_limits<float>::infinity())
		s << std::setprecision(std::numeric_limits<float>::infinity());
	else
		s << std::setprecision(1);

	s << f << "f" << std::endl;
	
	return s.str();
}

std::string display(double d, bool isNegative) {

	std::stringstream s;

	s << demangle(typeid(d).name()) << ": " << std::fixed;
	if (isNegative == true)
		d = -d;
	
	if (d == std::numeric_limits<double>::infinity())
		s << std::setprecision(std::numeric_limits<double>::infinity());
	else
		s << std::setprecision(1);

	s << d << std::endl;
	
	return s.str();
}

