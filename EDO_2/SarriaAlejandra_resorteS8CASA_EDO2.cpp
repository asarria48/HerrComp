#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double m = 0.2;
const double k = 50.0;

double f(double t, double x){

  return -k*x/m;
}

double s(double t){

  return 0.1*cos(sqrt(k/m)*t);
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


  //cout << abs((f(t[0],x[0]) - s(t[0]))/s(t[0])) << endl;


  ofstream outfile;
  outfile.open("euler_2.dat");

  outfile << t[0] << " , " << x[0] << endl;
  for(int i = 0; i < n; i++){
    outfile << t[i+1] << " , " << x[i+1] << endl;
  }

  outfile.close();
  

  v[0] = v0 + 0.5*h*f(t[0],x[0]);
  
  for(int i = 0; i < n; i++){

    x[i+1] = x[i] + h*v[i];
    v[i+1] = v[i] + h*f(t[i+1],x[i+1]);
    t[i+1] = t[i] + h;

  }

  //cout << abs((f(t[0],x[0]) - s(t[0]))/s(t[0])) << endl;

    ofstream outFile;
  outFile.open("leapfrog_2.dat");

  outFile << t[0] << " , " << x[0] << endl;
  for(int i = 0; i < n; i++){
    outFile << t[i+1] << " , " << x[i+1] << endl;
  }

  outFile.close();

  
  double k1x, k2x, k3x, k4x;
  double k1v, k2v, k3v, k4v;
  
  t[0] = t0;
  x[0] = x0;
  v[0] = v0;

  for(int i = 0; i < n; i++){

    k1x = f(t[i],x[i]);
    k1v = f(t[i],v[i]);
    k2x = f(t[i] + h/2 , x[i] + (h/2)*k1x);
    k2v = f(t[i] + h/2 , v[i] + (h/2)*k1v);
    k3x = f(t[i] + h/2 , x[i] + (h/2)*k2x);
    k3v = f(t[i] + h/2 , v[i] + (h/2)*k2v);
    k4x = f(t[i] + h , x[i] + h*k3x);
    k4v = f(t[i] + h , v[i] + h*k3v);

    x[i+1] = x[i] + h*(k1x + 2*k2x + 2*k3x + k4x)/6;
    v[i+1] = v[i] + h*(k1v + 2*k2v + 2*k3v + k4v)/6;
    t[i+1] = t[i] + h;
  }

   ofstream Outfile;
  Outfile.open("rungekutta_2.dat");

  Outfile << t[0] << " , " << x[0] << endl;
  for(int i = 0; i < n; i++){
    Outfile << t[i+1] << " , " << x[i+1] << endl;
  }

  Outfile.close();

  return 0;
}
