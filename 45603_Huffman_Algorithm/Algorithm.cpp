#include "Algorithm.h"
#include <iostream>


Algorithm::Algorithm(FreqTable table) {

	int table_size = table.get_size();
	Tree*left;
	Tree* right;
	Tree* new_tree;
	for (int i = 0; i < table_size; i++) {
		all_trees.push(new Tree(table.get_freq(i), table.get_letter(i)));
	}

	while (all_trees.size() != 1) {
		left = all_trees.top();
		all_trees.pop();
		right = all_trees.top();
		all_trees.pop();
		new_tree = new Tree(left->get_freq() + right->get_freq(), 256);
		new_tree->set_left_to(left);
		new_tree->set_right_to(right);
		all_trees.push(new_tree); //because i defined it as min heap it will be sorted when pushed
	}
}

void Algorithm::Algorithm_code(Tree* root, std::string code)
{
	if (!root)
		return;

	if (root->get_letter() != 256) {
		std::cout << (char)root->get_letter() << ": " << code << std::endl;
		letters.push_back(root->get_letter());
		coded_letters.push_back(code);
	}
	Algorithm_code(root->left_child(), code + '0');
	Algorithm_code(root->right_child(), code + '1');
}

void Algorithm::print_the_code(std::vector<short> original) {
	int org_size = original.size();
	int letters_size = letters.size();
	std::cout << "Original Message:" << std::endl;

	for (int i = 0; i < org_size; i++) {
		std::cout << (char)original[i];
	}
	std::cout << std::endl << "Coded Message:" << std::endl;
	for (int i = 0; i < org_size; i++) {
		for (int j = 0; j < letters_size; j++) {
			if (original[i] == letters[j]) std::cout << coded_letters[j]; //all the couts are for documentation purposes
		}
	}
	std::cout << std::endl;
}

void Algorithm::Algorithm_decode(Tree * root, std::string coded_message) {
	int size = coded_message.size();
	Tree* iterator = root;
	for (int i = 0; i < size; i++) {
		if (coded_message[i] == '0')
			iterator = iterator->left_child();
		else
			iterator = iterator->right_child();

		if (iterator->get_letter() != 256)
		{
			std::cout << (char)iterator->get_letter();
			iterator = root;
		}
	}
}

