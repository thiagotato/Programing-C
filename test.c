#include <stdio.h>

int f1(int n);
int f2(void);

	void main (void){
		int t;
			printf("Digite um número: ");
				scanf("%d", &t);
					t ? f1(t) + f2() : printf("foi digitado zero\n");
	}

	f1 (int n){
		printf("%d", n);
			return 0;
	}

	f2(void){
		printf("foi digitado\n");
			return 0;
	}