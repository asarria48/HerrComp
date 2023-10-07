#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double m = 0.2;
const double k = 50.0;

double f(double t, double x){

  return -k*x/m;
}

int main(){

  double x0 = 0.1;
  double v0 = 0.0;
  double t0 = 0.0;
  double tf = 2.0;
  double h = 0.01;

  int n = (tf - t0)/h;

  double x[n];
  double v[n];
  double t[n];

  x[0] = x0;
  v[0] = v0;
  t[0] = t0;

  for(int i = 0; i < n; i++){

    x[i+1] = x[i] + h*v[i];
    v[i+1] = v[i] + h*f(t[i],x[i]);
    t[i+1] = t[i] + h;

  }

  ofstream outfile;
  outfile.open("euler_2.dat");

  outfile << t[0] << " , " << x[0] << endl;
  for(int i = 0; i < n; i++){
    outfile << t[i+1] << " , " << x[i+1] << endl;
  }

  outfile.close();
  

  for(int i = 0; i < n; i++){

    x[i+1] = x[i] + h*v[i];
    v[i+1] = v[i] + h*f(t[i+1],x[i+1]);
    t[i+1] = t[i] + h;

  }

    ofstream outFile;
  outFile.open("leapfrog_2.dat");

  outFile << t[0] << " , " << x[0] << endl;
  for(int i = 0; i < n; i++){
    outFile << t[i+1] << " , " << x[i+1] << endl;
  }

  outFile.close();

  return 0;
}
