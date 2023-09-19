#include <iostream>
#include <cstdlib>  //Necesito ambas librerías para generar la semilla de aleatoriedad 
#include <ctime>
#include <cmath>  //La necesito para usar la función pow()
using namespace std;

//8. Hacer una función que eleve al exponente
float pow_func(float mivarflotante, int mivarentera){ //Defino la función al inicio, antes de mi función main

  return pow(mivarflotante, mivarentera);
}

//10.0 Hacer una función que retorne el mínimo del arreglo antes creado 
int minimum(int arreglo[], int N){ //La función recibe el arreglo y su tamaño

  int min = arreglo[0]; //supongo que el mínimo inicialmente es el primer valor del arreglo 

  for(int i = 1; i < N ;i++){  //inicializo desde la posición 1 porque el primer mínimo ya está en 0; la condición de i es que esté dentro del tamaño del arreglo
  
   if(arreglo[i] < min){  //Hago un if para establecer la condición, si el número en la posición i es menor que min
     
    min = arreglo[i];  //actualizo el mínimo, y así para cada número del arreglo
   }
 }

  return min; //un error que cometí fue poner el return dentro del for, así no funcionaba la iteración, el return debe ir fuera del for al finalizar la función
}

//11.0 Hacer una función que retorne los impares menores a 800 del arreglo e imprimir los valores
void odd(int arreglo[], int N){  //Esta función no tiene que retornar algo, solo cumplir la instrucción, por lo que es tipo void
  for(int i = 0; i < N; i++){

    if(arreglo[i] > 800){  //Si el número es mayor a 800, se rompe el ciclo
      break;
    }
    if(arreglo[i] % 2 != 0){  //Para verificar que los números sean impares

      cout << arreglo[i] << "\n";  //En caso de que lo sean,, imprimirlos
    }

  }
}

int main(){

//1. Inicializar dos variables globales, una entera y una flotante

  int XX = 2;
  float YY = 2.5;

//2. Imprimir las variables
  cout <<"La primera variable tiene un valor de "<< XX <<" y la segunda tiene un valor de "<< YY <<"\n";

//3. Calcular e imprimir la división de las variables
  float division = YY/XX;
  cout <<"El resultado de la división es "<< division <<"\n";

//4. Generar un arreglo de 300 números enteros aleatorios entre 0 y 900
  srand(time(nullptr)); //semilla de aleatoriedad que cambia cada que ejecuto el código

  int N = 300;  //tamaño del arreglo que necesito
  int arreglo[N]; //creo un arreglo vacío del tamaño que requiero, en este caso 300
   
//5. Hacer una iteración para recorrer el arreglo e imprimir todos sus valores
  for (int i = 0; i < N; i++){  //El primer término sirve para inicializar la variable, el segundo establece la condición, y el tercero suma en cada iteración
   arreglo[i] = rand() % 901;  //Con la función rand() y el módulo, se genera un valor entre 0 y 900
   
   cout << arreglo[i] <<"\n"; //imprimo mi arreglo con cada valor de i 
 }
 
//6. Imprimir el quinto número del arreglo
  cout << "El quinto valor del arreglo es " <<arreglo[4] <<"\n"; //imprimo el quinto elemento de mi arreglo (por fuera del for para que no haya problemas)

//7. Obtener la longitud del arreglo e imprimirla
   int length = sizeof(arreglo) / sizeof(arreglo[0]); //La función sizeof() me retorna el tamaño ocupado en bytes de todo mi arreglo, para obtener el tamaño del arreg   lo como tal, debo dividir sobre un dato de este

   cout <<"El tamaño del arreglo es "<< length <<"\n";

//9. Llamar la función que eleva al exponente y meterle los valores indicados
   float mivarflotante = 17.5;
   int mivarentera = 5;
   cout << mivarflotante << " elevada a la " << mivarentera << " es: " << pow_func(mivarflotante, mivarentera) <<"\n";  //Llamo a la función pow_fun desde la función main

//10.1 Imprime lo que retorna la función del mínimo con el arreglo
   cout << "El mínimo del arreglo es " << minimum(arreglo, N) <<"\n"; //Tanto a minimum como a odd les pongo los parámetros necesarios para que trabajen sobre mi arreglo previamente hecho

//11.1 Llamar a la función e introducirle el arreglo
   
   odd(arreglo, N);
   
 return 0;
     
}
