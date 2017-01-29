#include <iostream>
using std::cout;

int main(int argc, char *argv[])
{	
	const int N = 9;
	int arr[N][N] = {{0}};
	int arr[N*N] = argv[1];


	cout << arr[1][2] << "\n";

	return 0;
} 
