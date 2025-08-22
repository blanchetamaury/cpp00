/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:18:57 by amblanch          #+#    #+#             */
/*   Updated: 2025/08/21 14:40:35 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += _amount;
    _accountIndex = _nbAccounts;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    _nbAccounts++;

}

Account::~Account(void) {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    _nbAccounts--;
    return ;
}

void Account::_displayTimestamp() {
    time_t timestamp = time(0);
    struct tm *datetime;

    datetime = localtime(&timestamp);
    std::cout << "[" << datetime->tm_year + 1900 \
                << std::setfill('0') << std::setw(2) << datetime->tm_mon + 1 \
                << std::setfill('0') << std::setw(2) << datetime->tm_mday \
                << "_" \
                << std::setfill('0') << std::setw(2) << datetime->tm_hour \
                << std::setfill('0') << std::setw(2) << datetime->tm_min \
                << std::setfill('0') << std::setw(2) << datetime->tm_sec \
                << "] ";
}

int Account::getNbAccounts(void) {
    return (_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (_totalAmount);
}

int Account::getNbDeposits(void) {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
    int p_amount;

    _totalNbDeposits++;
    _nbDeposits++;
    p_amount = _amount;
    _amount += deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl; 
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (_amount - withdrawal < 0)
    {
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << "refused" << std::endl;
        return (false);
    }
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << (_amount - withdrawal) << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    return (true);
}

int Account::checkAmount(void) const {
    std::cout << "checkamount : " << _amount << "  (checkAmount)" << std::endl;
    return (_amount);
}

void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}