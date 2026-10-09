#include <iostream>

using namespace std;

int findMin(int* v, int n, int renatoTinos);

int main(){

	int n;
	cin >> n;
	
	int* v = new int[n];
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	for(int i = 0; i < n; i++)
	{
		int min = findMin(v, n, i);

		int temp = v[i];
		v[i] = v[min];
		v[min] = temp;
	}

	for(int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}

int findMin(int* v, int n, int renatoTinos)
{
	int min = renatoTinos;
	for(int i = renatoTinos + 1; i < n; i++)
		if(v[i] < v[min])
			min = i;
	
	return min;
}
