#include <iostream>
#include "Expressao.h"

using namespace std;

class Gauss {
	private:
		double x;
		double y;
		double z;
		double precisao;
		Expressao vetor[3];
		
		public:
			Gauss(){
				ler();
				this->x = 0;
				this->y = 0;
				this->z = 0;
				cout << "Informe a Precisao: ";
				cin >> precisao;
			}
				
			//Setters
			void setPrecisao(double p){
				this->precisao = p;
			}
			
			void setValorX(double x){
				this->x = x;
			}
			
			void setValorY(double y){
				this->y = y;
			}
			
			void setValorZ(double z){
				this->z = z;
			}
			
			
			//Getters
			double getPrecisao()const{
				return precisao;
			}
			
			double getValorX()const{
				return this->x;
			}
			
			double getValorY()const{
				return this->y;
			}
			
			double getValorZ()const{
				return this->z;
			}
			
			//Metodo ler
		    void ler(){
		    
				for(int i = 0; i < 3; i++){
					cout << "Linha " << (i + 1) << endl;
					vetor[i].iniciar();
			}
				/*vetor[0] = Expressao(3,-1,1,5);
				vetor[1] = Expressao(2,5,-1,-8);
				vetor[2] = Expressao(1,2,5,-3);*/
			}
			
			double atualizaX(Gauss g){
				Gauss aux = g;
			    
				aux.setValorY(aux.getValorY() * vetor[0].b);
				aux.setValorZ(aux.getValorZ() * vetor[0].c);
				
				aux.setValorY(aux.getValorY() * -1);
				aux.setValorZ(aux.getValorZ() * -1);
				
				double valor = vetor[0].k + aux.getValorY() + aux.getValorZ();
				valor /= vetor[0].a;
				return valor;
			}
			
			double atualizaY(Gauss g){
				Gauss aux = g;
				
				aux.setValorX(aux.getValorX() * vetor[1].a);
				aux.setValorZ(aux.getValorZ() * vetor[1].c);
				
				aux.setValorX(aux.getValorX() * -1);
				aux.setValorZ(aux.getValorZ() * -1);
				
				double valor = vetor[1].k + aux.getValorX() + aux.getValorZ();
				valor /= vetor[1].b;
				return valor;
			}
			
			double atualizaZ(Gauss g){
				Gauss aux = g;
				
				aux.setValorX(aux.getValorX() * vetor[2].a);
				aux.setValorY(aux.getValorY() * vetor[2].b);
				
				aux.setValorX(aux.getValorX() * -1);
				aux.setValorY(aux.getValorY() * -1);
				
				double valor = (vetor[2].k + aux.getValorX() + aux.getValorY());
				valor /= vetor[2].c;
				return valor;
			}
			
		    
			double calc_parada(double atual, double anterior){
			
				double valor = (atual - anterior) / atual;
		        //if(valor < 0) valor *= -1;        
				printf("\n(%f - %f) / %f = %f\n",atual,anterior,atual,valor);
				if(atual == 0) {
					cout << "\nDivisao por 0" << endl;
					exit(1);
				}
				return valor;
			}
			
			bool parada(double valor){
				if(valor <= getPrecisao() || valor == 0){
					return true;
				}
				return false;
			}
			
			void somatorio(){
				double n[3];
				n[0] = (vetor[0].a * getValorX()) + (vetor[0].b * getValorY()) + (vetor[0].c * getValorZ());
				n[1] = (vetor[1].a * getValorX()) + (vetor[1].b * getValorY()) + (vetor[1].c * getValorZ());
			    n[2] = (vetor[2].a * getValorX()) + (vetor[2].b * getValorY()) + (vetor[2].c * getValorZ());
			    
			    printf("\n%.3f = %.3f\n", n[0],vetor[0].k);
			    printf("%.3f = %.3f\n", n[1],vetor[1].k);
			    printf("%.3f = %.3f\n", n[2],vetor[2].k);
			}
};
