#include <iostream>

using namespace std;

int binSearch(int* V, int v, int lo, int hi)
{
	if(V[(lo + hi) / 2] > v)
	{
		hi = (lo + hi) / 2;
		return binSearch(V, v, lo, hi);
	}
	else if(V[(lo + hi) / 2]) < v)
	{

		lo = (lo + hi) / 2;
		return binSearch(V, v, lo, hi);
	}
	else
		return lo;
}

int main()
{
	
	int size;
	cin >> size;

	int* V = new int[size];
	for(int i = 0; i < size; i++)
		cin >> V[i];
	
	int queries;
	cin >> queries;

	for(int i = 0; i < queries; i++){
		int n;
		cin >> n;
		cout << binSearch(V, n, 0, size) << endl; //i começa no 0
	}
}
