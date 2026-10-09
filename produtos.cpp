#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Produto{
	string nome;
	double valor;
	long long codBarras;
};

Produto receberProduto();
void adicionarProduto(Produto produto, Produto** produtos, int* n);

int main()
{
	Produto* produtos;
	produtos = new Produto[1];
	int n = 0;
	int opcao;

	while(opcao != 5){

		cout << "Escolha a opcao\n1. Cadastrar produto\n2. Mostrar dados de produto\n3. Apagar produto\n4. Mostrar produtos\n5. Sair" << endl;
		cin >> opcao;
		
		switch(opcao)
		{
			case 1:{
				Produto produto = receberProduto();
				adicionarProduto(produto, &produtos, &n);			
				break;
			}
			case 2:{
				string nome;
				cout << "Digite o nome do produto que deseja buscar: " << endl;
				cin >> nome;
				bool found = false;
				for(int i = 0; i < n; i++)
				{
					if(nome == produtos[i].nome)
					{
						cout << "Nome: " << produtos[i].nome << endl;
						cout << "Valor: R$" << produtos[i].valor << endl;
						cout << "Codigo de barras: " << produtos[i].codBarras << endl;
						cout << endl;
						found = true;
					}
				}
				if(!found)
					cout << "Produto nao encontrado" << endl;
				break;
			}
			case 4:{
				for(int i = 0; i < n; i++)
				{
					cout << setw(20) << produtos[i].nome << " R$" << setw(8) << produtos[i].valor << " Codigo de barras: " << setw(12) << produtos[i].codBarras << endl;
				}
			}
			default:{
				
				break;
			}
		}
	}
}

Produto receberProduto(){
	Produto produto;
	cout << "Digite o nome do produto: " << endl;
	cin >> produto.nome;
	cout << "Digite o valor do produto: " << endl;
	cin >> produto.valor;
	cout << "Digite o codigo de barras do produto: " << endl;
	cin >> produto.codBarras; 
	return produto;	
}

void adicionarProduto(Produto produto, Produto** produtos, int* n){
	Produto* novoProdutos = new Produto[*n + 1];
	
	for(int i = 0; i < *n; i++)
	{
		novoProdutos[i] = (*produtos)[i];
	}
	
	novoProdutos[*n] = produto;
	delete[] (*produtos);
	(*n)++;
	*produtos = novoProdutos;
	
}

void removerProduto(Produto* produtos, int index){

}

