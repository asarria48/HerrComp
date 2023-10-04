#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const double k = 50.0;
const double m = 0.2;

double f(double x){

  return -(k/m)*x;
}

int main(){

  double x0 = 0.1;
  double v0 = 0.0;
  double t0 = 0.0;
  double tf = 2.0;
  double h = 0.01;
  int n = tf/h;

  double x[n];
  double v[n];
  double t[n];

  v[0] = v0;
  x[0] = x0;
  t[0] = t0;

  for(int i = 0; i < n - 1; i++){

    v[i+1] = v[i] + h*f(x[i]);
    x[i+1] = x[i] + h*v[i];
    t[i+1] = t[i] + h;

    cout << t[i] << " "  << x[i] << "\n";
  }

  ofstream outfile;
  outfile.open("euler2.dat");

  outfile << t[0] << "," << x[0] << "\n";
  for(int i = 0; i < n; i++){
  outfile << t[i+1] << "," << x[i+1] << "\n";
  }

  outfile.close();

  return 0; 
}
