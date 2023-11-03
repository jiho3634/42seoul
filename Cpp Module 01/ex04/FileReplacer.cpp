#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

void FileReplacer::replaceAndSave() {
    std::ifstream input(filename.c_str());
    if (!input.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream output(outputFilename.c_str());
    if (!output.is_open()) {
        std::cerr << "Error: Cannot create output file " << outputFilename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        output << line << '\n';
    }

    input.close();
    output.close();

    std::cout << "File '" << filename << "' copied to '" << outputFilename << "', replacing '" << s1 << "' with '" << s2 << "'." << std::endl;
}

