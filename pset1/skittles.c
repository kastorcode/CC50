#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void)
{
	// seed do PRNG
	srand(time(NULL));

	// escolhe número pseudo-aleatório entre [0, 1023]
	int skittles = rand() % 1024, i = 0;

	printf("Olá! Eu sou uma máquina de balas falante! Adivinhe quantos Skittles têm dentro de mim. Dica: estou pensando em um número entre 0 e 1023. Qual é ele?\nDigite um número: ");

	do {
		i = GetInt();
		if (i < skittles)
			printf("Haha! Tenho muito mais Skittles do que isso. Tente novamente.\nDigite um número: ");
		else if (i > skittles)
			printf("Não tente ser difícil... Adivinhe novamente.\nDigite um número: ");
		else {
			printf("\nVocê está certo! Nom nom nom nom.\n");
			break;
		}
	} while (i != skittles);

	return 0;
}
