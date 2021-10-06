#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>


struct data_point {
	int x;
	int y;
};

std::vector<data_point*> data_read_txt(std::string path) {
	std::ifstream file_open(path, std::ios::binary);
	std::string output;
	std::vector<int> output_vec;
	std::vector<data_point*> data_vec;

	int pos = 0;

	if (!file_open.is_open()) {
		std::cout << "Error opening file." << std::endl;
	}

	while (std::getline(file_open, output)) {
		output_vec.push_back(stoi(output));
	}

	for (int i = 0; i < output_vec.size() / 2; i++) {
		data_vec.push_back(new data_point);
		data_vec.at(i)->x = output_vec.at(pos);
		data_vec.at(i)->y = output_vec.at(pos+1);
		pos += 2;
	}


	return data_vec;

}

void main() {
	int columns = 200;
	int rows = 50;

	std::vector<data_point*> data_table = data_read_txt("test.txt");
	std::vector<std::string*> row_table;


	for (int i = 0; i < rows; i++){
		row_table.push_back(new std::string);
		for (int p = 0; p < columns; p++) {
			
			row_table.at(i)->push_back(' ');
		}
	}

	for (int i = 0; i < data_table.size(); i++) {
		int x = data_table.at(i)->x;
		int y = data_table.at(i)->y;

		row_table.at(y)->at(x) = 'X';
	}

	for (int i = 49; i>-1; i--) {
		std::cout << *row_table.at(i) << '\n';
	}


	//cleanup
	for (int i = 0; i < row_table.size(); i++) {
		delete(row_table.at(i));
	}

	for (int i = 0; i < data_table.size(); i++) {
		delete(data_table.at(i));
	}

}