//#1a)
/*
x = range (10)
#print (x)
a=range(0,1000,3)
print(a)
b=range(0,1000,5)
c=(a,b)
print(c)
d=set(a)|set(b)
print d
e=sum (d)
print e
*/

//Ahora en C

#include "stdio.h"


int sum(int *v, int x, int i); //alocar espacio de memoria v de tamaño x


//Definición de variables
int main() {
  int i; //contador
  int x = 1000; 
  int *v;

/*printf("Introduce un numero entero\n");
scanf(" %d",&x); //Guarda el número introducido por el usuario en la variable x
  */ 
  
  for (i=1;i<=x;i++) {
     if ((x % 3 == 0 ) || (x % 5 == 0) ) {
	v[i]=x; }
     else { 
        v[i]=0; }
  }
//  printf("%d\n",v[i])
  return 0;} 

int sum(int *v, int x, int i){
  int e;
  for (i=1;i<=x;i++) {
     e += v[i];
   } 
   
   printf( "La suma total es %d\n", e );
   
return e;}

