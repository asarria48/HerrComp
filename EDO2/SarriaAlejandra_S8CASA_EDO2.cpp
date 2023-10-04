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
  double v_med = v0 + 0.5*h*f(x0);
  double k1x, k1v, k2x, k2v, k3x, k3v, k4x, k4v;

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

  v[0] = v_med;

  for(int i = 0; i < n; i++){

    v[i+1] = v[i] + h*f(x[i+1]);
    x[i+1] = x[i] + h*v[i];
    t[i+1] = t[i] + h;

    cout << t[i] << " " << x[i] << "\n";

  }

    ofstream outFile;
  outFile.open("leapfrog2.dat");

  outFile << t[0] << "," << x[0] << "\n";
  for(int i = 0; i < n; i++){
  outFile << t[i+1] << "," << x[i+1] << "\n";
  }

  for(int i = 0; i < n; i++){

    k1x = h*f(x[i]);
    k1v = h*f(v[i]);
    k2x = h*f(x[i] + (k1x/2));
    k2v = h*f(v[i] + (k1v/2));
    k3x = h*f(x[i] + (k2x/2));
    k3v = h*f(v[i] + (k2v/2));
    k4x = h*f(x[i] + k3x);
    k4v = h*f(v[i] + k3v);

    x[i+1] = x[i] + (1/6)*(k1x + 2*k2x + 2*k3x + k4x);
    v[i+1] = v[i] + (1/6)*(k1v + 2*k2v + 2*k3v + k4v);

    t[i+1] = t[i] + h;

    cout << t[i] << " " << x[i] << "\n";
    //cout << t[i] << " " << v[i] << "\n";

  }

  ofstream Outfile;
  Outfile.open("RK2.dat");

  Outfile << t[0] << "," << x[0] << "\n";
  for(int i = 0; i < n; i++){
  Outfile << t[i+1] << "," << x[i+1] << "\n";
  }
  
  
  return 0; 
}
