#include <iostream>
using namespace std;

class Expressao {
	public:
		double a;
	    double b;
		double c;
		double k;
			
	    	Expressao(){
				a = 0;
				b = 0;
				c = 0;
				k = 0;
			}
			
			Expressao(double a,double b, double c, double k){
				this->a = a;
				this->b = b;
				this->c = c;
				this->k = k;
			}
			
			iniciar(){
				cout << "Informe valor de <A>: ";
				cin >> a;
				cout << "Informe valor de <B>: ";
				cin >> b;
				cout << "Informe valor de <C>: ";
				cin >> c;
				cout << "Informe valor de <K>: ";
				cin >> k;
			}
};
