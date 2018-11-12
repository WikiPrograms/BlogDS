#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
	int dato;
	struct nodo* sig;
}nodo;
nodo * primero = NULL;
nodo * ultimo = NULL;
void push();
void pop();
void sacar();
int main(int argc, char *argv[]) {
	int menu=0;
	do{
		printf("\n\t1.- Insertar dato\n\t2.-Desplegar cola de datos\n\t3.-Sacar el primero\n\t4.-Salir\n");
		scanf("%d",&menu);
		switch(menu){
		case 1:
			printf("\n\tInsertar dato\n\n");
			push();
			break;
		case 2:
			printf("\n\tDesplegar pila de datos\n\n");
			pop();
			break;
		case 3:
			sacar();
			break;
		default:
			printf("Invalido\n");
		}
	} while(menu!=4);
	return 0;
}
void push(){ //parecido a listas enlazadas
	nodo* nuevo =(nodo*)malloc(sizeof(nodo));
	printf("\nIngrese el dato: ");
	scanf("%d",&nuevo->dato);
	if(primero == NULL){
		primero=nuevo;
		primero->sig=NULL;
		ultimo=nuevo;
	}else{
		ultimo->sig=nuevo;
		nuevo->sig=NULL;
		ultimo=nuevo;
	}
}
void pop(){
	nodo* aux = (nodo*)malloc(sizeof(nodo));
	aux=primero;
	if(primero!=NULL){
		printf("--INICIO--\n");
		while(aux!=NULL){
			printf("    %d",aux->dato);
			printf("\n   |||\n");
			printf("   |||\n");
			printf("  ****\n");
			printf("   ** \n");
			aux=aux->sig;
		}
		printf("\n   |||\n");
		printf("   |||\n");
		printf("  ****\n");
		printf("   ** \n");
		printf("   Proximo");
	}else{
		printf("\nLa cola vacia\n");
	}
}
void sacar(){
	if(primero!=NULL){
		printf("\n\nElemento a salir: ");
		printf("%d\n",primero->dato);
		primero = primero->sig;
		
	}else{
		printf("\nCola vacia\n");
	}
	
}
