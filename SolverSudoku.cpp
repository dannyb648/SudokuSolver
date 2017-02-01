#include <iostream>
using std::cout;
using std::endl;

#define W 9
#define EMPTY 0

int getIndex(int y, int x)
{
	return (y * W) + x;
}

bool inX(int puzzle[81], int x, int target)
{
	for(int y = 0; y < W; y++)
	{
		if(puzzle[getIndex(y,x)] == target)
		{
			return true;
		}
	}
	return false;
}

bool inY(int puzzle[81], int y, int target)
{
	for(int x = 0; x < W; x++)
	{
		if(puzzle[getIndex(y,x)] == target)
		{
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	int col = 7;
	int row = 4;
	int puzzle[81] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 
					  9, 10, 11, 12, 13, 14, 15, 16, 17,
					  18, 19, 20, 21, 22, 23, 24, 25, 26, 
					  27, 28, 29, 30, 31, 32, 33, 34, 35, 
					  36, 37, 38, 39, 40, 41, 42, 43, 44, 
					  45, 46, 47, 48, 49, 50, 51, 52, 53, 
					  54, 55, 56, 57, 58, 59, 60, 61, 62, 
					  63, 64, 65, 66, 67, 68, 69, 70, 71, 
					  72, 73, 74, 75, 76, 77, 78, 79, 80};
	int target = 1147;
	cout << inX(puzzle, 2, target) << endl;
	return 0;
}
