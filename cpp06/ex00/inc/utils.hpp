/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:19:09 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/30 16:42:17 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iomanip>
# include <cxxabi.h>
# include <string>
# include <sstream>
# include <cstdlib>
# include <limits>

typedef struct s_handle {

	char* p;
	s_handle(char* ptr) : p(ptr) {}
	~s_handle() { free(p); }
} 	t_handle;

std::string		demangle(const char *name);
std::string		display(char c, bool isPossible);
std::string		display(int i, bool isPossible);
std::string		display(float f, bool isNegative);
std::string		display(double d, bool isNegative);

#endif