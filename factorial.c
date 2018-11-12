#include <stdio.h>
long factorial(int n); 
int main(int argc, char *argv[]) {
	int n;
	printf("Ingrese numero\n");
	scanf("%d",&n);
	factorial(n);
	int t;
	t=factorial(n);
	printf("%d",t);
	return 0;
}
long factorial(int n){
	if(n==1){
		return 1;
	}else{
		return n*factorial(n-1);
	}
}
