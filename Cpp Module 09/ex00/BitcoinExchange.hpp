#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>

class BitcoinExchange {
private:
    std::map<std::string, double> prices;
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& pricesFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void parseBitcoinPrices(const std::string& filename);
    void processUserInput(const std::string& filename);
};

bool isValidDate(const std::string& date);

#endif // BITCOINEXCHANGE_HPP
