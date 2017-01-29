#include <iostream>
using std::cout;



int main(int argc, char *argv[])
{	
	const int N = 3;
	int arr[N][N];
	//int* p = &arr[N][N];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}
	}
	cout << arr[1][2] << "\n";
	

	
//	cout << p << "\n\a";
	return 0;
} 
