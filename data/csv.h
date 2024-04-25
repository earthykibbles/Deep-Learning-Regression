#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <variant>

namespace CSV {
	int columns;
	int rows;

	// Function to split a string into tokens based on a delimiter
	std::vector<std::variant<float, std::string>> split(const std::string& s, char delimiter) {
		std::vector<std::variant<float,std::string>> tokens;
		std::stringstream ss(s);
		std::variant<float, std::string> token;
		while (getline(ss, token, delimiter)) {
			tokens.push_back(token);
		}
		return tokens;
	}


	std::vector<std::vector<float>> readCsv(std::string filename, bool hasHeader) {
		// Open a CSV file for writing
		std::ofstream csvFile(filename);
		// Check if the file opened successfully
		if (!csvFile.is_open()) {
			std::cerr << "Failed to open file." << std::endl;
		}

		if (hasHeader) {
			readHeader();
			std::string line;
			while (getline(csvFile, line)) {
				std::vector<float> columns = split(line, ',');
				if (columns.size() != 5) {
					std::cerr << "Error: Number of columns is not five!" << std::endl;
					continue; // Skip this line and proceed to the next one
				}
			}

			
			

		}
		else {

		}
		csvFile.close();
	}

	// Read the First Row as the Header and store it in a vector of strings
	std::vector<std::string> readHeader() {

	}
};