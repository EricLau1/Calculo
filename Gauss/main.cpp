#include <iostream>
#include "Gauss.h"
using namespace std;

void idioma(const char*);

struct Valores {
	double a;
	double b;
	double c;
	double k;
};

double atualizaX(Valores,Gauss);
double atualizaY(Valores,Gauss);
double atualizaZ(Valores,Gauss);
bool precisao(double,double,double,char);
double calc(double,double);

double err[3];

int main(){
    idioma("Portuguese");
		
	Valores n[3];
	cout << "IMPORTANTE! SE O VALOR FOR ZERO DIGTE 1 COM O SINAL CORRESPONDENTE" << endl;
	for(int i = 0; i < 3; i++){
		cout << (i + 1) << "ª Linha" << endl;
    	cout << "Valor <A>: ";
	    cin >> n[i].a;
	    cout << "Valor <B>: ";
	    cin >> n[i].b;
	    cout << "Valor <C>: ";
	    cin >> n[i].c;
	    cout << "Valor <K>: ";
	    cin >> n[i].k;
    }
    
	Gauss at1;
	Gauss at2;
	
	at2.x = atualizaX(n[0],at1);
	at2.y = atualizaY(n[1],at1);
	at2.z = atualizaZ(n[2],at1);

	
	int iteracoes = 0;
	double e;
	cout << "Informe a precisao: ";
	cin >> e;
	
	while( !(precisao(at2.x,at1.x,e,'X') && precisao(at2.y,at1.y,e,'Y') && precisao(at2.z,at1.z,e,'Z')) ){
		err[0] = calc(at2.x,at1.x);
		err[1] = calc(at2.y,at1.y);
		err[2] = calc(at2.z,at1.z);
	
		at2.mostre(iteracoes);
		at1 = at2;
		at2.x = atualizaX(n[0],at1);
	    at2.y = atualizaY(n[1],at1);
	    at2.z = atualizaZ(n[2],at1);
	    iteracoes++;
	}
	
	    at2.mostre(iteracoes);
		err[0] = calc(at2.x,at1.x);
		err[1] = calc(at2.y,at1.y);
		err[2] = calc(at2.z,at1.z);
		cout << "\nCriterio de Parada:" << endl;
		for(int i = 0; i < 3; i++){
			cout << err[i] << endl;
		}
	
	return 0;
}

		
double atualizaX(Valores num, Gauss att){

	num.b *= att.y;	
	num.c *= att.z;

	num.b *= -1;
	num.c *= -1;
			
	num.k += (num.b + num.c);
	att.x = (num.k / num.a);
	
	return att.x;
}

double atualizaY(Valores num, Gauss att){

	num.a *= att.x;
	num.c *= att.z;	

	num.a *= -1;
	num.c *= -1;
	
	num.k += (num.a + num.c);
	att.y = (num.k / num.b);
	
	return att.y;
}

double atualizaZ(Valores num, Gauss att){

	num.a *= att.x;
	num.b *= att.y;

	num.a *= -1;
	num.b *= -1;
	
	num.k += (num.a + num.b);
	att.z = (num.k / num.c);
	
    return att.z;
}

bool precisao(double valor1,double valor2,double presicao,char letra){
	
	double number = (valor1 - valor2) / valor1;
	
	if(number < 0) number *= -1;
	
	if(number <= presicao){
		//printf("\nPrecisão %c = %.4f\n",letra,number);
		return true;
	}
	return false;
}

double calc(double n1,double n2){
	return (n1 - n2) / n1;
}

void idioma(const char* pais){
	setlocale(LC_ALL, pais);
}

