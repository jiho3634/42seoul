#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	std::cout << "accounts:" << _nbAccounts << ";";
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	std::cout << "total:" << _totalAmount << ";";
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	std::cout << "deposits:" << _totalNbDeposits;
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ) {
	std::cout << "[19920104_091532] ";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	getNbAccounts();
	getTotalAmount();
	getNbDeposits();
	std::cout << ";";
	getNbWithdrawals();
	std::cout << std::endl;
}

int	Account::checkAmount( void ) const {
	std::cout << "amount:" << _amount << ";";
	return _amount;
}

void	Account::makeDeposit( int deposit ) {
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_";
	checkAmount();
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	checkAmount();
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_";
	checkAmount();
	std::cout << "withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	checkAmount();
	std::cout << "nb_withdrawals: " <<_nbWithdrawals << std::endl;
	return true;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	checkAmount();
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )	: _accountIndex(_nbAccounts), _amount(initial_deposit) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	checkAmount();
	std::cout << "created" << std:: endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	checkAmount();
	std::cout << "closed" << std:: endl;
}
