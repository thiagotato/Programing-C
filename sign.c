#include <stdio.h>
#include <stdlib.h>

	void sign_on(void){
		char str[20];
		int x;

		for ( x = 0; x < 3 && strcmp(str, "senha"); ++x)
		{
			printf("Digite a senha:");
			gets(str);
		}
			if (x==3) return;
			{
				printf("Erro");
			else {
				printf("Sucesso");
		
			}
	}