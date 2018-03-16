// recover.c	CC50 Pset5	Recupera imagens JPG. Matheus.

#include <stdint.h>
#include <stdio.h>

uint8_t checkJPG(uint8_t *buffer);

int
main(void)
{
	// Boas vindas
	printf("\033[1;30;47mPOWERED BY RAMALHOLIVEIRA\033[0m\nIniciando operação.\n");

	// Abrir arquivo
	FILE *fpr = fopen("card.raw", "r");
	if (fpr == NULL) {
		printf("\033[31mErro ao abrir o arquivo.\033[0m\n");
		return 1;
	}

	// Variáveis
	uint8_t buffer[512];
	int count = 0;
	char name[8];
	FILE *saida;

	// Loop que copia
	while (fread(&buffer, 512, 1, fpr) == 1)
		while (checkJPG(buffer)) {
			count++;
			sprintf(name, "%03d.jpg", count);
			saida = fopen(name, "w");
			fwrite(&buffer, 512, 1, saida);
			// Fim do arquivo ou outra assinatura, para
			while (fread(&buffer, 512, 1, fpr) == 1 && !checkJPG(buffer))
				fwrite(&buffer, 512, 1, saida);
		}

	// Isso é tudo, pessoal :)
	count < 2 ? printf("%d encontrado.\n", count) : printf("Encontrados! %d.\n", count);
	fclose(fpr);
	fclose(saida);
	printf("Isso é tudo, pessoal.\n");
	return 0;
}

// Verifica assinatura JPG
uint8_t
checkJPG(uint8_t *buffer)
{
	if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
		return 1;
	else
		return 0;
}
