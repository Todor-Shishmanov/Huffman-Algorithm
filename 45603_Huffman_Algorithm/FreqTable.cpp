#include "FreqTable.h"
#include <iostream>




FreqTable::FreqTable(std::vector<short> input) {

	const int n = input.size();
	bool alreadyIn = 0;

	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < table_letters.size(); j++) {
			if (input[i] == table_letters[j]) {
				table_freq[j]++;
				alreadyIn = 1;
			}
		}
		if (!alreadyIn) {
			table_letters.push_back(input[i]);
			table_freq.push_back(1);
		}
		alreadyIn = 0;
	}
	size = table_freq.size();
}

void FreqTable::print() {
	int size = table_letters.size();
	std::cout << "Letter:               Frequency:" << std::endl;
	for (size_t i = 0; i < size; i++) {
		std::cout << "   " << table_letters[i] << "                        " << table_freq[i] << std::endl;
	}
}

int FreqTable::get_size()
{
	return size;
}

int FreqTable::get_letter(int place_in_table_letter)
{
	return table_letters[place_in_table_letter];
}

int FreqTable::get_freq(int place_in_table)
{
	return table_freq[place_in_table];
}