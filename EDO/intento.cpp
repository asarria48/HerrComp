#include <iostream>
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
  
  int y[n];    //arreglo de tamaño n donde guardaré mis valores de y
  int t[n];
  
  t[0] = t0;
  y[0] = y0;
    
  for(int i = 0; i < n; i++){

    y[i+1] += y[i] + h*(f(y[i]));
    t[i+1] += t[i] + h;
    
    cout << t[i] << " " << y[i] << "\n";
  }


    
  return 0;
}
