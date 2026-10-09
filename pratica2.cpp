#include <iostream>
#include <ctime>
#define _LENGTH 10000

double* algoritmoIgnobil(double* X, long long n);
double* algoritmoAstuto(double* X, long long n);

int main()
{
	double* X = new double[_LENGTH];
	for(long long i = 0; i < _LENGTH; i++)
	{
		X[i] = i;
	}
	
	clock_t t1, t2;
	clock_t total1, total2;
	for(long long n = 0; n < _LENGTH; n += 100)
	{
		t1 = clock();
		algoritmoIgnobil(X, n);
		t2 = clock();
		total1 = t2 - t1;		
		double t1us = (total1 / (CLOCKS_PER_SEC / 1000000.0)); 
	
		t1 = clock();
		algoritmoAstuto(X, n);
		t2 = clock();
		total2 = t2 - t1;
		double t2us = (total2 / (CLOCKS_PER_SEC / 1000000.0)); 	

		std::cout << "Teste " << n+1 << ": algoritmo1: " << t1us << " algoritmo2: " << t2us << std::endl;  
	} 	
	return 0;
}

double* algoritmoIgnobil(double* X, long long n)
{
	double* A = new double[n];

	for(int i = 0; i < n; i++)
	{
		double a = 0;
		for(int j = 0; j <= i; j++)
			a += X[j];	
		A[i] = a / (i + 1);
	}
	
	return A;	
}

double* algoritmoAstuto(double* X, long long n)
{
	double* A = new double[n];

	double s = 0;
	for(int i = 0; i < n; i++)
	{
		s = s + X[i];	
		A[i] = s/(i+1);
	}
	
	return A;	
}
