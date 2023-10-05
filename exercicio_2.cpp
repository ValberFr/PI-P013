#include <iostream>
#include <string>

using namespace std;

struct Empregado
{
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};

void reajusta_dez_porcento(Empregado vetor[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        vetor[i].salario *= 1.10;
    }
}

int main()
{
    Empregado vetorEmpregados[50];

    vetorEmpregados[0] = {"Marina", "Luna", 1980, "26.760.718-0", 2005, 1500.0};
    vetorEmpregados[1] = {"Joao", "Melo", 1990, "20.800.978-4", 2010, 2000.0};
    vetorEmpregados[2] = {"Valber", "Francisco", 1985, "11.070.083-1", 2015, 1000.0};
    vetorEmpregados[3] = {"Andre", "Cardoso", 1995, "28.398.869-1", 2008, 2300.0};
    vetorEmpregados[4] = {"Caroline", "Fogaça", 1990, "12.111.842-3", 2011, 1200.0};
    vetorEmpregados[5] = {"Betina", "Teixeira", 1991, "20.417.810-1", 2007, 8000.0};

    reajusta_dez_porcento(vetorEmpregados, 6);

    cout << "Empregados com reajuste de 10%: " << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Nome: " << vetorEmpregados[i].nome << " " << vetorEmpregados[i].sobrenome << endl;
        cout << "Ano de Nascimento: " << vetorEmpregados[i].anoNascimento << endl;
        cout << "RG: " << vetorEmpregados[i].RG << endl;
        cout << "Ano de Admissão: " << vetorEmpregados[i].anoAdmissao << endl;
        cout << "Salário: " << vetorEmpregados[i].salario << endl;
        cout << endl;
    }

    return 0;
}
