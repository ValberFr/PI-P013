#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <regex>

using namespace std;

struct Produto
{
    string codigo;
    string nome;
    double preco;
};

void inserirProduto(vector<Produto> &produtos)
{
    if (produtos.size() != 300)
    {

        Produto produto;
        regex codigoValido("^[0-9]{13}$"), nomeValido("^.{0,20}$");

        cout << "\nInforme o codigo do produto de 13 digitos: ";
        cin >> produto.codigo;

        while (true)
        {
            if (regex_match(produto.codigo, codigoValido))
            {
                break;
            }
            else
            {
                cout << "Informe o codigo do produto de 13 digitos: ";
                cin >> produto.codigo;
            }
        }

        for (Produto &it : produtos)
        {
            if (it.codigo == produto.codigo)
            {
                cout << "Codigo ja cadastrado!" << endl;
                return;
            }
        }

        cout << "Informe o nome do produto: ";
        cin.ignore();
        getline(cin, produto.nome);

        while (true)
        {
            if (regex_match(produto.nome, nomeValido))
            {
                break;
            }
            else
            {
                cout << "\nInforme o nome do produto: ";
                getline(cin, produto.nome);
            }
        }

        for (Produto &it : produtos)
        {
            if (it.nome == produto.nome)
            {
                cout << "Nome ja cadastrado!" << endl;
                return;
            }
        }

        cout << "Informe o preco do produto: ";
        cin >> produto.preco;

        produtos.push_back(produto);

        cout << endl
             << "Produto cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "Limite máximo de 300 produtos foi atingido!";
    }
}

void excluirProduto(vector<Produto> &produtos)
{
    string codigo;
    cout << "\nInforme o codigo do produto a ser excluído: ";
    cin >> codigo;

    for (auto it = produtos.begin(); it != produtos.end(); ++it)
    {
        if (it->codigo == codigo)
        {
            produtos.erase(it);
            cout << "\nProduto excluído com sucesso!" << endl;
            return;
        }
    }

    cout << "\nProduto não encontrado." << endl;
}

void listarProdutos(vector<Produto> &produtos)
{
    if (produtos.empty())
    {
        cout << "\nNão existem produtos cadastrados!" << endl;
        return;
    }

    cout << "\nLista de produtos cadastrados:" << endl;
    for (Produto &it : produtos)
    {
        cout << "Codigo: " << it.codigo << endl;
        cout << "Nome: " << it.nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << it.preco << endl;
    }
    cout << endl;
}

void consultarPreco(vector<Produto> &produtos)
{
    string codigo;
    cout << "\nInforme o codigo do produto a ser consultado: ";
    cin >> codigo;

    for (Produto &it : produtos)
    {
        if (it.codigo == codigo)
        {
            cout << "Preco: " << fixed << setprecision(2) << it.preco << endl;
            return;
        }
    }

    cout << "\nProduto não encontrado." << endl;
}

int main()
{
    vector<Produto> listaProdutos;
    int opcao;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Inserir um novo produto" << endl;
        cout << "2. Excluir um produto" << endl;
        cout << "3. Listar produtos" << endl;
        cout << "4. Consultar o preço de um produto" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            inserirProduto(listaProdutos);
            break;
        case 2:
            excluirProduto(listaProdutos);
            break;
        case 3:
            listarProdutos(listaProdutos);
            break;
        case 4:
            consultarPreco(listaProdutos);
            break;
        case 5:
            cout << "Saindo do programa." << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
        }
    } while (opcao != 5);

    return 0;
}
