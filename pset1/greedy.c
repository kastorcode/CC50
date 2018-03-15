#include <cc50.h>
#include <stdio.h>

int
main(void)
{
	float a = 0.25, b = 0.10, c = 0.05, d = 0.01, f = 0.00;
	int a2 = 0, b2 = 0, c2 = 0, d2 = 0, moedas = 0, f2 = (int)f;

	do {
		printf("Quanto de troco deseja receber? ");
		f = GetFloat();
	} while (f < 0);

	if (f == 0)
		printf("Obrigado volte sempre!\nF2=%d.\n", f2);
	else {
		while (f >= a)
			f -= a, moedas++, a2++;
		while (f >= b)
			f -= b, moedas++, b2++;
		while (f >= c)
			f -= c, moedas++, c2++;
		while (f >= d)
			f -= d, moedas++, d2++;
		printf("Este troco exige %d moedas. 25=%d, 10=%d, 5=%d, 1=%d, f=%f, F2=%d.\n", moedas, a2, b2, c2, d2, f, f2);
	}

	return 0;
}
