/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:33:46 by amaury            #+#    #+#             */
/*   Updated: 2025/08/22 14:37:58 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
    public:
        PhoneBook();
        void loop(void);
        void add(void);
        void search(void);
        void printPhoneBook(void);
        std::string goodEntry(std::string word);
        std::string formatArray(std::string word);
    private:
        Contact array[8];
        int index;
        int display;
        std::string entry;
};

#endif