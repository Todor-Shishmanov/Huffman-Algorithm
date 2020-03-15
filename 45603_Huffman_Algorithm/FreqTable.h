#pragma once
#include<vector>
class FreqTable
{
private:
	std::vector<int> table_freq;
	std::vector<int> table_letters;
	int size;
public:
	FreqTable() {
		table_freq = {};
		table_letters = {};
		size = 0;
	}
	FreqTable(std::vector<short>);

	void print();
	int get_size();
	int get_letter(int place_in_table);
	int get_freq(int place_in_table);
};
