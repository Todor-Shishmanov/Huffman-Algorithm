#pragma once
class Tree
{
private:
	int freq;
	int letter;
	Tree* left;
	Tree* right;
public:
	Tree() {
		freq = 0;
		letter = 0;
		left = nullptr;
		right = nullptr;
	}
	Tree(int new_freq, int new_letter) {
		freq = new_freq;
		letter = new_letter;
		left = nullptr;
		right = nullptr;
	}
	Tree* left_child() {
		return left;
	}
	Tree* right_child() {
		return right;
	}
	void set_left_to(Tree* root) {
		left = root;
	}
	void set_right_to(Tree*root) {
		right = root;
	}
	int get_freq() {
		return freq;
	}
	int get_letter() {
		return letter;
	}
};

