#include <iostream>

using namespace std;

long long recfatorial(long long n){
	if(n > 0)
		return n * recfatorial(n - 1);
	else
		return 1;
}

int main(){
	for(long long i = 0; i < 21; i++){
		cout << recfatorial(i) << endl;
	}

}
