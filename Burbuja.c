#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct nodo{
	int dato;
	struct nodo* sig;
}nodo;
nodo* inicio=NULL;
nodo* fin=NULL;
void insertar();
void ver();
void Burbuja();
int main(int argc, char *argv[]) {
	int opc;
	while(opc!=5){
		printf("\n\t1.-Insertar\n\t2.- Ver\n\t3.- Burbuja\n\t5.- Salir\n");
		scanf("%d",&opc);
		system("cls");
		switch(opc){
		case 1:
			insertar();
			break;
		case 2:
			ver();
			break;
		case 3:
			Burbuja();
			break;
		}
	}
	return 0;
}
void insertar(){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	printf("\nIngrese el nuevo dato: ");
	scanf("%d",&nuevo->dato);
	if(inicio == NULL){
		inicio= nuevo;
		nuevo->sig=NULL;
		fin=nuevo;
	}else{
		fin->sig=nuevo;
		nuevo->sig=NULL;
		fin=nuevo;
	}
}
void ver(){
	nodo* aux=(nodo*)malloc(sizeof(nodo));
	aux=inicio;
	if(aux!=NULL){
		printf("\n---------------------------\n");
		while(aux!=NULL){
			printf("%d",aux->dato);
			printf(" -> ");
			aux=aux->sig;
		}
		printf("NULL\n");
	}else{
		printf("\nLista vacia\n");
	}
}
void Burbuja(){
	nodo* piv =(nodo*)malloc(sizeof(nodo)); //i
	nodo* aux =(nodo*)malloc(sizeof(nodo));//j
	piv=inicio;
	int temp=0; //un auxiliar para guardar temporalmente el valor a cambiar
	if(inicio!=NULL){ 
		while(piv!=NULL){ //i <total-1
			aux = piv->sig; //// j= i+1
			while(aux !=NULL){ //j<total
				if(piv->dato > aux->dato){ //arreglo[i] > arreglo[j]
					temp = piv->dato;
					piv->dato = aux->dato;
					aux->dato = temp;
				}
				aux= aux->sig; //j++
			}
			piv= piv->sig;
		}
	}else{
		printf("\nLista vacia\n");
	}
	printf ("\nVuelva a seleccionar ver\n");
}
