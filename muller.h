#ifndef MULLER_H
#define MULLER_H

#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <string>

using std::function;
using std::string;
using std::cout;
using std::endl;

class muller{
public:
	//constructor que recibe una funcion y una cadena
	muller(function<double(double)> p_func,
		   string p_str
		   ): func(p_func), str_func(p_str){
	}
	
	
	void tabla(double x0, double x1, double x2, int intervalos ) {
		double paso = (x2-x0)/intervalos;
		cout << str() << endl;
		cout
			<<setw(10)
			<<"x"
			<<setw(10)
			<<"f(x)"
			<< endl;
		while (x0 < x2 + paso) {
			cout
				<<setw(10)
				<<x0
				<<setw(10)
				<<f(x0)
				<< endl;
			x0 += paso;	
		}
	}
	
	bool raiz(double x0, 
			  double x1, 
			  double x2, 
			  int max_iter, 
			  double tolerancia, 
			  double &valor_raiz,
			  int &iter){
		
		
		//paso 1
		double h1 = x1 - x0;
		double h2 = x2 - x1;
		
		double d1 = (f(x1) - f(x0))/h1;
		double d2 = (f(x2) - f(x1))/h2;
		
		double a = (d2 - d1) / (h2 + h1);
		
		iter = 2;
		
		//paso 2
		while(iter < max_iter){ //TODO: menor o igual?
			double b = d2 + (h2 * a);
			double c = f(x2);
			double D = sqrt(b*b - 4*a*c); //Posiblemente hay raices complejas
			//paso 4
			double E = b - D;//Aqui calcula el error
			if(fabs(E) < fabs(b + D)){
				E= b + D;
			}
			//paso 5
			double h = (-2.0 * c)/E;
			//hallar el diguiente punto
			double x3 = x2 + h;
			double er = (x3 - x2) / x3;
			cout << std::setprecision(10) 
				<< "i: " << iter
				<< "   x3: " << x3
				<< "   f(x3): " << f(x3)
				<< "   error: " << er << endl;
			
			//verificacion
			if(fabs(h) < tolerancia){ //fabs(er)? o fabs(h)?
				valor_raiz = x3;
				return true;
			}
			x0 = x1;
			x1 = x2;
			x2 = x3;
			h1 = x1 - x0;
			h2 = x2 - x1;
			
			d1 = (f(x1) - f(x0))/h1;
			d2 = (f(x2) - f(x1))/h2;
			
			a = (d2 - d1) / (h2 + h1);
			iter = iter + 1;
		}
		return false;
	}
		
		double f(double x){
			return func(x);
		}
			string str(){
				return str_func;
			}
				
private:
					function<double(double)> func;
					string str_func;
};

#endif
