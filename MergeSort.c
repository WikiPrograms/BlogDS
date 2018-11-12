#include <stdio.h>
#include <stdlib.h>
void mergeSort(int a[],int izq, int der, int n);
int main(int argc, char *argv[]) {
	int n,i,izq,der;
	printf("\nTamaño: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		a[i]=rand()%n;
	}
	printf("\nLista desordenada\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		printf("\n");
	}
	izq = 0;
	der = n-1;
	mergeSort(a,izq,der,n);
	printf("\nLista ordenada\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
void mergeSort(int a[],int izq, int der,int n){
	int i,j,k,l;
	int array[n]; //arreglo auxiliar para los cortes
	//verificamos hasta cuando se va a cortar nuestro arreglo
	if(der>izq){
		//determinamos la mitad del arreglo
		l = (der + izq)/2;
		//Lo cortamos por la mitad pasando como parametro el
		//arreglo desde la posicion inicial hasta la siguiente mitad
		mergeSort(a,izq,l,n);
		//cortamos pasando por parametros el arreglo desde la posicion
		// de la mitad hasta la posicion final
		mergeSort(a,l+1,der,n);
		//recorremos el arreglo ya cortado
		for(i=l+1;i>izq;i--){
			//Asignamos los elementos a un arreglo auxiliar
			array[i-1]= a[i-1];
		}
		//recorremos el arreglo ya cortado
		for(j=l;j<der;j++){
			//Asignamos los elementos a un arreglo auxiliar
			array[der+l-j]= a[j+1];
		}
		//recorremos el arreglo temporal
		//recorremos el arreglo ya cortado
		for(k=izq;k<=der;k++){
			//Para determinar cual es el elemento menor
			if(array[i]<array[j]){
				a[k]=array[i++];
			}else{
				a[k]= array[j--];
			}
		}
	}
}
