#include <iostream>
#include <fstream>
#include <ctime>

#define _LENGTH 10000
#define _STEP 100

using namespace std;
typedef long long ll;

double* Algoritmo1(ll* X, ll n);
double* Algoritmo2(ll* X, ll n);

int main()
{
	ll* X = new ll[_LENGTH];
	for(int i = 0; i < _LENGTH; i++)
		X[i] = i;

	ofstream arquivo("dados.txt");

	for(ll i = 0; i < _LENGTH; i += _STEP)
	{
		clock_t t1, t2;

		t1 = clock();
		Algoritmo1(X, i);
		t1 = clock() - t1;
		
		t2 = clock();
		Algoritmo2(X, i);
		t2 = clock() - t2;

		if(arquivo.is_open())
			arquivo << i << endl << t1/(CLOCKS_PER_SEC / 1000000) << endl << t2/(CLOCKS_PER_SEC/ 1000000) << endl;
		else
			cout << "erro no arquivo" << endl;

	}

	return 0;

}

double* Algoritmo1(ll* X, ll n)
{
	double* A = new double[n];
	for(ll i = 0; i < n; i++)
	{
		ll a = 0;
		for(int j = 0; j <= i; j++)
		{
			a += X[j];
		}
		A[i] = (a * 1.0)/(i+1);
	}

	return A;
}

double* Algoritmo2(ll* X, ll n)
{
	double* A = new double[n];

	ll s = 0;
	for(ll i = 0; i < n; i++)
	{
		s += X[i];
		A[i] = (s * 1.0)/(i+1);
	}

	return A;
}
