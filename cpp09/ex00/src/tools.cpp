/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:38:57 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 00:30:26 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.hpp"

bool isLeapYear(int year) {
    
	if (year % 4 == 0) {
    
	   if (year % 100 == 0) {
          // year is divisible by 400, hence the year is a leap year
          if (year % 400 == 0)
             return true;
          else
             return false;
       }
       else
          return true;
    }
    else
      return false;
}

bool isValidDate(int day, int month, int year) {
    
	// Check the validity of year and month
    if (year < 1000 || year > 3000 || month < 1 || month > 12)
        return false;
    
    // Days of each month
    int monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // If it is leap year, set February's days to 29
    if (month == 2 && isLeapYear(year))
        monthLength[1] = 29;
    
    // Check the validity of day
    return day > 0 && day <= monthLength[month - 1];
}

int convertToCents(std::string value) {
    
    std::istringstream iss(value);
    float amount;
    iss >> amount;
    
    std::cout << "amount: " << amount << std::endl;
    int cents = static_cast<int>(amount * 100);
    std::cout << "cents: " << cents << std::endl;
    return cents;
}