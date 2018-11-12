#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct nodo _nodo;
struct nodo{
	int dato;
	struct nodo *izq;
	struct nodo *der;
}nodo;

_nodo *crearnodo(int dato){
	_nodo *nuevo;
	nuevo=(_nodo*)malloc(sizeof(nodo));
	nuevo->dato=dato;
	nuevo->der=NULL;
	nuevo->izq=NULL;
	return nuevo;
}
_nodo *addDerecha(_nodo *nuevo, _nodo *raiz){
	raiz->der = nuevo;
	return raiz;
}
_nodo *addIzquierdo(_nodo *nuevo, _nodo *raiz){
	raiz->izq=nuevo;
	return raiz;
}
void imprimir(_nodo *nodo){
	if(nodo !=NULL){
		printf(" %d ", nodo->dato);
	}
}
void preorden(_nodo *raiz){
	if(raiz != NULL){
		imprimir(raiz);
		preorden(raiz->izq);
		preorden(raiz->der);
	}
}
void inorden(_nodo *raiz){
	if(raiz != NULL){
		inorden(raiz->izq);
		imprimir(raiz);
		inorden(raiz->der);
	}
}
void postorden(_nodo *raiz){
	if(raiz != NULL){
		postorden(raiz->izq);
		postorden(raiz->der);
		imprimir(raiz);
	}
}
int main(int argc, char *argv[]) {
	_nodo *raiz;
	raiz = crearnodo(1);
	raiz->izq = crearnodo(2);
	raiz->der = crearnodo(3);
	raiz->izq->izq=crearnodo(4);
	raiz->der->izq=crearnodo(5);
	raiz->der->der = crearnodo(6);
	printf("Inorden\n");
	inorden(raiz);
	printf("\nPreorden\n");
	preorden(raiz);
	printf("\nPostorden\n");
	postorden(raiz);
	return 0;
}
