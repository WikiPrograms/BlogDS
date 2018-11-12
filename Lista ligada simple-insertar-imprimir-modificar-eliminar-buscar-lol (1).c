#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct nodo{
	int dato;
	struct nodo* siguiente;
	struct nodo* atras;
}nodo;
nodo* inicio =NULL;
nodo* ultimo =NULL;
//es necesario colocar estos valores de referencia porque una lista tiene un inicio y un fin
//y se pone nodo, porque es referencia a la estructura de la lista
//se asigna los valores de null porque aun no tiene valores y no se puede saber si son vacios o no, asi que se asignan como nulos al inicio
void insertarDato();
void imprimirLista();
void Buscar();
void modificarNodo();
void EliminarNodo();
void EliminariInicio();
int main(int argc, char *argv[]) {
	int opc;
	while(opc!=7){
	printf("\nQue desea hacer:\n\t1.-Insertar nodo\n\t2.-Ver lista\n\t3.-Buscar nodo\n\t4.-Modificar Nodo\n\t5.-Eliminar Nodo\n\t\n\t6.-Eliminar inicio\n\t7.-Salir\n");
	scanf("%d",&opc);
	system("cls");
	switch(opc){
	case 1:
		printf("\n\tInsertar nodo\n");
		insertarDato();
		break;
	case 2:
		printf("\n\tVer lista\n");
		imprimirLista();
		break;
	case 3:
		printf("\n\tBuscar nodo\n");
		Buscar();
		break;
	case 4:
		printf("\n\tModificar Nodo\n");
		modificarNodo();
		break;
	case 5: 
		printf("\n\tEliminar Nodo\n");
		EliminarNodo();
		break;
	case 6:
		printf("\n\tEliminar inicio\n");
		EliminariInicio();
		break;
	}
	}
	return 0;
}
void insertarDato(){
	nodo* nuevo=(nodo*)malloc(sizeof(nodo)); // estamos creando un nuevo nodo en la lista y malloc le asigna memoria
	printf("Digite un nuevo dato de la lista: \n");
	scanf("%d",&nuevo->dato);   //nuevo como es un nuevo nodo y en la estructura nodo hace referencia a un dato tipo entero, por eso nodo apunta a su tipo de dato donde guardar
	// como es referencia se coloca ->
	if(inicio==NULL){ //si el inicio de la lista es null entonces el primer dato es el inicio
 		inicio=nuevo; //nuevo es el nuevo valor
		inicio->siguiente=NULL; //como es el unico valor tendra que apuntar a NULL su parte de siguiente
		inicio->atras=NULL;// es decir si inicio es nuevo su ligadura tiene que apuntar a algo, y por ser el primer valor apunta a null su parte de atras
		ultimo=inicio; //porque como solo hay un valor pues ultimo regresa su ligadura a inicio
	}else{
		ultimo->siguiente=nuevo; //el ultimo valor de la lista, su ligadura tiene que apuntar al nuevo valor
		nuevo->siguiente=NULL; //y el nuevo valor pasa a ser el ultimo y tiene que apuntar a null por ser el ultimo
		nuevo->atras=ultimo; //aqui el apuntador de atras del nuevo dato debe apuntar a un antecesor el cual nunca será nulo cuando haya elementos en la lista
	}   ultimo=nuevo; //despues de hacer las ligaduras ahora el nuevo pasa a ser el ultimo nodo en la lista
	printf("\t\t\tNodo insertado con exito\n\n");
}
void imprimirLista(){
	nodo* actual=(nodo*)malloc(sizeof(nodo)); //creamos un nuevo nodo para que nos ayude a recorrer la lista
	actual=inicio; //posicionamos el nodo actual al primer valor de la lista
	if(actual!=NULL){ //significa que al menos hay un valor en la lista
		while(actual != NULL){ //hasta que actual sea igual que null dejara el ciclo
			printf("%d\n",actual->dato); //imprimimos el valor de actual en la parte de dato
			actual=actual->siguiente; //recorremos el valor de actual, digamos toma el valor del que apuntaba dato
		}
	}else{ // la lista es vacia
		printf("\nLa Lista esta vacia\n");
	}
}
void Buscar(){ //tiene gran parte de coincidencia con el imprimir lista, porque tiene que recorrer cada uno hasta encontrar el valor
	nodo* actual=(nodo*)malloc(sizeof(nodo)); //creamos un nuevo nodo para que nos ayude a recorrer la lista
	actual=inicio; //posicionamos el nodo actual al primer valor de la lista
	int nodobuscar, encontrado=0; 
	printf("Ingrese nodo a buscar: \n"); //pedir el valor del nodo a buscar
	scanf("%d",&nodobuscar);
	if(actual!=NULL){
		while(actual != NULL && encontrado !=1){ //comienza a recorrer la lista
			if(actual->dato==nodobuscar){ //si el valor del actual es igual al nodo buscado, lo encontramos
				printf("Nodo encontrado, con valor de: %d\n",actual->dato);
				encontrado=1; //asignamos 1 a encontrado para referir que ya se encontro
			}
			actual=actual->siguiente; //recorremos el valor de actual, digamos toma el valor del que apuntaba dato
		}
		if(encontrado==0){ //si encontrado sigue igual significa que no se encontro
			printf("No esta ese nodo\n");
		}
	}else{ // la lista es vacia
		printf("\nLa Lista esta vacia\n");
	}
}
void modificarNodo(){ // son muy parecidas a las instrucciones de buscar nodo, porque tenemos que buscar primero el nodo a modificar y ya encontrado modificarlo
	nodo* actual=(nodo*)malloc(sizeof(nodo)); //creamos un nuevo nodo para que nos ayude a recorrer la lista
	actual=inicio; //posicionamos el nodo actual al primer valor de la lista
	int nodobuscar, encontrado=0; 
	printf("Ingrese nodo a buscar: \n"); //pedir el valor del nodo a buscar para ser modificado
	scanf("%d",&nodobuscar);
	if(actual!=NULL){
		while(actual != NULL && encontrado !=1){ //comienza a recorrer la lista
			if(actual->dato==nodobuscar){ //si el valor del actual es igual al nodo buscado, lo encontramos
				printf("Nodo encontrado, con valor de: %d\n",nodobuscar);//si lo encontramos ahora pediremos el nuevo valor del nodo
				printf("\nIngrese el nuevo valor del nodo: \n");
				scanf("%d",&actual->dato); //lo guardamos en la misma posicion donde esta el valor encontrado
				printf("\n\t\tNodo modificado\n");
				encontrado=1; //asignamos 1 a encontrado para referir que ya se encontro
			}
			actual=actual->siguiente; //recorremos el valor de actual, digamos toma el valor del que apuntaba dato
		}
		if(encontrado==0){ //si encontrado sigue igual significa que no se encontro
			printf("No esta ese nodo\n");
		}
	}else{ 
		printf("\nLa Lista esta vacia\n");
	}
	
}
void EliminarNodo(){ // para eliminar debemos buscar primero el nodo, por eso nos basamos de buscar
	nodo* actual=(nodo*)malloc(sizeof(nodo)); //creamos un nuevo nodo para que nos ayude a recorrer la lista
	actual=inicio; //posicionamos el nodo actual al primer valor de la lista
	nodo * anterior=(nodo*)malloc(sizeof(nodo)); //creamos un nuevo apuntador que nos ayudara a ligar la lista
	anterior=NULL; //le damos valor de NULL porque no esta ligada con nada
	int nodobuscar, encontrado=0; 
	printf("Ingrese nodo a buscar para eliminar: \n"); //pedir el valor del nodo a buscar
	scanf("%d",&nodobuscar);
	if(actual!=NULL){
		while(actual != NULL && encontrado !=1){ //comienza a recorrer la lista
			if(actual->dato==nodobuscar){ //si el valor del actual es igual al nodo buscado, lo encontramos, y si lo encontramos podemos eliminarlo
				// hay tres casos para poder eliminar el nodo
				//1.- Que se encuentre al inicio de la lista
				if(actual == inicio){
					inicio=inicio->siguiente; //inicio ahora sera lo que apunte inicio-> nuevo inicio
					inicio->atras=NULL; //como es el inicio no hay un nodo antecesor asi que el inicio siempre su apuntador atras sera NULL
				}else{
					if(actual==ultimo){ //si se encuentra en el ultimo nodo de la lista
					//Aqui el apuntador anterior no importa porque es el ultimo elemento que se elimina, asi que 
					//su apuntador atras se puede perder, solo importa la ligadura siguiente del nodo anterior
					anterior->siguiente=NULL; //posicionamos que apunte a NULL porque sera el proximo valor ultimo
					ultimo=anterior; //ahora toma posicion del ultimo, inicio-> anterior->NULL
					}else{
						anterior->siguiente=actual->siguiente; //si eliminamos un nodo de inmedio de la lista entonces
						//el anterior va a apuntar a lo que apunte actual, y entonces actual se quita de la lsta, es como un paso de...
						// tenemos 7->4->5->1 y queremos quitar 5 entonces el anterior es el 4 como se recorre la lista, digamos que llega a 4 y anterior toma el valor
						// y sigue el ciclo y encuentra el valor a eliminar que es 5, entonces anterior=4 y actual=5, entonces anterior va apuntar lo que...
						//esta apuntando actual, y actual se pierde porque ya no apunta a nada y no es apuntado por otro, y anterior toma el valor de actual segun el ciclo
						//es por eso que al pasar la ligadura anterior toma el valor de 5 para ser eliminado con un free
						actual->siguiente->atras=anterior;
						//
					}
				}
				
				encontrado=1; //asignamos 1 a encontrado para referir que ya se encontro
			}
			anterior=actual;
			actual=actual->siguiente; //recorremos el valor de actual, digamos toma el valor del que apuntaba dato
		}
		if(encontrado==0){ //si encontrado sigue igual significa que no se encontro
			printf("No esta ese nodo\n");
		}
		else{
			free(anterior);
		}
	}else{
		printf("\nLa Lista esta vacia\n");
	}
}
void EliminariInicio(){
	inicio=inicio->siguiente;
}
