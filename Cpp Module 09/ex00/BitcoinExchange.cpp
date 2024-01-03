#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& pricesFile) {
    parseBitcoinPrices(pricesFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : prices(other.prices) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->prices = other.prices;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseBitcoinPrices(const std::string& filename) {
    std::ifstream file(filename);//파일 오픈
    std::string line, date;
    double price;

    //파일 오픈 에러 처리
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }
    // 첫 번째 줄 (헤더) 무시
    // 주어진 입력 스트림(file)에서 문자열을 읽어, 두 번째 인자인 line에 저장
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        //콤마를 구분자로 사용하여 날짜를 추출 후 스트림에서 가격을 읽는다
        if (std::getline(ss, date, ',') && (ss >> price)) {
            prices[date] = price;
        }
    }
}

//비트코인의 가치를 계산하고 결과를 출력하는 역할
void BitcoinExchange::processUserInput(const std::string& filename) {
    std::ifstream file(filename);
    std::string line, date;
    double amount;

    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find('|');
        //find 함수는 찾은 문자의 위치를 size_t 타입으로 반환. 
        //만약 문자가 문자열에 없다면, std::string::npos라는 값을 반환. 
        //이 상수 값은 문자열의 끝을 넘어선 위치를 나타낸다.
        if (delimiterPos != std::string::npos) {
            date = line.substr(0, delimiterPos);
            date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
            //std::remove 함수는 date 문자열에서 모든 공백(' ')을 찾아 문자열의 끝으로 이동시킨다.
            //공백 이후의 첫 번째 위치를 가리키는 반복자를 반환. 문자열의 길이를 변경하지 않는다.
            //erase는 std::remove 함수로부터 반환된 반복자부터 문자열의 끝까지 모든 문자를 제거.

            if (!isValidDate(date)) {
                    std::cerr << "Error: invalid date format => " << date << std::endl;
                    continue;
            }

            std::string valueStr = line.substr(delimiterPos + 1);
            valueStr.erase(std::remove(valueStr.begin(), valueStr.end(), ' '), valueStr.end());

            std::stringstream valueSS(valueStr);
            if (!(valueSS >> amount)) {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }

            if (amount <= 0) {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }

            if (amount > 1000) {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }

            //lower_bound 함수는 주어진 키(date)와 같거나 큰 첫 번째 요소를 가리키는 반복자를 반환.
            //만약 date보다 큰 키가 맵에 전혀 없으면, end() 반환. 
            //end()는 맵의 실제 요소를 가리키지 않고, 맵의 끝을 나타내는 반복자.
            std::map<std::string, double>::const_iterator it = prices.lower_bound(date);
            if (it != prices.begin() && (it == prices.end() || it->first != date)) {
                --it; // 이전 날짜로 이동
            }
            //해당하는 데이터가 맵에 없어 begin 이전으로 이동하면. end를 가리키게 된다

            if (it != prices.end()) {
                std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;
            } else {
                std::cout << "Error: no price available for date " << date << std::endl;
            }
        } else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2000 || year > 2023) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    return true;
}