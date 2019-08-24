#include "Path.h"

std::vector<int> getPath(Node* s) {
	std::vector<int> res;
	Node* curr = s;
	res.push_back(curr->idx);
	while (curr->p != 0) {
		curr = curr->p;
		res.push_back(curr->idx);
	}
	return res;
}

std::vector<int> combinePath(std::vector<int> sl, std::vector<int> el) {
	std::vector<int> res;
	std::vector<int>::iterator iter;
	for (int i = 0; i < sl.size(); i++) {
		if ((iter = find(el.begin(), el.end(), sl[i])) != el.end()) break;
		res.push_back(sl[i]);
	}

	for (; iter != el.begin(); iter--) {
		res.push_back(*iter);
	}

	res.push_back(el.front());

	return res;
}