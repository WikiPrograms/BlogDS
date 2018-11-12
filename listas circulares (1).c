#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
	int dato;
	struct nodo* sig;
}nodo;
nodo* inicio=NULL;
nodo * fin= NULL;
void insertar();
void ver();
void buscar();
void eliminar();
int main(int argc, char *argv[]) {
	int opc;
	while(opc!=5){
		printf("\n\nQue desea hacer\n\t1.- Insertar\n\t 2.- Ver\n\t3.- Buscar\n\t4.- Eliminar\n\t5.- Salir\n: ");
		scanf("%d",&opc);
		switch(opc){
		case 1:
			insertar();
			break;
		case 2:
			ver();
			break;
		case 3:
			buscar();
			
			break;
		case 4:
			eliminar();
			break;
		}
	}
	
	return 0;
}
void insertar(){
	nodo* nuevoNodo=(nodo*)malloc(sizeof(nodo));
	printf("\nIngrese dato: ");
	scanf("%d",&nuevoNodo->dato);
	if(inicio==NULL){
		inicio=nuevoNodo;
		inicio->sig=nuevoNodo; //el inicio si es el primero en agregarse el debe apuntarse a si mismo
		fin=nuevoNodo;
		// en este caso el ultimo no apunta a null sino apunta a inicio
	}else{
		fin->sig=nuevoNodo;
		nuevoNodo->sig=inicio; //si ya hay datos, el ultimo dato o nuevonodo debera apuntar a inicio
		fin=nuevoNodo;
	}
	printf("\nNodo ingresado con exito\n");
}
void ver(){
	nodo* aux=(nodo*)malloc(sizeof(nodo));
	aux=inicio;
	if(aux!=NULL){
		do{ //Un do while porque a diferencia de las listas simples existe un enlace que es null que es del ultimo, en las circulares
			//no existe un enlace null, por ello el do while se sigue repitiendo mientras que aux sea diferente a inicio y no mientras sea diferente que null
			//si fuera con while aux!=null se haria un bucle infinito porque nunca encontrara un enlace que sea null
			printf("%d",aux->dato);
			printf(" -> ");
			aux=aux->sig;
		}while(aux!=inicio);
	}else{
		printf("\nLista vacia\n");
	}
}
void buscar(){
	nodo* aux=(nodo*)malloc(sizeof(nodo));
	aux=inicio;
	int b,e=0;
	printf("\nIngrese valor a buscar: ");
	scanf("%d",&b);
	if(aux!=NULL){
		do{
			if(aux->dato==b){
				printf("\nEncontrado [%d]\n",aux->dato);
				e=1;
			}
			aux=aux->sig;
		} while(aux!=inicio);
		if(e==0){
			printf("\nNo esta\n");
		}
	}else{
		printf("\nLista vacia\n");
	}
}
void eliminar(){
	nodo* aux=(nodo*)malloc(sizeof(nodo));
	aux=inicio;
	nodo * anterior=(nodo*)malloc(sizeof(nodo)); //creamos un nuevo apuntador que nos ayudara a ligar la lista
	anterior=NULL; //le damos valor de NULL porque no esta ligada con nada
	int b,e=0;
	printf("\nIngrese valor a buscar: ");
	scanf("%d",&b);
	if(aux!=NULL){
		do{
			if(aux->dato==b){
				printf("\nEncontrado [%d]\n",aux->dato);
				//Hay que considerar tres casos: 1.- Que es un elemento que esta inmedio de la lista, 2.- Que es el incio de la lista, 3.- Que es el final de la lista.
				if(aux==inicio){
					inicio=inicio->sig;
					fin->sig=inicio;
				}else{
					if(aux==fin){
						anterior->sig=inicio;
						fin = anterior;
					}else{
						anterior->sig = aux->sig;
					}
				}
				e=1;
			}
			anterior = aux;
			aux=aux->sig;
		} while(aux!=inicio && e!=1);
		if(e==0){
			printf("\nNo esta\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\nLista vacia\n");
	}
}
