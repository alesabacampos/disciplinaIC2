#include <iostream> 

using namespace std;

int repete(int* v, int n);

int main(){
	
	int n;
	cin >> n;

	int* v = new int[n];

	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	cout << repete(v, n) << endl;	
}

int repete(int* v, int n)
{
	for(int i = 1; i < n; i++)
		if(v[i-1] == v[i])
			return i - 1;
	return -1; 
}
