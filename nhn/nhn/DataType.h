#pragma once
#ifndef DATATYPE_H
#define DATATYPE_H

struct Circle {
	double x, y;
	double r;
};

struct Node {
	Node* p;
	Node* next;
	Node* child;
	int idx;
	Circle circle;
};

#endif // !DATATYPE_H