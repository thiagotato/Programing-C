#include <stdio.h>

	void main (void){
		int x,y;

			printf("Digite um numero\n");
				scanf("%d", &y);

					for (x=y; x >= 1; --x){
						printf("%d\n", x );
						y=y*x;
					}
						printf("O resultado é %d\n", y );
	}		