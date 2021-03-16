#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

//#include "biseccion.h"
#include "reglafalsa.h"
#include "newtonraphson.h"
#include "secante.h"
#include "muller.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::function;


void raices_ejercicio_1();
void raices_ejercicio_2();
void raices_ejercicio_3();

int main (int argc, char *argv[]) {
	
	//Caso 1: x^2 - cos(x)
	raices_ejercicio_1();
	
	//Caso 2: f(x) = x^3 + 4x^2 - 10
	raices_ejercicio_2();
	
	raices_ejercicio_3();
	
	return 0;
}


//EJERCICIO 1:
void raices_ejercicio_1() {
	double a = 0.0;
	double b = 2.5;
	double xr = -0.5;
	double xa = 2.0;
	double x0 = 0.0;
	double x1 = 2.0;
	double x2 = 2.0;
	double p0 = 0.5;
	double raiz = 0.0;
	int max_iter=1000000;
	double tolerancia=0.00000001;
	int intervalos = 100;
	int iteraciones = 0.0;
	
	
	//Regla falsa f(x)= -5x^4 - 5.4x^3 + 10.56x^2 + 8.954x + 1.6
	reglafalsa rf(
				  [](double x)->double {
					  return (-5.0 * pow(x,4) - 5.4 * pow(x,3) + 10.56 * pow(x,2) +8.954 * x + 1.6);
				  },
					  " "
					  );
	
	cout <<"METODO PARA PROBAR LA FUNCION EN EL EJERCICIO 1: "; 
	cout
		<< "\n\nMETODO DE REGLA FALSA\n" 
		<< rf.str()
		<< endl;
	
	cout << "Ingrese los valores xr y xa del intervalo para evaluar la funcion: ";
	
	cin >> xr >> xa;
	
	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
	
	cin >> intervalos;
	
	rf.tabla(xr, xa, intervalos);
	
	
//	cout << "Ingrese la tolerancia: ";
//	cin >> tolerancia;
	
	
	cout << "Ingrese el numero maximo de iteraciones: ";
	cin >> max_iter;
	
	
	bool resultadorf = rf.raiz (
								xa,
								xr,
								max_iter,
								tolerancia,
								raiz);	
	
	if(resultadorf == true) {
		cout << "Raiz encontrada: " << raiz << endl; 
	}else {
		cout << "No se encontro raiz con el metodo de regla falsa" << endl;
	}
	
	
	//Newton-Raphson f(x) = -5x^4 - 5.4x^3 + 10.56x^2 + 8.954x + 1.6
	newtonraphson nl(
					 [](double x)->double {
						 return -5.0 * pow(x,4) - 5.4 * pow(x,3) + 10.56 * pow(x,2) +8.954 * x + 1.6;
					 },
						 [](double x)->double {
							 return -20.0 * pow(x,3) - 16.2 * pow(x,2) + 21.12 * x + 8.954;
						 },
							 "f(x) = -5x^4 - 5.4x^3 + 10.56x^2 + 8.954x + 1.6" 
							 );
	
	cout <<"\n\nMETODO PARA PROBAR LA FUNCION EN EL EJERCICIO 1: ";
	cout
		<< "\n\nMETODO DE NEWTON RAPHSON\n"   
		<< nl.str() 
		<< endl;
	
	cout <<"Ingrese el valor inicial de x: ";
	cin >> p0;
	xr = p0 - 1;
	xa =  0.1;
	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
	
	cin >> intervalos;
	nl.tabla(xr, xa, intervalos);
	
	
	
	
//	cout <<"Ingrese la tolerancia: ";
//	cin >> tolerancia;
	
	cout <<"Ingrese la cantidad de iteraciones: ";
	cin >> iteraciones;
	
	if(nl.raiz(p0, tolerancia, iteraciones, raiz)) {
		cout << "Raiz encontrada: " << raiz << endl;
	}else {
		cout << "No se encontro raiz con el metodo newton raphson" <<endl;
	};
	
	
	//Metodo de Muller f(x) = -5x^4 - 5.4x^3 + 10.56x^2 + 8.954x + 1.6
	muller m(
			 [](double x)->double {
				 return (-5.0 * pow(x,4) - 5.4 * pow(x,3) + 10.56 * pow(x,2) + 8.954 * x + 1.6);
			 },
				 "f(x) = -5x^4 - 5.4x^3 + 10.56x^2 + 8.954x + 1.6"
				 );
	
	cout <<"\n\nMETODO PARA PROBAR LA FUNCION EN EL EJERCICIO 1: ";
	cout
		<< "\n\nMETODO DE MULLER\n"
		<< m.str()
		<< endl;
	
	cout << "Ingrese los valores x0  x1 y x2 del intervalo para evaluar la funcion: ";
	
	cin >> x0 >> x1 >> x2;
	
	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
	
	cin >> intervalos;
	
	m.tabla(x0, x1, x2, intervalos);
	
	
//	cout << "Ingrese la tolerancia: ";
//	cin >> tolerancia;
//	
	
	cout << "Ingrese el numero maximo de iteraciones: ";
	cin >> max_iter;
	
	
	if(m.raiz(x0, x1, x2, max_iter, tolerancia, raiz, iteraciones)) {
		cout << "Raiz encontrada: " << raiz << endl; 
	}else {
		cout << "No se encontro raiz con el metodo Muller" << endl;
	}
}


