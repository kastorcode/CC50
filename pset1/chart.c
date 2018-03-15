#include <cc50.h>
#include <stdio.h>

int
main(void)
{
	int hm, hh, mh, mm;

	do {
		printf("\nQuantos homens procuraram mulheres? ");
		hm = GetInt();
	} while (hm < 0);

	do {
		printf("\nQuantos homens procuraram homens? ");
		hh = GetInt();
	} while (hh < 0);

	do {
		printf("\nQuantas mulheres procuraram homens? ");
		mh = GetInt();
	} while (mh < 0);

	do {
		printf("\nQuantas mulheres procuraram mulheres? ");
		mm = GetInt();
	} while (mm < 0);

	int total = hm + hh + mh + mm;
	printf("\nTotal: %d. Gráfico de buscas:\n", total);

	int cerquilha = 80*hm/total, i = 100*hm/total;
	printf("\nH procurando M - %d%%\n", i);
	for (int i = 0; i < cerquilha; i++)
		printf("#");

	cerquilha = 80*hh/total, i = 100*hh/total;
	printf("\nH procurando H - %d%%\n", i);
	for (int i = 0; i < cerquilha; i++)
		printf("#");

	cerquilha = 80*mh/total, i = 100*mh/total;
	printf("\nM procurando H - %d%%\n", i);
	for (int i = 0; i < cerquilha; i++)
		printf("#");

	cerquilha = 80*mm/total, i = 100*mm/total;
	printf("\nM procurando M - %d%%\n", i);
	for (int i = 0; i < cerquilha; i++)
		printf("#");

	printf("\n\n");
	return 0;
}
