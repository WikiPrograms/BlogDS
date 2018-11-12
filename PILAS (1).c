#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
}nodo;

nodo* primero =NULL;

void insertarNodo();
void desplegarPila();
void buscarNodo();
void eliminarNodo();
int main(int argc, char *argv[]) {
	int menu=0;
	do{
		printf("\n\t1.- Insertar dato\n\t2.-Buscar un nodo en la pila\n\t3.- Eliminar un nodo de la pila\n\t4.-Desplegar pila de datos\n\t5.-Salir\n");
		scanf("%d",&menu);
		switch(menu){
		case 1:
			printf("\n\tInsertar dato\n\n");
			insertarNodo();
			break;
		case 2:
			printf("\n\tBuscar un nodo en la pila\n\n");
			buscarNodo();
			break;
		case 3:
			printf("\n\tEliminar un nodo de la pila\n\n");
			eliminarNodo();
			break;
		case 4:
			printf("\n\tDesplegar pila de datos\n\n");
			desplegarPila();
			break;
		case 5:
			printf("\n\tSalir");
			break;
		default:
			printf("Invalido\n");
		}
	} while(menu!=5);
	return 0;
}

void insertarNodo(){
	nodo* nuevo= (nodo*)malloc(sizeof(nodo));
	printf("Ingrese dato: ");
	scanf("%d",&nuevo->dato); //para especificar que se va a guardar en la parte de dato
	nuevo->siguiente = primero; //cada que se ingresa un nuevo nodo, el inicio se pasa al final
	//y el nuevo nodo se liga con el primero(ultimo)
	primero = nuevo;
	//el apuntador primero apuntara al nuevo y el que fue primero anterior se va guardando en la pila
}
void buscarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodobuscado=0,encontrado=0;
	printf("Ingrese el dato del nodo a buscar: ");
	scanf("%d",&nodobuscado);
	if(actual!=NULL){
		while(actual!=NULL){
			if(actual->dato==nodobuscado){
				printf("El nodo con el dato (%d) Encontrado\n",nodobuscado);
				encontrado=1;
			}
			actual=actual->siguiente;
		}
		if(encontrado==0){
			printf("No encontrado\n");
		}
	}
	else{
		printf("La pila se encuentra vacia\n");
	}
}
void desplegarPila(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if(actual!=NULL){
		while(actual!=NULL){
			printf("%d\n",actual->dato);
			actual =actual-> siguiente;
		}
	}
	else{
		printf("La pila se encuentra vacia\n");
	}
}
void eliminarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior= (nodo*)malloc(sizeof(nodo));
	anterior=NULL;
	int nodobuscado=0,encontrado=0;
	printf("Ingrese el dato de la pila a eliminar: ");
	scanf("%d",&nodobuscado);
	if(actual!=NULL){
		while(actual!=NULL && encontrado!=1){
			if(actual->dato==nodobuscado){
				if(actual==primero){
					primero=primero->siguiente;
				}else{
					anterior->siguiente=actual->siguiente;
				}
				printf("El dato ha sido eliminado\n");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->siguiente;
		}
		if(encontrado==0){
			printf("No encontrado\n");
		}else{
			free(anterior);//anterior es el que va a guardar el dato a eliminarse
		}
	}
	else{
		printf("La pila se encuentra vacia\n");
	}
}
