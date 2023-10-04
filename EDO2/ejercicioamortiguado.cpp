#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double k = 50.0;
const double m = 0.1;
const double b = 0.08;

double f(double x, double v){

  return -(k/m)*x - b*v;
}

int main(){

  double x0 = 0.1;
  double v0 = 0.0;
  double t0 = 0.0;
  double tf = 2.0;
  double h = 0.01;
  int n = (tf - t0)/h;

  double x[n], v[n], t[n];

  x[0] = x0;
  v[0] = v0;
  t[0] = t0;

  for(int i = 0; i < n; i++){

    v[i+1] = v[i] + h*f(x[i],v[i]);
    x[i+1] = x[i] + h*v[i];
    t[i+1] = t[i] + h;

    cout << t[i] << " " << x[i] << endl;
    
  }

  ofstream outfile;
  outfile.open("euleramor.dat");

  outfile << t[0] << " , " << x[0] << endl;
  for(int i = 0; i < n; i++){
  outfile << t[i+1] << " , " << x[i+1] << endl;
  }

  outfile.close();


  return 0;
}
