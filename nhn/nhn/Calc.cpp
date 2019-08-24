#include <math.h>
#include "Calc.h"

int relateCircle(Circle c1, Circle c2) {
	double d = sqrt(pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2));
	double sum = (double)c1.r + (double)c2.r;
	if (sum > d) return 1; // Child
	else return -1; // No Related
}