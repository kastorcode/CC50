/***************************************************************************
 * generate.c
 *
 * CC50
 * Pset 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int
main(int argc, char *argv[])
{
	// Verificação dos argumentos de linha de comando
	if (argc != 2 && argc != 3)
	{
		printf("Usage: %s n [s]\n", argv[0]);
		return 1;
	}

	// Transforma o primeiro argumento em INT e armazena em N
	int n = atoi(argv[1]);

	// Verifica se são 2 ou 3 argumentos
	if (argc == 3)
		srand((unsigned int) atoi(argv[2]));
	else
		srand((unsigned int) time(NULL));

	// Imprime os números pseudo-aleatórios
	for (int i = 0; i < n; i++)
		printf("%d\n", rand() % LIMIT);

	// Encerra o programa
	return 0;
}
