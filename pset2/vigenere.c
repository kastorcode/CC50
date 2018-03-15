#include<cc50.h>
#include<stdio.h>
#include<string.h>

int
main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Erro 1. Digite uma palavra na linha de comando.\n");
		return 1;
	}

	printf("Texto a ser criptografado:\n");
	string texto = GetString();

	int k = 0, l = strlen(texto), m = strlen(argv[1]);

	for (int i = 0, j = 0; i < l; i++) {
		if (j == m)
			j = 0;

		k = (int)argv[1][j];
		if (k >= 65 && k <= 90)
			k -= 65;
		else if (k >= 97 && k <= 122)
			k -= 97;
		else
			k = 0;

		if (texto[i] >= 65 && texto[i] <= 90) {
			texto[i] = (((texto[i] - 65) + k) % 26) + 65;
			j++;
		}
		else if (texto[i] >= 97 && texto[i] <= 122) {
			texto[i] = (((texto[i] - 97) + k) % 26) + 97;
			j++;
		}

		printf("%c", texto[i]);
	}

	printf("\n");
	return 0;
}
