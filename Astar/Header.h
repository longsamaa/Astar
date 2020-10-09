#pragma once
#pragma once
#include <vector>
namespace Long
{
	struct coordinates
	{
		int row, col;
	};

	struct Node
	{
		coordinates coordinates;
		int g;
		int h;
		int f;
		Node* parent;
		//fucntion
		Node(int col, int row)
		{
			coordinates.col = col;
			coordinates.row = row;
			g = 0;
			h = 0;
			f = 0;
			parent = NULL;
		}
		Node()
		{
			coordinates.col = 0;
			coordinates.row = 0;
			g = 0;
			h = 0;
			f = 0;
		};
		int calculateH(int tgtRow, int tgtCol)
		{
			return (coordinates.row - tgtRow) * (coordinates.row - tgtRow) + (coordinates.col - tgtCol) * (coordinates.col - tgtCol);
		}
	};

	class Astar
	{
	public:
		Node* getPath(int array[100][100], int srcRow, int srcCol, int tgtRow, int tgtCol, int width, int height);
		int ifInOpen(int r, int c);
		int ifInClose(int r, int c);
		int getMinFOpen();
	public:
		int dc[4] = { -1, 0, 1, 0 };
		int dr[4] = { 0, -1, 0, 1 };
		int min = 1000000;
		std::vector<Node*> Open;
		std::vector<Node*> Close;
	};
}