
/*
Name: Christopher Tuncap
CSCI 4270 - Assignment 3
Date: 2/14/2018
Description: This algorithm solves a grid of 2n x 2n and a blank tile by placing trominos recursively.
*/

#include <iostream>
#include "tromino.h"
#include <ctime>

using namespace std;

void solve(int, int, int, int, int, Tromino &tromino);

int main()
{
	int n, x, y;
	cout << "N: ";
	cin >> n;
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;

	Tromino tromino(n, x, y);
	cout << tromino << endl;
	solve(0, 0, tromino.size(), x, y, tromino);
	cout << tromino << endl;

	system("pause");
	return 0;
}

void solve(int x, int y, int size, int blockX, int blockY, Tromino &tromino)
{
	if (size == 1)
		return;
	else
	{
		int halfSize = size / 2;
		int xCenter = x + halfSize;
		int yCenter = y + halfSize;
		//if missing block is in first quadrant.
		if ((blockX >= xCenter && blockY < yCenter))
		{
			tromino.place(xCenter - 1, yCenter - 1, xCenter - 1, yCenter, xCenter, yCenter);

			//recursive call on each quadrants
			//first quadrant
			solve(x + halfSize, y, halfSize, blockX, blockY, tromino);
			//second quadrant
			solve(x, y, halfSize, xCenter - 1, yCenter - 1, tromino);
			//third quadrant
			solve(x, y + halfSize, halfSize, blockX, blockY, tromino);
			//fourth quadrant
			solve(x + halfSize, y + halfSize, halfSize, xCenter, yCenter, tromino);
		}
		//if missing block is in second quadrant.
		if ((blockX < xCenter && blockY < yCenter))
		{
			tromino.place(xCenter, yCenter, xCenter - 1, yCenter, xCenter, yCenter - 1);

			//recursive call on each quadrants
			//first quadrant
			solve(x + halfSize, y, halfSize, xCenter, yCenter, tromino);
			//second quadrant
			solve(x, y, halfSize, blockX, blockY, tromino);
			//third quadrant
			solve(x, y + halfSize, halfSize, xCenter, yCenter - 1, tromino);
			//fourth quadrant
			solve(x + halfSize, y + halfSize, halfSize, blockX, blockY, tromino);

		}
		//if missing block is in third quadrant.
		if ((blockX < xCenter && blockY >= yCenter))
		{
			tromino.place(xCenter, yCenter, xCenter - 1, yCenter - 1, xCenter, yCenter - 1);

			//recursive call on each quadrants
			//first quadrant
			solve(x + halfSize, y, halfSize, blockX, blockY, tromino);
			//second quadrant
			solve(x, y, halfSize, xCenter - 1, yCenter, tromino);
			//third quadrant
			solve(x, y + halfSize, halfSize, blockX, blockY, tromino);
			//fourth quadrant
			solve(x + halfSize, y + halfSize, halfSize, xCenter, yCenter, tromino);
		}
		//if missing block is in fourth quadrant
		if ((blockX >= xCenter && blockY >= yCenter))
		{
			tromino.place(xCenter - 1, yCenter - 1, xCenter, yCenter - 1, xCenter - 1, yCenter);

			//recursive call on each quadrants
			//first quadrant
			solve(x + halfSize, y, halfSize, xCenter - 1, yCenter, tromino);
			//second quadrant
			solve(x, y, halfSize, blockX, blockY, tromino);
			//third quadrant
			solve(x, y + halfSize, halfSize, xCenter, yCenter - 1, tromino);
			//fourth quadrant
			solve(x + halfSize, y + halfSize, halfSize, blockX, blockY, tromino);
		}
	}

}


