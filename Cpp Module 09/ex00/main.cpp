#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input.txt>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string pricesFile = "data.csv"; // 비트코인 가격 데이터 파일 경로

    BitcoinExchange exchange(pricesFile);
    exchange.processUserInput(inputFile);

    return 0;
}
