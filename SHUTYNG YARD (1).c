#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct nodo nodo;

struct nodo{
	char dato;
	nodo* siguiente;
	nodo* anterior;
};

nodo* inicio = NULL;
nodo* anterior = NULL;

nodo* inicio2 = NULL;
nodo* anterior2 = NULL;

nodo* inicio3 = NULL;
nodo* anterior3 = NULL;

nodo* inicio4 = NULL;
nodo* anterior4 = NULL;

nodo* crearNodo(char dato){
	nodo* nuevo=NULL;
	nuevo=(nodo*)malloc(sizeof(nodo));
	if(nuevo!=NULL){
		nuevo->dato=dato;
		nuevo->siguiente= NULL;
		nuevo->anterior=NULL;
	}
	return nuevo;
}

void insertarCola(char dato){
	nodo* nuevo = crearNodo(dato);
	if(inicio==NULL){
		inicio=nuevo;
		anterior=nuevo;
	}else{
		nuevo->anterior=anterior;
		anterior->siguiente=nuevo;
		anterior=nuevo;
	}
}

void insertarPila(char dato){
	nodo* nuevo = crearNodo(dato);
	if(inicio2==NULL){
		inicio2=nuevo;
		anterior2=nuevo;
	}else{
		nuevo->anterior=inicio2;
		inicio2->siguiente=nuevo;
		inicio2=nuevo;
	}
}
void insertarCola2(char dato){
	nodo* nuevo = crearNodo(dato);
	if(inicio3==NULL){
		inicio3=nuevo;
		anterior3=nuevo;
	}else{
		nuevo->anterior=anterior3;
		anterior3->siguiente=nuevo;
		anterior3=nuevo;
	}
}

void insertarPila2(float dato){
	nodo* nuevo = crearNodo(dato);
	if(inicio4==NULL){
		inicio4=nuevo;
		anterior4=nuevo;
	}else{
		nuevo->anterior=inicio4;
		inicio4->siguiente=nuevo;
		inicio4=nuevo;
	}
}

void shutPolaca(){
	nodo *aux1 = inicio;
	while(aux1->siguiente!=NULL){
		char c=aux1->dato;
		nodo *aux2=inicio2;
		switch(c){
		case '(':
			insertarPila(c);	
			break;
		case '+':
		case '-':
			if(aux2==NULL){
				insertarPila(c);	
			}
			else{ 
				while(aux2->dato=='*'||aux2->dato=='/'||aux2->dato=='^'){
					insertarCola2(aux2->dato);
					inicio2=inicio2->anterior;
					aux2->anterior=NULL;
					aux2->siguiente=NULL;
					inicio2->siguiente=NULL;
					free(aux2);
					aux2=inicio2;
				}
				insertarPila(c);
			}
			break;
		case '*':
		case '/':
			if(aux2==NULL){
				insertarPila(c);	
			}
			else{ 
				while(aux2->dato=='^'){
					insertarCola2(aux2->dato);
					inicio2=inicio2->anterior;
					aux2->anterior=NULL;
					aux2->siguiente=NULL;
					inicio2->siguiente=NULL;
					free(aux2);
					aux2=inicio2;
				}
				insertarPila(c);	
			}
			break;
		case '^':
			insertarPila(c);	
			break;
		case ')':
			while((aux2->dato)!='('){
				insertarCola2(aux2->dato);
				inicio2=inicio2->anterior;
				aux2->anterior=NULL;
				aux2->siguiente=NULL;
				inicio2->siguiente=NULL;
				free(aux2);
				aux2=inicio2;
			}
			break;
		default:
			insertarCola2(c);
		}
		aux1=aux1->siguiente;
	}
	nodo *aux2=inicio2;
	while(aux2!=NULL){
		if(aux2->dato!='('){
			insertarCola2(aux2->dato);
		}
		aux2=aux2->anterior;
	}
}

void desar(){
	float res;
	nodo *aux=inicio3;
	while(aux!=NULL){
		nodo *aux2=inicio4;
		switch(aux->dato){
		case '+':
			res=(inicio4->anterior->dato)+(inicio4->dato);
			if(aux2->anterior->anterior!=NULL){
				inicio4=aux2->anterior->anterior;
				inicio4->siguiente=NULL;
				inicio4->anterior=aux2->anterior->anterior->anterior;
				free(aux2);
				free(aux2->anterior);
				//printf("suma %i",inicio4->dato);
			}
			else{
				inicio4=NULL;	
			}
			insertarPila2(res);
			break;
		case '-':
			res=(inicio4->anterior->dato)-(inicio4->dato);
			if(aux2->anterior->anterior!=NULL){
				inicio4=aux2->anterior->anterior;
				inicio4->siguiente=NULL;
				inicio4->anterior=aux2->anterior->anterior->anterior;
				free(aux2);
				free(aux2->anterior);
			}
			else{
				inicio4=NULL;	
			}
			insertarPila2(res);
			break;
		case '*':
			res=((inicio4->anterior->dato)*(inicio4->dato));
			if(aux2->anterior->anterior!=NULL){
				inicio4=aux2->anterior->anterior;
				inicio4->siguiente=NULL;
				inicio4->anterior=aux2->anterior->anterior->anterior;
				free(aux2);
				free(aux2->anterior);
			}
			else{
				inicio4=NULL;	
			}
			insertarPila2(res);
			break;
		case '/':
			res=((inicio4->anterior->dato)/(inicio4->dato));
			if(aux2->anterior->anterior!=NULL){
				inicio4=aux2->anterior->anterior;
				inicio4->siguiente=NULL;
				inicio4->anterior=aux2->anterior->anterior->anterior;
				free(aux2);
				free(aux2->anterior);
			}
			else{
				inicio4=NULL;	
			}
			insertarPila2(res);
			break;
		case '^':
			res=pow((inicio4->anterior->dato),(inicio4->dato));
			if(aux2->anterior->anterior!=NULL){
				inicio4=aux2->anterior->anterior;
				inicio4->siguiente=NULL;
				inicio4->anterior=aux2->anterior->anterior->anterior;
				free(aux2);
				free(aux2->anterior);
			}
			else{
				inicio4=NULL;	
			}
			insertarPila2(res);
			break;
		default:
			res=(aux->dato)-48;
			insertarPila2(res);
		}
		aux=aux->siguiente;
	}
	printf("El resultado es: %.2f",res);
}

void leerCola(){
	nodo *aux = inicio;
	while(aux!=NULL){
		printf("%c", aux->dato);
		aux = aux->siguiente;
	}
}

void leerCola2(){
	nodo *aux = inicio3;
	while(aux!=NULL){
		printf("%c", aux->dato);
		aux = aux->siguiente;
	}
}


int main(){
	char p[20];
	int c=0;
	for(int i=0;i<20;i++){
		p[i]='.';
	}
	printf("Ingresa una funcion\n");
	scanf("%s",&p[0]);
	while(p[c]!='.'){
		char pa=p[c];
		insertarCola(pa);
		c+=1;
	}
	leerCola();
	printf("\nNotacion Polaca:\t");
	shutPolaca();
	leerCola2();
	printf("\n\t");
	desar();
	return 0;
}
