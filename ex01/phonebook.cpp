/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:45:54 by amaury            #+#    #+#             */
/*   Updated: 2025/08/22 14:44:40 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string PhoneBook::formatArray(std::string word) {
    if (word.length() > 10)
        return word.substr(0, 9) + ".";
    return word;
}

void PhoneBook::printPhoneBook(void) {
    std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|index     |first name|last name |nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < display; i++) {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << PhoneBook::formatArray(array[i].getName());
        std::cout << "|" << std::setw(10) << PhoneBook::formatArray(array[i].getLastName());
        std::cout << "|" << std::setw(10) << PhoneBook::formatArray(array[i].getNickname());
        std::cout << "|" << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
    }
}

void PhoneBook::add(void) {
    array[index].setName(PhoneBook::goodEntry("Name : "));
    array[index].setLastName(PhoneBook::goodEntry("Last Name : "));
    array[index].setNickname(PhoneBook::goodEntry("Nickname : "));
    array[index].setPhoneNumber(PhoneBook::goodEntry("Phone Number : "));
    array[index].setDarkestSecret(PhoneBook::goodEntry("Darkest Secret : "));
    index++;
    if (display < 8)
        display++;
    if (index == 8) index = 0;
}

void PhoneBook::search(void) {
    int i;
    PhoneBook::printPhoneBook();
    PhoneBook::goodEntry("Index : ");
    i = std::atoi(entry.c_str());
    if (entry.size() == 1 && i < display && i >= 0) array[i].printContact();
    else std::cout << "Contact not found" << std::endl;
}

std::string PhoneBook::goodEntry(std::string word) {
    while (1) {
        std::cout << word;
        std::getline(std::cin, entry);
        if (entry.size() != 0 ) return entry;
        if (!std::cin) exit (1);
    }
}

void PhoneBook::loop(void) {
    void (PhoneBook::*fct[2])(void) = {&PhoneBook::add, &PhoneBook::search};
    while (1) {
        PhoneBook::goodEntry("Action : ");
        if (entry == "ADD") (this->*fct[0])();
        if (entry == "SEARCH") (this->*fct[1])();
        if (entry == "EXIT" || !std::cin) break;
    }
}

PhoneBook::PhoneBook(void) {
    index = 0;
    entry = "";
    display = 0;
}