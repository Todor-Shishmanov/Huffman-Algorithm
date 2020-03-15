#pragma once
#include "Tree.h"
#include "FreqTable.h"
#include <queue>
#include <string>

//same as std::greater<T>, but for Tree. Needed in minHeap
struct compare_trees {
	bool operator()(Tree* first, Tree* second) {
		return(first->get_freq() > second->get_freq());
	}
};

class Algorithm :
	public Tree,
	public FreqTable
{
private:
	std::priority_queue<Tree*, std::vector<Tree*>, compare_trees> all_trees;
	std::vector<short> letters;
	std::vector<std::string> coded_letters;
public:
	Algorithm(FreqTable table);

	Tree* top_element() {
		return all_trees.top();
	}

	void Algorithm_code(Tree* root, std::string code);
	void print_the_code(std::vector<short> original);
	void Algorithm_decode(Tree* root, std::string coded_message);
};
