#include "pch.h"
#include "Set.h"
#include "List.h"

Set::Set(Point* mas, int size)
{
	Point temp;
	for (int i(0); i < size; i++)
	{
		temp.x = mas[i].x;
		temp.y = mas[i].y;
		lst.push_back(temp);
	}
}

int Set::checkSet(Set s)
{
	double max = 0;
	for (double i(0); i < s.lst.size() - 2; i++) //для каждой точки i берем все возможные точки j
	{
		for (double j(i + 1); j < s.lst.size() - 1; j++) //а для каждой точки j, взятых для i берем все возможные точки k
		{
			for (double k(j + 1); k < s.lst.size(); k++)
			{
				//далее мы находим периметр треугольника для текущих трех взятых точек
				double P = sqrt((abs(s.lst[i].x - s.lst[j].x)) * (abs(s.lst[i].x - s.lst[j].x)) + (abs(s.lst[i].y - s.lst[j].y))*(abs(s.lst[i].y - s.lst[j].y)))
					+ sqrt((abs(s.lst[j].x - s.lst[k].x)) * (abs(s.lst[j].x - s.lst[k].x)) + (abs(s.lst[j].y - s.lst[k].y))*(abs(s.lst[j].y - s.lst[k].y)))
					+ sqrt((abs(s.lst[i].x - s.lst[k].x)) * (abs(s.lst[i].x - s.lst[k].x)) + (abs(s.lst[i].y - s.lst[k].y))*(abs(s.lst[i].y - s.lst[k].y)));

				if (P > max)
				{
					max = P;
				}
			}
		}
	}
	return max;
}


Set::~Set() {}
