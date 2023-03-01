/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:11:32 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/16 21:45:15 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_H
# define CONTACTS_H

# include "PhoneBook.hpp"

class Contacts {
	
public:
	
	Contacts (void);
	~Contacts (void);
	
	void		setData (void);
	void		setFields (void);
	
	static int	getNbInst (void);
	int			getIndex (void) const;
	std::string	getField (int)	const;
	std::string	getData (int)	const;

private:
	
	static int		_nbInst;
	int				_index;
	std::string		_field[5];
	std::string		_data[5];
};

typedef enum e_fields {
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NB,
	SECRET
}	t_fields;

#endif
