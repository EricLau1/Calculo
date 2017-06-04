#include <iostream>
#include "Gauss.h"
using namespace std;

int main(){
	
	Gauss g1;
    double aux[3];
    double e[3];
		
	cout << "X Y Z Inicializados: " << endl;
	printf("(X) = (%.3f)\n",g1.getValorX());
	printf("(Y) = (%.3f)\n",g1.getValorY());
	printf("(Z) = (%.3f)\n",g1.getValorZ());
	
	aux[0] = g1.getValorX();
	aux[1] = g1.getValorY();
	aux[2] = g1.getValorZ(); 
	
	
	cout << "\nAtualizando..." << endl;	
	g1.setValorX(g1.atualizaX(g1));
	g1.setValorY(g1.atualizaY(g1)); 
	g1.setValorZ(g1.atualizaZ(g1)); 
	
	int i = 0;
	cout << "\nIteracao " << i << endl;
	
	printf("(X %d) = (%.3f)\n", (i+1), g1.getValorX());
	printf("(Y %d) = (%.3f)\n", (i+1), g1.getValorY());
	printf("(Z %d) = (%.3f)\n", (i+1), g1.getValorZ());
	
	e[0] = g1.calc_parada(g1.getValorX(), aux[0]);
	e[1] = g1.calc_parada(g1.getValorY(), aux[1]);
	e[2] = g1.calc_parada(g1.getValorZ(), aux[2]);
	
	cout << "\nCriterio de Parada: " << endl;
	printf("X = %f\n",e[0]);
	printf("Y = %f\n",e[1]);
	printf("Z = %f\n",e[2]);
	
	cout << "\nPrecisao: " << g1.getPrecisao() << endl;
	
	while( !(g1.parada(e[0]) && g1.parada(e[1]) && g1.parada(e[2])) ){
		
	    aux[0] = g1.getValorX();
	    aux[1] = g1.getValorY();
	    aux[2] = g1.getValorZ(); 
	    	    
	   	cout << "\nAtualizando..." << endl;	
	    g1.setValorX(g1.atualizaX(g1));
	    g1.setValorY(g1.atualizaY(g1)); 
	    g1.setValorZ(g1.atualizaZ(g1)); 
	    
	    i++;
	    cout << "\nIteracao " << i << endl;

	    printf("(X %d) = (%.3f)\n", (i+1), g1.getValorX());
	    printf("(Y %d) = (%.3f)\n", (i+1), g1.getValorY());
	    printf("(Z %d) = (%.3f)\n", (i+1), g1.getValorZ());
	    
	    e[0] = g1.calc_parada(g1.getValorX(), aux[0]);
	    e[1] = g1.calc_parada(g1.getValorY(), aux[1]);
	    e[2] = g1.calc_parada(g1.getValorZ(), aux[2]);
	    
        cout << "\nCriterio de Parada: " << endl;
	    printf("X = %f\n",e[0]);
	    printf("Y = %f\n",e[1]);
	    printf("Z = %f\n",e[2]);	    
	}//fim while

   g1.somatorio();
	return 0;
}
