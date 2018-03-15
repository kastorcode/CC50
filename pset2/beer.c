#include<stdio.h>
#include<unistd.h>

int
main(void)
{
	int i = 10;
	while (i > 0) {
		printf("%d garrafas de cerveja no muro, bebo uma, jogo no lixo, ", i);
		i--;
		if (i == 1) {
			printf("%d garrafa no muro...\n", i);
			sleep(1);
			printf("1 garrafa de cerveja no muro, bebo uma, jogo no lixo, nenhuma garrafa no muro...\n");
			return 0;
		}
		printf("%d garrafas no muro...\n", i);
		sleep(1);
	}
}
