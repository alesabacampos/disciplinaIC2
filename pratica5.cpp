#include <iostream>

using namespace std;

int buscaIterativa(int* V, int n, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(n == V[i])
			return i;
	}

	return -1;
}

int buscaRecursiva(int* V, int n, int size, int i)
{
	if(V[i] == n)
		return i;
	else if(i == size)
		return -1;
	else
		return buscaRecursiva(V, n, size, ++i);
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
		cout << buscaIterativa(V, n, size) << " " << buscaRecursiva(V, n, size, 0) << endl; //i começa no 0
	}
}
