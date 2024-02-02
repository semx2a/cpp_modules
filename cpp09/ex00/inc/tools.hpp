/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:38:26 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 00:07:53 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP

# include <iostream>
# include <cmath>
# include <string>
# include <sstream>

bool	isValidDate(int day, int month, int year);
int		convertToCents(std::string value);

#endif