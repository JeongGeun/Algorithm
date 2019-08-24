#include <iostream>
#include <algorithm>
#include <vector>
#include "DataType.h"
#include "Calc.h"
#include "Tree.h"
#include "Path.h"

bool compare(Node a, Node b) {
	return a.circle.r > b.circle.r;
}

int main() {
	std::cin >> tree_size;
	for (int i = 0; i < tree_size; i++) {
		std::cin >> nodeList[i].idx >> nodeList[i].circle.x >> nodeList[i].circle.y >> nodeList[i].circle.r;
	}

	std::sort(nodeList, nodeList + tree_size, compare);

	for (int i = 0; i < tree_size; i++) insertNode(&nodeList[i]);

	int start, end;
	std::cin >> start >> end;
	std::vector<int> result = combinePath(getPath(findNode(start)), getPath(findNode(end)));
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i];
		if (i == result.size() - 1) std::cout << std::endl;
		else std::cout << " ";
	}

	return 0;
}