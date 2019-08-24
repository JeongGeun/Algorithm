#pragma once
#ifndef PATH_H
#define PATH_H
#include <vector>
#include <algorithm>
#include "DataType.h"

std::vector<int> getPath(Node* s);
std::vector<int> combinePath(std::vector<int> sl, std::vector<int> el);
#endif // !PATH_H