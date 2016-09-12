#include <stdio.h>
#include <stdlib.h>
	
	void main(void){
		int magic;
		int guess;
			magic = rand();
				printf("Adivinhe o número magico: ");
					scanf("%d", &guess);
						if (guess == magic){
							printf("*** Certo ***");
								printf("%d é o número magico\n", magic);
						}
						else{
							guess > magic ? printf("Alto\n") : printf("Baixo\n");
						}
	}