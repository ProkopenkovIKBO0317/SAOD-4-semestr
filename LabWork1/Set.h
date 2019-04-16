#pragma once
#include "List.h"
#include <vector>
#include <math.h>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Set
{
public:
	vector<Point> lst;
	Set(Point* mas, int size);
	static int checkSet(Set s);
	~Set();
};

