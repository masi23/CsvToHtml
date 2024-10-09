#include <iostream>
#include <string>
#include <fstream>
#include <vector>


std::vector<std::string> split(const std::string& text) {
	std::vector<std::string> result;
	size_t start = 0;
	size_t end = text.find(",");

	while (end != std::string::npos) {
		if (text.at(end + 1) != ' ') {
			result.push_back(text.substr(start, end - start));
			start = end + 1;
		}
		else {
			end = text.find(',', end + 1);
			continue;
		}
		end = text.find(",", start);
	}

	result.push_back(text.substr(start));
	return result;
}

std::string processWord(std::string& text) {
	size_t start = text.find('"');
	if (start != std::string::npos) {
		size_t end = text.find('"', start);
		return text.substr(start, end - start);
	}
	return text;
}

int main()
{
	std::ifstream readFile("D:/projekty/Nauka C++/Random/CsvToHtml/customers-1000.csv");
	std::ofstream outputFile("D:/projekty/Nauka C++/Random/CsvToHtml/index.html");
	outputFile << "<html><head> <title>Output Data Table</title> <style>" << std::endl; 
	outputFile << "table { font-family: Arial; }" << std::endl;
	outputFile << "table tr:nth-child(odd) { background: lightgray;}" << std::endl;
	outputFile << "</style> </head><body><table>" << std::endl;
	std::string textline;
	bool firstLine = true;
	while (getline(readFile, textline)) {
		outputFile << "<tr>";
		std::vector<std::string> words = split(textline);
		for (auto& word : words) {
			std::cout << word << " ";
			if (firstLine) {
				outputFile << "<th><input type=\"text\" value=\"" << processWord(word) << "\"></th>" << std::endl;
			}
			else {
				outputFile << "<td><input type=\"text\" value=\"" << processWord(word) << "\"></td>" << std::endl;
			}
		}
		if (firstLine) firstLine = false;
		std::cout << std::endl << std::endl;
		outputFile << "</tr>" << std::endl;
	}
	outputFile << "</table></body></html>";
	readFile.close();
	outputFile.close();
}