#pragma once

int main();

int indexNejblizsi(int velikost, int(*poleBodu)[2], int referencniX, int referencniY);
double prumernaVzdalenost(int velikost, int(*poleBodu)[2], int referencniX, int referencniY);
void bodyVBlizkosti(int max_vzdalenost,int velikost, int(*poleBodu)[2], int referencniX, int referencniY);
