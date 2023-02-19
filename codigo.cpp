// Ex04Pag57.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <locale>
#include <string>
using namespace std;

int main()
{
	string nome;
	char sexo;
	char EstadoCivil;
	int idade;
	int TotalEntrevistados = 0;
	int QuantidadeDeMulheresEntrevistadas = 0;
	int QuantidadeDeHomensEntrevistados = 0;
	int QuantidadeDeMulheresSolteirasQueGanhamAte3500Reais = 0;
	int QuantidadeDePessoasComRendaAte500Reais = 0;
	int QuantidadeDeEntrevistadosCom30Ou40Anos = 0;
	double PorcentagemDePessoasComRendaAte500 = 0;
	double RendaMensal;
	double TotalRendaMensal = 0;
	double RendaMediaPessoas30e40Anos;
	double SomaTotalDaRendaDePessoasCom30ou40Anos = 0;
	double MenorRendaDeHomensCasados = 9999999999999999;
	double MaiorRendaEntreMulheresSolteiras = -999999999999999; 
	double PorcentagemDeHomensEntrevistados = 0;
	double PorcentagemDeMulheresEntrevistadas = 0;
	

	while (TotalEntrevistados < 3) 
	{
		cout << "Digite seu nome: " << endl;
		cin >> nome;
		cout << "Digite seu sexo <F/M>: ";
		cin >> sexo;
		cout << "Digite sua idade: ";
		cin >> idade; 
		cout << "Digite sua renda mensal: ";
		cin >> RendaMensal;
		cout << "Qual seu estado civil <S/C> ? ";
		cin >> EstadoCivil;

		if (sexo == 'm' || sexo == 'M') 
			QuantidadeDeHomensEntrevistados++;
		else if (sexo == 'f' || sexo == 'F')
			QuantidadeDeMulheresEntrevistadas++;
		if ((EstadoCivil == 'C' || EstadoCivil == 'c') && (sexo == 'm' || sexo == 'M') && RendaMensal < MenorRendaDeHomensCasados)
			MenorRendaDeHomensCasados = RendaMensal;
		if ((EstadoCivil == 'S' || EstadoCivil == 's') && (sexo == 'f' || sexo == 'F') && RendaMensal > MaiorRendaEntreMulheresSolteiras)
			MaiorRendaEntreMulheresSolteiras = RendaMensal;
		if (idade >= 30 && idade <= 40)
		{
			SomaTotalDaRendaDePessoasCom30ou40Anos += RendaMensal;
			QuantidadeDeEntrevistadosCom30Ou40Anos++;
		}
		if ((sexo == 'f' || sexo == 'F') && idade <= 25 && (EstadoCivil == 'S' || EstadoCivil == 's')) 
			QuantidadeDeMulheresSolteirasQueGanhamAte3500Reais++;
		if (RendaMensal <= 500)
		{
			QuantidadeDePessoasComRendaAte500Reais++;
		}
		
		TotalEntrevistados++;
	}
	cout << "\n";
	PorcentagemDeHomensEntrevistados = (QuantidadeDeHomensEntrevistados * 100) / TotalEntrevistados;
	PorcentagemDeMulheresEntrevistadas = (QuantidadeDeMulheresEntrevistadas * 100) / TotalEntrevistados;
	RendaMediaPessoas30e40Anos = SomaTotalDaRendaDePessoasCom30ou40Anos / QuantidadeDeEntrevistadosCom30Ou40Anos;
	PorcentagemDePessoasComRendaAte500 = (QuantidadeDePessoasComRendaAte500Reais * 100) / TotalEntrevistados;

	cout << "Porcentagem de homens entrevistados: " << PorcentagemDeHomensEntrevistados << endl
		<< "Porcentagem de mulheres entrevistadas : " << PorcentagemDeMulheresEntrevistadas << endl
		<< "Menor renda entre homens casados: " << MenorRendaDeHomensCasados << endl
		<< "Maior renda entre as mulheres solteiras: " << MaiorRendaEntreMulheresSolteiras << endl
		<< "Renda media das pesoas com idade entre 30 e 40 anos: " << RendaMediaPessoas30e40Anos << endl
		<< "Quantas mulheres solteiras com idade inferior a 20 anos ganham ate 3200 reais: " << QuantidadeDeMulheresSolteirasQueGanhamAte3500Reais << endl
		<< "Porcentagem de pessoas com renda ate 500 reais: " << PorcentagemDePessoasComRendaAte500 << endl;;
			

}