//Caso 2:
void raices_ejercicio_2() {
	double a = 0.0;
	double b = 2.5;
	double xi = 0.0;
	double xs = 2.0;
	double x0 = 0.0;
	double x1 = 2.0;
	double x2 = 2.0;
	double p0;
	double raiz = 0.0;
	int max_iter = 100;
	int intervalos = 100;
	int iteraciones = 100;
	double tolerancia = 0.0000000001;
	
//	//biseccion
//	biseccion bl(
//				 [](double x) -> double {
//					 return pow(x,3) + (4*(pow(x, 2))) - 10;
//				 },
//					 "f(x) = x^3 + 4x^2- 10"
//					 );
//	
//	cout << "\nCALCULO DE LAS RAICES DE UNA FUNCION CASO 2  \n";
//	
//	cout
//		<< "\nMetodo de biseccion: "
//		<< bl.str()
//		<< endl;
//	
//	cout << "Ingrese los valores a y b del intervalo para evaluar la funcion: ";
//	
//	cin >> a >> b;
//	
//	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
//	
//	cin >> intervalos;
//	
//	bl.tabla(a, b, intervalos);
//	
//	cout << "Ingrese la tolerancia: ";
//	cin >> tolerancia;
//	
//	cout << "Ingrese el numero maximo de iteraciones: ";
//	cin >> max_iter;
//	
//	bool resultadobl = bl.raiz(
//							   a,
//							   b,
//							   max_iter,
//							   tolerancia,
//							   raiz);	
//	
//	if(resultadobl == true) {
//		cout << "Raiz encontrada: " << raiz << endl; 
//	}else {
//		cout << "No se pudo encontrar la raiz con los parametros dados " << endl;
//	}
//	
	
	//Regla falsa
	reglafalsa rf(
				  [](double x) -> double {
					  return (pow(10,-9) * (pow(450+273,4)-pow(x+273,4))-224.243047824);
				  },
					  "f(x) = (10^(-9))[(450 + 273)^4 - (x + 273)^4]-224.243047824"
					  );
	reglafalsa rf2(
				   [](double x) -> double {
					   return (1.3 * pow((x - 25), 4/3 )-224.243047824);
				   },
					   "g(x) = 1.3*(x -25)^(4/3)-224.243047824"
					   );
	cout <<"METODO PARA PROBAR LA FUNCION EN EL EJERCICIO 2: "; 
	cout
		<< "\nMetodo de regla falsa funcion 2.1:  "
		<< rf.str()
		<< endl;
	cout
		<< "\nMetodo de regla falsa funcion 2.2:  "
		<< rf2.str()
		<< endl;
	
	cout << "Ingrese los valores xi y xs del intervalo para evaluar las funciones: ";
	
	cin >> xi >> xs;
	
	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
	
	cin >> intervalos;
	
	rf.tabla(xi, xs, intervalos);
	rf2.tabla(xi, xs, intervalos);
	
	
//	cout << "Ingrese la tolerancia: ";
//	cin >> tolerancia;
	
	
	cout << "Ingrese el numero maximo de iteraciones: ";
	cin >> max_iter;
	
	
	bool resultadorf = rf.raiz (
								xi,
								xs,
								max_iter,
								tolerancia,
								raiz);	
	cout << "f(x)";
	if(resultadorf == true) {
		cout << "Raiz de f(x) encontrada: " << raiz << endl; 
	}else {
		cout << "No se pudo encontrar la raiz de f(x) con los parametros dados " << endl;
	}
	
	bool resultadorf2 = rf2.raiz (
								xi,
								xs,
								max_iter,
								tolerancia,
								raiz);	
	cout << "g(x)";
	if(resultadorf2 == true) {
		cout << "Raiz de g(x) encontrada: " << raiz << endl; 
	}else {
		cout << "No se pudo encontrar la raiz de g(x) con los parametros dados " << endl;
	}
	
	
//	//netown Raphson
//	newtonraphson nl(
//					 [](double x) -> double {
//						 return (pow(10,-9) * (pow(450+273,4)-pow(x+273,4))-224.243047824);
//					 },
//						 [](double x) -> double {
//							 return pow(10,-9) * (-4 * 273 * pow(x+273,3));
//						 },
//							 "f(x) = (10^(-9))[(450 + 273)^4 - (x + 273)^4]-224.243047824"
//							 );
//	
//	
//	
//	
//	cout
//		<< "\nMetodo de Newton-Raphson: "
//		<< nl.str() 
//		<< endl;
//	
//	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
//	
//	cin >> intervalos;
//	nl.tabla(a, b, intervalos);
//	
//	cout <<"Ingrese el valor inicial de x: ";
//	cin >> p0;
//	
////	cout <<"Ingrese la tolerancia: ";
////	cin >> tolerancia;
//	
//	cout <<"Ingrese la cantidad de iteraciones: ";
//	cin >> iteraciones;
//	
//	if(nl.raiz(p0, tolerancia, iteraciones, raiz)) {
//		cout << "Raiz encontrada: " << raiz << endl;
//	}else {
//		cout << "No se pudo encontrar la raiz con los parametros dados" <<endl;
//	};
//	
	
	//Secante
	secante sc(
			   [](double x) -> double {
				   return (pow(10,-9) * (pow(450+273,4)-pow(x+273,4))-224.243047824);
			   },
				   "f(x) = (10^(-9))[(450 + 273)^4 - (x + 273)^4]-224.243047824"
				   );
	secante sc2(
				   [](double x) -> double {
					   return (1.3 * pow((x - 25), 4/3 )-224.243047824);
				   },
					   "g(x) = 1.3*(x -25)^(4/3)-224.243047824"
					   );
	cout <<"METODO PARA PROBAR LA FUNCION EN EL EJERCICIO 2: "; 
	cout
		<< "\nMetodo de la secante funcion 2.1:  "
		<< sc.str()
		<< endl;
	cout
		<< "\nMetodo de la secante funcion 2.2:  "
		<< sc2.str()
		<< endl;
	
	
	cout << "Ingrese los valores x0 y x1 del intervalo para evaluar las funciones: ";
	
	cin >> x0 >> x1;
	
	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
	
	cin >> intervalos;
	
	sc.tabla(x0, x1, intervalos);
	sc2.tabla(x0, x1, intervalos);
	
	
//	cout << "Ingrese la tolerancia: ";
//	cin >> tolerancia;
	
	
	cout << "Ingrese el numero maximo de iteraciones: ";
	cin >> max_iter;
	
	
	bool resultadosc = sc.raiz (
								x0,
								x1,
								max_iter,
								tolerancia,
								raiz);	
	cout << "f(x)";
	if(resultadosc == true) {
		cout << "Raiz encontrada en f(x): " << raiz << endl; 
	}else {
		cout << "No se pudo encontrar la raiz de f(x) con los parametros dados " << endl;
	}
	bool resultadosc2 = sc2.raiz (
								x0,
								x1,
								max_iter,
								tolerancia,
								raiz);	
	cout << "g(x)";
	if(resultadosc2 == true) {
		cout << "Raiz encontrada: " << raiz << endl; 
	}else {
		cout << "No se pudo encontrar la raiz g(x) con los parametros dados " << endl;
	}
	
	//Metodo de Muller f(x) = sen(2x) + 2e^(-2x)sen(x) - 2e^(-x)sen(2x) - e^(-2x)
	muller m(
			 [](double x)->double {
				 return sin(2*x) + 2 * exp(-2*x) * sin(x) - 2 * exp(-x) * sin(2*x)- exp(-2*x);
			 },
				 "f(x) = sen(2x) + 2e^(-2x)sen(x) - 2e^(-x)sen(2x) - e^(-2x) "
				 );
	
	muller m2(
			  [](double x) -> double {
				  return (1.3 * pow((x - 25), 4/3 )-224.243047824);
			  },
				  "g(x) = 1.3*(x -25)^(4/3)-224.243047824"
				  );
	
	
	
	cout <<"METODO PARA PROBAR LA FUNCION EN EL EJERCICIO 2: "; 
	cout
		<< "\n\nMETODO DE MULLER f(x)\n"
		<< m.str()
		<< endl;
	cout
		<< "\n\nMETODO DE MULLER g(x)\n"
		<< m2.str()
		<< endl;
	
	cout << "Ingrese los valores x0  x1 y x2 del intervalo para evaluar la funcion: ";
	
	cin >> x0 >> x1 >> x2;
	
	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
	
	cin >> intervalos;
	
	m.tabla(x0, x1, x2, intervalos);
	m2.tabla(x0, x1, x2, intervalos);
	
	cout << "Ingrese el numero maximo de iteraciones: ";
	cin >> max_iter;
	
	
	if(m.raiz(x0, x1, x2, max_iter, tolerancia, raiz, iteraciones)) {
		cout << "Raiz encontrada en f(x): " << raiz << endl; 
	}else {
		cout << "No se encontro raiz en f(x) con el metodo Muller" << endl;
	}
	
	if(m2.raiz(x0, x1, x2, max_iter, tolerancia, raiz, iteraciones)) {
		cout << "Raiz encontrada g(x): " << raiz << endl; 
	}else {
		cout << "No se encontro raiz en g(x)con el metodo Muller" << endl;
	}
}

