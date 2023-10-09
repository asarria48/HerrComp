#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double G = 6.67430e-11;    //Constante gravitacional (m^3/kg*s^2)
const double ms = 1.989e30;      //Masa del Sol (kg)
const double mt = 5.972e24;      //Masa de la Tierra (kg)

double fx(double t, double x, double y){    //Función para resolver la ecuación de la órbita en x. Mi compañero Juan Diego Parales me ayudó a llegar a las ecuaciones 
                                            //que debo resolver
  return -(G*x)/pow(x*x + y*y , 3/2);
}

double fy(double t, double x, double y){    //Función para resolver la ecuación de la órbita en y

  return -(G*y)/pow(x*x + y*y , 3/2);
}


int main(){

  double x0 = 1.475e11;           //Distancia entre la Tierra y el Sol en el perihelio
  double y0 = 0.0;           

  double vx0 = 0.0;
  double vy0 = 3.075e4;           //Velocidad de la Tierra en el perihelio

  double t0 = 0.0;
  double tf = 3.154e7;            //Un año en segundos

  double h = 0.001;
  
  int n = tf/h;

  double x[n], y[n];
  double vx[n], vy[n];
  double t[n];

  x[0] = x0;
  y[0] = y0;

  vx[0] = vx0;
  vy[0] = vy0;

  t[0] = t0;

  for(int i = 0; i < n; i++){

    x[i+1] = x[i] + h*vx[i];
    y[i+1] = y[i] + h*vy[i];

    vx[i+1] = vx[i] + h*fx(t[i], x[i], y[i]);
    vy[i+1] = vy[i] + h*fy(t[i], x[i], y[i]);
    
    t[i+1] = t[i] + h;
    
  }

  ofstream outfile;
  outfile.open("EulerPlanetas.dat");

  outfile << t[0] << " , " << x[0] << " , " << y[0] << endl;
  
  for(int i = 0; i < n; i++){
    outfile << t[i+1] << " , " << x[i+1] << " , " << y[i+1] << endl;
  }

  outfile.close();


  return 0;
}
