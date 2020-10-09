#include "Header.h"
#include <iostream>
using namespace std;
int main()
{
	int array[100][100] =
	{
		{0,0,1,0,0,0},
		{0,0,1,0,1,0},
		{0,0,0,0,1,0},
		{1,1,0,0,0,1}
	};

	int row = 4;
	int col = 6;
	Long::Astar a;
	Long::Node* result = a.getPath(array, 0, 0, 2, 5, col, row);
	while (result != NULL)
	{
		array[result->coordinates.col][result->coordinates.row] = 2;
		cout << "col :" << result->coordinates.col << "row :" << result->coordinates.row << endl;
		result = result->parent;
	}

	delete result;
}