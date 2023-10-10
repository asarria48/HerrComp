#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

//Para este ejercicio llevaré las unidades a algo que me convenga

const double ms = 1.0;              //La masa del Sol será la unidad
const double mt = 1.0/328900.56;    //Lo que es la masa de la Tierra proporcional a la del Sol
const double kg = 1.0/1.9891e30;    //Lo que significa un kilogramo respecto a la masa del Sol

const double m = 6.68459e-12;       //Metros en una unidad astronómica (distancia entre la Tierra y el Sol)

const double s = 3.17098e-8;        //Segundos en un año

const double G = (6.67428e-11)*m*m*m/(kg*s*s);    //Constante gravitacional (m^3/kg*s^2) (pasándolo a las unidades que estoy usando)

double fx(double t, double x, double y){    //Función para resolver la ecuación de la órbita en x. Mi compañero Juan Diego Parales me ayudó a llegar a las ecuaciones 
                                            //que debo resolver
  return -(G*x)/pow(x*x + y*y , 3/2);
}  

double fy(double t, double x, double y){    //Función para resolver la ecuación de la órbita en y

  return -(G*y)/pow(x*x + y*y , 3/2);
}


int main(){
  
  double x0 = 0.983;                   //Distancia entre la Tierra y el Sol en el perihelio
  double y0 = 0.0;           
    
  double vx0 = 0.0;
  double vy0 = 30750*m/s;              //Velocidad de la Tierra en el perihelio (pasándolo a las unidades que estoy usando)

  double t0 = 0.0;
  double tf = 2.0;                     //Tiempo en años
  
  double h = 0.001;
  
  int n = tf/h;

  double x[n];
  double y[n];
  double vx[n];
  double vy[n];
  double t[n];

  // Método de Euler:

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


  // Método de Leapfrog:

  x[0] = x0;
  y[0] = y0;

  vx[0] = vx0 + (h/2)*fx(t[0], x[0], y[0]);    //Inicialización de leapfrog para vx
  vy[0] = vy0 + (h/2)*fy(t[0], x[0], y[0]);    //Inicialización de leapfrog para vy

  t[0] = t0;

  for(int i = 0; i < n; i++){

    x[i+1] = x[i] + h*vx[i];
    y[i+1] = y[i] + h*vy[i];

    vx[i+1] = vx[i] + fx(t[i+1], x[i+1], y[i+1]);
    vy[i+1] = vy[i] + fy(t[i+1], x[i+1], y[i+1]);

    t[i+1] = t[i] + h;
    
  }

  ofstream Outfile;
  Outfile.open("LeapfrogPlanetas.dat");

  Outfile << t[0] << " , " << x[0] << " , " << y[0] << endl;

  for(int i = 0; i < n; i++){

    Outfile << t[i+1] << " , " << x[i+1] << " , " << y[i+1] << endl;
  }
  

  Outfile.close();

  
  return 0;
}
