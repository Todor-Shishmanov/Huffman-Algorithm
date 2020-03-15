#include<iostream>
#include <fstream>
#include "Algorithm.h"
using namespace std;

int main() {
	//adding some sort of interface
	char answer;
	bool check = 0;
	string message;
	vector<short> ASCII_message;
	//get the message from a file or user
	while (!check) {
		cout << "Would you like to code from a file? Enter y or n:" << endl;
		cin >> answer;
		if (answer == 'y') {
			string file_location;
			cout << "Enter file location:";
			cin >> file_location;
			fstream get_message(file_location, fstream::in);
			if (!get_message) std::cerr << "Could not open the file!" << std::endl;
			else
			{
				getline(get_message, message, '\0');
				get_message.close();
				check = 1;
			}
		}
		else if (answer == 'n') {
			cout << "Enter message:" << endl;
			cin >> message;
			check = 1;
		}
		else {
			check = 0;
		}
	}

	//create the table and the tree
	int message_size = message.size();
	for (int i = 0; i < message_size; i++) {
		ASCII_message.push_back((short)message[i]);
	}
	FreqTable frequency_table(ASCII_message);
	Algorithm huffman_algorithm(frequency_table);
	cout << "Want to code the original message(1), or decode one that has already been coded via huffman algorithm(2)? Please enter '1' or '2':" << endl;
	check = 0;

	while (!check) {
		cin >> answer;
		if (answer == '1') {
			string code="";
			huffman_algorithm.Algorithm_code(huffman_algorithm.top_element(), code);
			huffman_algorithm.print_the_code(ASCII_message);
			check = 1;
		}
		else if (answer == '2') {
			string decode_message;
			cout << "Enter the coded message:";
			cin >> decode_message;
			huffman_algorithm.Algorithm_decode(huffman_algorithm.top_element(), decode_message);
			check = 1;
		}
		else {
			cout << "Please enter '1' or '2':";
			check = 0;
		}
	}
	system("pause");
	return 0;
}