//EJERCICIO 3:
void raices_ejercicio_3() {
	double a = 0.0;
	double b = 2.5;
	double xr = 0.0;
	double xa = 2.0;
	double x0 = 0.0;
	double x1 = 2.0;
	double x2 = 2.0;
	double p0 = 0;
	double raiz = 0.0;
	int max_iter = 100;
	int intervalos = 100;
	int iteraciones = 100;
	double tolerancia = 0.00000001;
	
	
	//Metodo de la regla falsa f(x) = sen(2x) + 2e^(-2x)sen(x) - 2e^(-x)sen(2x) - e^(-2x) 
	reglafalsa rf(
				  [](double x)->double {
					  return sin(2 * x) + 2 * sin(x) * exp((-2) * x)  - 2 * exp(-x) * sin(2 * x)- exp(-2 * x);
				  },
					  "f(x) = sen(2x) + 2e^(-2x)sen(x) - 2e^(-x)sen(2x) - e^(-2x) "
					  );
	
	cout <<"METODO PARA PROBAR LA FUNCION EN EL EJERCICIO 3: "; 
	cout
		<< "\n\nMETODO DE REGLA FALSA\n" 
		<< rf.str()
		<< endl;
	
	cout << "Ingrese los valores xr y xa del intervalo para evaluar la funcion: ";
	
	cin >> xr >> xa;
	
	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
	
	cin >> intervalos;
	
	rf.tabla(xr, xa, intervalos);
	
	
	cout << "Ingrese el numero maximo de iteraciones: ";
	cin >> max_iter;
	
	
	bool resultadorf = rf.raiz (
								xa,
								xr,
								max_iter,
								tolerancia,
								raiz);	
	
	if(resultadorf == true) {
		cout << "Raiz encontrada: " << raiz << endl; 
	}else {
		cout << "No se encontro raiz con el metodo de regla falsa" << endl;
	}
	
	
	
	
	//Secante f(x) = sen(2x) + 2e^(-2x)sen(x) - 2e^(-x)sen(2x) - e^(-2x) 
	secante sc(
			   [](double x)->double {
				   return sin(2*x) + 2 * exp(-2*x) * sin(x) - 2 * exp(-x) * sin(2*x)- exp(-2*x);
			   },
				   "f(x) = sen(2x) + 2e^(-2x)sen(x) - 2e^(-x)sen(2x) - e^(-2x) "				   );
	
	cout <<"METODO PARA PROBAR LA FUNCION EN EL EJERCICIO 3: "; 
	cout
		<< "\n\nMETODO DE SECANTE\n" 
		<< sc.str()
		<< endl;
	
	cout << "Ingrese los valores x0 y x1 del intervalo para evaluar la funcion: ";
	
	cin >> x0 >> x1;
	
	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
	
	cin >> intervalos;
	
	rf.tabla(x0, x1, intervalos);
	
	
	cout << "Ingrese el numero maximo de iteraciones: ";
	cin >> max_iter;
	
	
	bool resultadosc = sc.raiz (
								x0,
								x1,
								max_iter,
								tolerancia,
								raiz);	
	
	if(resultadosc == true) {
		cout << "Raiz encontrada: " << raiz << endl; 
	}else {
		cout << "No se encontro raiz con el metodo de secante " << endl;
	}
	
	
	//Metodo de Muller f(x) = sen(2x) + 2e^(-2x)sen(x) - 2e^(-x)sen(2x) - e^(-2x)
	muller m(
			 [](double x)->double {
				 return sin(2*x) + 2 * exp(-2*x) * sin(x) - 2 * exp(-x) * sin(2*x)- exp(-2*x);
			 },
				 "f(x) = sen(2x) + 2e^(-2x)sen(x) - 2e^(-x)sen(2x) - e^(-2x) "
				 );
	
	cout <<"\n\nMETODO PARA PROBAR LA FUNCION EN EL EJERCICIO 3: ";
	cout
		<< "\n\nMETODO DE MULLER\n"
		<< m.str()
		<< endl;
	
	cout << "Ingrese los valores x0  x1 y x2 del intervalo para evaluar la funcion: ";
	
	cin >> x0 >> x1 >> x2;
	
	cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
	
	cin >> intervalos;
	
	m.tabla(x0, x1, x2, intervalos);
	
	
	cout << "Ingrese el numero maximo de iteraciones: ";
	cin >> max_iter;
	
	
	if(m.raiz(x0, x1, x2, max_iter, tolerancia, raiz, iteraciones)) {
		cout << "Raiz encontrada: " << raiz << endl; 
	}else {
		cout << "No se encontro raiz con el metodo Muller" << endl;
	}
}


