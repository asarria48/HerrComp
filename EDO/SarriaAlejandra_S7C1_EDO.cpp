#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double f(double y){

  return -y;
}

int main(){

  double y0 = 1.0;    //condición inicial
  double t0 = 0.0;    //tiempo inicial
  double tf = 2.0;    //tiempo final
  double h = 0.01;
  int n = tf/h;
  double k1, k2, k3, k4;    //inicializo las variables para el Runge-Kutta
  
  double y[n];    //arreglo de tamaño n donde guardaré mis valores de y
  double t[n];

  t[0] = t0;
  y[0] = y0;
    
   for(int i = 0; i < n ; i++){

     y[i+1] = y[i] + h*(f(y[i]));
     t[i+1] = t[i] + h;
    
     cout << t[i] << " " << y[i] << "\n";
  }


  for(int i = 0; i < n; i++){

    k1 = h*f(y[i]);
    k2 = h*f(y[i] + (k1/2));
    k3 = h*f(y[i] + (k2/2));
    k4 = h*f(y[i] + k3);

    y[i+1] = y[i] + ((k1 + 2*k2 + 2*k3 + k4)/6);
    t[i+1] = t[i] + h;

    cout << t[i] << " " << y[i] << "\n";
  }

  ofstream outFile("datosEuler.txt");
  if(outFile.is_open()){
    for(int i = 0; i < n; i++){
      outFile << t[i] << " " << y[i] << "\n";
    }

    outFile.close();

  }

  return 0;
}
