#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double G = 6.67430e-11;    //Constante gravitacional
const double ms = 1.989e30;      //Masa del Sol (kg)
const double mt = 5.972e24;      //Masa de la Tierra (kg)


void Euler(double& x,double& y, double& z, double& vx, double& vy, double& vz, double& dt){    //Función void: no retorna nada pero cumple una tarea
                                                                                               //& quiere decir que la función puede cambiar el parámetro
  double r = sqrt(x*x + y*y + z*z);         //Distancia entre la Tierra y el Sol
  double f = (G*ms*mt)/(r*r);               //Fuerza de gravitación

  double ax = (-f/mt)*x;                           //Aceleración en x
  double ay = (-f/mt)*y;                           //Aceleración en y
  double az = (-f/mt)*z;                           //Aceleración en z

  vx = vx + ax*dt;                          //Actualización de la velocidad en x, y, y z en función de la aceleración y el paso del tiempo
  vy = vy + ay*dt;
  vz = vz + az*dt;

  x = x + vx*dt;                            //Actualización de la posición en x, y, y z en función de la velocidad y el paso del tiempo 
  y = y + vy*dt;
  z = z + vz*dt;
  
}
  
int main(){

  double x = 1.475e11;               //Distancia entre la Tierra y el Sol en el perihelio (m) (distancia inicial)
  double y = 0.0;
  double z = 0.0;
  
  double r = sqrt(x+x + y*y + z*z);  //distancia inicial entre la Tierra y el Sol 
  double f = (G*ms*mt)/(r*r);        //Fuerza de gravedad inicial entre la Tierra y el Sol

  double vx = 0.0;
  double vy = 3.0750e4;              //Velocidad de la Tierra en el perihelio (m/s) (velocidad inicial)
  double vz = 0.0;

  double ax, ay, az;                 //Aceleración de la Tierra en el perihelio (m/s^2)

  double dt = 3600.0;                //Paso del tiempo (s) (una hora)

  int n = 365*24;                    //Un año en horas
  
  for(int i = 0; i < n; i++){

    Euler(x, y, z, vx, vy, vz, dt);

    cout << i+1 << " " << sqrt(x*x + y*y + z*z) << endl;

  ofstream outfile("planetasEuler.dat");
  outfile << i+1 << " , " << sqrt(x*x + y*y + z*z) << endl;
  outfile.flush();
  
  }


  return 0;
}
