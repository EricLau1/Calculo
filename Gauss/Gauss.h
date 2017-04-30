#include <iostream>
using namespace std;


/* 
  Exemplo:
  
  3x - y + z = 5
  2x + 5y - z = -8
  x + 2y + 5z = -3
  
  isolando x -> 3x = 5 + y - z    ->  x = (5 + y - z) / 3
  isolando y -> 5y = -8 - 2x + z  ->  y = (-8 - 2x + z) / 5
  isolando z -> 5z = -3 - x - 2y  ->  z = (-3 -x - 2y) / 5
  
*/

class Gauss {
	public:
		double x;
		double y;
		double z;
		
		Gauss(){
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}
		
				
		void mostre(){
		   cout << "\nValores Atualizados:" << endl;
		   printf("(X) = (%.3f)\n",this->x);
		   printf("(Y) = (%.3f)\n",this->y);
		   printf("(Z) = (%.3f)\n",this->z); 
		}
		
		void mostre(int ite){
		   cout << "\nValores Atualizados - Iteracao " << ite << endl;
		   printf("(X) = (%.3f)\n",this->x);
		   printf("(Y) = (%.3f)\n",this->y);
		   printf("(Z) = (%.3f)\n",this->z); 
		}
		
		
};
