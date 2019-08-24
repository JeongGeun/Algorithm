#pragma once
#ifndef TREE_H
#define TREE_H
#include <queue>
#include "DataType.h"

extern Node nodeList[128];
extern Node root;
extern int tree_size;

void insertNode(Node* tmp);
Node* findNode(int idx);

#endif // !TREE_H
