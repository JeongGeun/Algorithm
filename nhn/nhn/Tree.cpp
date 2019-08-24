#include "Tree.h"
#include "Calc.h"

Node nodeList[128];
Node root;
int tree_size;

void insertNode(Node* tmp) {
	if (tmp == 0) return;
	// using int because of checking error
	if (root.child == 0) {
		root.child = tmp;
		tmp->p = &root;
		return;
	}
	std::queue<Node*> que;
	que.push(root.child);
	Node* tmpParent = &root;
	while (!que.empty()) {
		Node* cur = que.front();
		que.pop();

		if (relateCircle(tmp->circle, cur->circle) == 1) {
			tmpParent = cur;
			if (cur->child == 0) {
				cur->child = tmp;
				tmp->p = tmpParent;
				return;
			}
			que.push(cur->child);
			continue;
		}

		if (cur->next == 0) {
			cur->next = tmp;
			tmp->p = tmpParent;
			return;
		}

		que.push(cur->next);
		continue;
	}

	return;
}

Node* findNode(int idx) {
	if (idx == 0) return &root;
	for (int i = 0; i < tree_size; i++) {
		if (nodeList[i].idx == idx) return &nodeList[i];
	}
	return 0;
}