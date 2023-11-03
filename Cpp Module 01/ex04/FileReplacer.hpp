#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>

class FileReplacer {
	public:
		FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
		void replaceAndSave();

	private:
		std::string filename;
		std::string s1;
		std::string s2;
};

#endif

