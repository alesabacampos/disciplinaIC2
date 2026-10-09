#include <iostream>
#include <string>

using namespace std;

class Domicilio{
	public:
		double rendaMedia;
		int ocupantes;
		string responsavel;
		string endereco;
		
		Domicilio(double rendaMedia, int ocupantes, string responsavel, string endereco){
			this->rendaMedia = rendaMedia;
			this->ocupantes = ocupantes;
			this->responsavel = responsavel;
			this->endereco = endereco;
		}		
};

int main(){

	int n;
	cout << "Quantos domicilios hao de ser cadastrados pela vossa senhoria?" << endl;
	cin >> n;

	Domicilio** domicilios = new Domicilio*[n+1];
	
	for(int i = 1; i < n + 1; i++)
	{
		double rendaMedia;
		int ocupantes;
		string responsavel;
		string endereco;

		cout << "Renda media mensal:" << endl;
		cin >> rendaMedia;

		cout << "Numero de ocupantes:" << endl;
		cin >> ocupantes;
		cin.ignore();

		cout << "Nome do responsavel:" << endl;
		getline(cin, responsavel);

		cout << "Endereco do domicilio:"<< endl;
		getline(cin, endereco);

		domicilios[i] = new Domicilio(rendaMedia, ocupantes, responsavel, endereco); 
	}

	for(int i = 2; i <= n; i++)
	{
		Domicilio* x = domicilios[i];
		domicilios[0] = x;
		int j = i;
		while(x->responsavel < domicilios[j - 1]->responsavel)
		{
			domicilios[j] = domicilios[j-1];
			j--;
		}
		domicilios[j] = x;
	}

	for(int i = 1; i <= n; i++)
	{
		cout << domicilios[i]->responsavel << endl;
	}

	string nome;
	getline(cin, nome);

	int l = 1;
	int r = n;
	bool sucesso = false;

	while((l <= r) && (sucesso == false))
	{
		int m = (l + r)/ 2;
		if(domicilios[m]->responsavel == nome)
			sucesso = true;
		else
		{
			if(domicilios[m]->responsavel < nome)
				l = m + 1;
			else
				r = m - 1;
		}
	}

	cout << (l + r) / 2 << endl;


	
}
