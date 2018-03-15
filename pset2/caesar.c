#include<cc50.h>
#include<stdio.h>
#include<string.h>

int
main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Erro 1. Digite um número na linha de comando.\n");
		return 1;
	}

	printf("Texto a ser criptografado:\n");
	string texto = GetString();
	int k = atoi(argv[1]);

	for (int i = 0, j = strlen(texto); i < j; i++) {
		if (texto[i] >= 65 && texto[i] <= 90)
			texto[i] = (((texto[i] - 65) + k) % 26) + 65;
		else if (texto[i] >= 97 && texto[i] <= 122)
			texto[i] = (((texto[i] - 97) + k) % 26) + 97;
		printf("%c", texto[i]);
	}

	printf("\nChave = %d.\n", k);
	return 0;
}
