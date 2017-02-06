#include <iostream>
using std::cout;
using std::endl;

#define W 9
#define L W*W
#define EMPTY 0

int getIndex(int y, int x)
{
	return (y * W) + x;
}

bool inX(int puzzle[L], int x, int target)
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

bool inY(int puzzle[L], int y, int target)
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

bool inB(int puzzle[L], int bX, int bY, int target)
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(puzzle[getIndex(y + bY, x + bX)] == target)
			{
				return true;
			}
		}
	}
	return false;
}

bool isLegal(int puzzle[L], int x, int y, int target)
{
	return !inX(puzzle, x, target)
	 &&    !inY(puzzle, y, target)
	 &&    !inB(puzzle, x - x%3, y - y%3, target);
}

bool isEmpty(int puzzle[L], int &x, int &y)
{
	for(x = 0; x < W; x++)
	{
		for(y = 0; y < W; y++)
		{
			if(puzzle[getIndex(y,x)] == EMPTY)
			{
				return true;
			}
		}
	}
	return false;
}

bool SolveSudoku(int puzzle[L])
{
    int y;
    int x;
    
    if(isEmpty(puzzle, x, y) == false)
    {
        return true;   
    }
    
    for (int digit = 1; digit <= 9; digit++)
    {
        if(isLegal(puzzle, x, y, digit) == true)
        {
            puzzle[getIndex(y,x)] = digit;
            
            if(SolveSudoku(puzzle) == true)
            {
                return true;   
            }
            
            puzzle[getIndex(y,x)] = EMPTY;
        }
    }
    return false;
    
}

void outputPuzzle(int puzzle[L])
{
    for(int y = 0; y < W; y++)
    {
        for(int x = 0; x < W; x++)
        {
            cout << " " << puzzle[getIndex(y,x)] << " ";   
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{

	int puzzle[L] =   {3, 0, 6, 5, 0, 8, 4, 0, 0,
                       5, 2, 0, 0, 0, 0, 0, 0, 0,
                       0, 8, 7, 0, 0, 0, 0, 3, 1,
                       0, 0, 3, 0, 1, 0, 0, 8, 0,
                       9, 0, 0, 8, 6, 3, 0, 0, 5,
                       0, 5, 0, 0, 9, 0, 6, 0, 0,
                       1, 3, 0, 0, 0, 0, 2, 5, 0,
                       0, 0, 0, 0, 0, 0, 0, 7, 4,
                       0, 0, 5, 2, 0, 6, 3, 0, 0};
                       
    if(SolveSudoku(puzzle) == true)
    {
        cout << "Solved" << endl;
        outputPuzzle(puzzle);
    }
    else
    {
        cout << "Unsolvable" << endl;    
    }
	return 0;
}
