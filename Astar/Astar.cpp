#include "Header.h"

namespace Long
{
	int Astar::getMinFOpen()
	{
		int idx = 0;
		for (int i = 0; i < Astar::Open.size(); i++)
		{
			if (Open[i]->f < min)
			{
				Astar::min = Open[i]->f;
				idx = i;
			}
		}
		return idx;
	}
	int Astar::ifInOpen(int r, int c)
	{
		for (int i = 0; i < Astar::Open.size(); i++)
		{
			if (c == Astar::Open[i]->coordinates.col && r == Astar::Open[i]->coordinates.row)
				return i;
		}
		return -1;
	}
	int Astar::ifInClose(int r, int c)
	{
		for (int i = 0; i < Astar::Close.size(); i++)
		{
			if (c == Astar::Close[i]->coordinates.col && r == Astar::Close[i]->coordinates.row)
				return i;
		}
		return -1;
	}
	Node* Astar::getPath(int array[100][100], int srcRow, int srcCol, int tgtRow, int tgtCol, int width, int height)
	{
		Node* nSource = new Node(srcCol, srcRow);
		nSource->g = 0;
		nSource->h = nSource->calculateH(tgtRow, tgtCol);
		Astar::Open.push_back(nSource);
		while (Open.size() > 0)
		{
			int idx = Astar::getMinFOpen();
			Node* cur = new Node();
			cur = Astar::Open[idx];
			Astar::Open.erase(Astar::Open.begin() + idx);
			if (cur->coordinates.row == tgtRow && cur->coordinates.col == tgtCol)
			{
				return cur;
			}
			for (int i = 0; i < 4; i++)
			{

				int r = cur->coordinates.row + dr[i];
				int c = cur->coordinates.col + dc[i];

				if (r >= 0 && r < height && c >= 0 && c < width && array[r][c] != 1)
				{
					Node* mi = new Node();
					int dmi = cur->g + 1;
					int oIdx = Astar::ifInOpen(r, c);
					if (oIdx >= 0)
					{
						mi = Astar::Open[oIdx];
						if (mi->g < dmi)
							continue;
					}
					int cIdx = Astar::ifInClose(r, c);
					if (cIdx >= 0)
					{
						mi = Astar::Close[cIdx];
						if (mi->g < dmi)
						{
							continue;
						}
						else
						{
							Astar::Open.push_back(Astar::Close[cIdx]);
							Astar::Close.erase(Astar::Close.begin() + cIdx);
						}
					}
					if (oIdx < 0 && cIdx < 0)
					{
						mi = new Node(c, r);
						Astar::Open.push_back(mi);
					}

					mi->g = dmi;
					mi->f = mi->g + mi->calculateH(tgtRow, tgtCol);
					mi->parent = cur;
				}
				/*	int r = cur->coordinates.row + dr[i];
					int c = cur->coordinates.col + dc[i];

					if (r >= 0 && r < height && c >= 0 && c < width && array[r][c] != 1)
					{
						Node* successor = new Node(c,r);
						successor->g = cur->g + 1;
						successor->h = successor->calculateH(tgtRow, tgtCol);
						successor->f = successor->g + successor->h;
						successor->parent = cur;

						int oIdx = Astar::ifInOpen(r, c);
						int cIdx = Astar::ifInClose(r, c);

						if (oIdx >= 0)
						{
							Node* tmp = Astar::Open[oIdx];
							if (tmp->f < successor->f)
								continue;
							delete tmp;
						}

						if (cIdx >= 0)
						{
							Node* tmp = Astar::Close[cIdx];
							if (tmp->f < successor->f)
							{
								continue;
							}
							else
							{
								Astar::Open.push_back(Astar::Close[cIdx]);
								Astar::Close.erase(Astar::Close.begin() + cIdx);
							}
						}

						if (oIdx < 0 && cIdx < 0)
						{
							Astar::Open.push_back(successor);
						}*/
			}
			Astar::Close.push_back(cur);
		}
		return nullptr;
	}
}