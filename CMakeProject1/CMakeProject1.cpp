// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
#define POCET_BODU 10
#include "Body2d.h"

using namespace std;

int main()
{
	int x, y, z;

	int body[POCET_BODU][2] = { 5,10,
								 -14,2,
								 45,4,
								 -9,8,
								 58,-3,
								 47,5,
								 -18,-86,
								 75,7,
								 -25,51,
								 17,98 };


	printf("Zadej souradnici X referencniho bodu: \n");
	scanf("%d", &x);
	printf("Zadej souradnici Y referencniho bodu: \n");
	scanf("%d", &y);
	printf("Zadej nejvetsi vzdalenost od bodu: \n");
	scanf("%d", &z);

	int a = indexNejblizsi(POCET_BODU, body, x, y);

	printf("Nejblizsi souradnice index: [%i, %i]\n", body[a][0], body[a][1]);

	double b = prumernaVzdalenost(POCET_BODU, body, x, y);

	printf("Prumerna vzdalenost: %lf\n", b);

	bodyVBlizkosti(z, POCET_BODU, body, x, y);
	




	return 0;
}

int indexNejblizsi(int velikost, int(*poleBodu)[2], int referencniX, int referencniY) {
	double temp_vzdalenost;
	int	min_vzdalenost = INT_MAX;
	int prvni_zavorka = 0, druha_zavorka = 0;
	int index;

	for (int row = 0; row < velikost; row++) {

		for (int col = 0; col < 2; col++) {

			if (col == 0) {
				prvni_zavorka = (referencniX - poleBodu[row][col]) * (referencniX - poleBodu[row][col]);
			}
			if (col == 1) {
				druha_zavorka = (referencniY - poleBodu[row][col]) * (referencniY - poleBodu[row][col]);
			}

		}
		temp_vzdalenost = sqrt(prvni_zavorka + druha_zavorka);

		if (temp_vzdalenost < min_vzdalenost) {
			min_vzdalenost = temp_vzdalenost;
			index = row;


			temp_vzdalenost = 0;
			prvni_zavorka = 0;
			druha_zavorka = 0;
		}
	}

	return index;
}

double prumernaVzdalenost(int velikost, int(*poleBodu)[2], int referencniX, int referencniY) {
	double temp_vzdalenost, prumerna_vzdalenost = 0;
	int prvni_zavorka = 0, druha_zavorka = 0;

	for (int row = 0; row < velikost; row++) {

		for (int col = 0; col < 2; col++) {

			if (col == 0) {
				prvni_zavorka = (referencniX - poleBodu[row][col]) * (referencniX - poleBodu[row][col]);
			}
			if (col == 1) {
				druha_zavorka = (referencniY - poleBodu[row][col]) * (referencniY - poleBodu[row][col]);
			}

		}
		temp_vzdalenost = sqrt(prvni_zavorka + druha_zavorka);

		prumerna_vzdalenost += temp_vzdalenost;


		temp_vzdalenost = 0;
		prvni_zavorka = 0;
		druha_zavorka = 0;
	}

	return prumerna_vzdalenost / 10;
}

void bodyVBlizkosti(int max_vzdalenost, int velikost, int(*poleBodu)[2], int referencniX, int referencniY) {
	int temp_vzdalenost;
	int prvni_zavorka = 0, druha_zavorka = 0;
	int index;


	printf("Nejblizsi body: ");

	for (int row = 0; row < velikost; row++) {

		for (int col = 0; col < 2; col++) {

			if (col == 0) {
				prvni_zavorka = (referencniX - poleBodu[row][col]) * (referencniX - poleBodu[row][col]);
			}
			if (col == 1) {
				druha_zavorka = (referencniY - poleBodu[row][col]) * (referencniY - poleBodu[row][col]);
			}
		}
		temp_vzdalenost = sqrt(prvni_zavorka + druha_zavorka);

		if (temp_vzdalenost <= max_vzdalenost) {
			index = row;
			printf("[%i, %i]", poleBodu[index][0], poleBodu[index][1]);

			temp_vzdalenost = 0;
			prvni_zavorka = 0;
			druha_zavorka = 0;
		}
	}

}

