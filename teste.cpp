#include <iostream>

using namespace std;
int* somarVetores(int* v1, int* v2, int n);

int main()
{
	int v1[5] = {1, 2, 3, 4 , 5};
	int v2[5] = {5, 4, 3, 2 , 1};
	
	int* v3 = somarVetores(v1, v2, 5);
	for(int i = 0; i < 5; i++)
		cout << v3[i] << endl;
	return 0;
}

int* somarVetores(int* v1, int* v2, int n){
	int* v3 = new int(n);
	for(int i = 0; i < n; i++)
		v3[i] = v1[i] + v2[i];
	return v3;
}
