#include <stdio.h>
#include "FSM_actions.c"

int main(void)
{
	char wynik;
	char s[] = ":Ia\n";
	char *wprowadzane;
	int rozm = 0;

	getline(&wprowadzane,rozm,stdin);

	wynik = parse(s);
	printf("%s",s);
	printf("%c %d\n", wynik, wynik);
	return 0;
}
