// ---------------------------------------------------------------------------
/*
 Kl�vs Ceic�ns P2-4

 Programma interv�l� no 0 l�dz N atrod t�dus skait�us, kuru
 maz�ko dal�taju summa ir viena�da ar liel�ko, kur� mazaks par pa�u skaitli
 (Piemeram 28:14=1+2+4+7), N ievada lietot�js.

 */
#pragma hdrstop
// ---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

main() {
	char exit, aizp; // exit - variablis izie�anai
	long mas[100][100];
	int izm, a, b, s;

	do {
		printf("Programma jusu ievadito matricu (NxN), kura satur naturalus skaitlus\n");
		printf("pagriez pa 90 gradiem pulkstenraditaja virziena!\n\n");
		printf("Ievadiet rindu un kolonnu skaitu (rindas = kolonnas):");
		scanf("%d", &izm);
		while ((izm <= 0) || (izm > 100)) {
			system("CLS");
			printf("Masiva izmeri nevar but mazaki par 1 vai lielaki par 100!\n\n");
			printf("Ievadiet rindu un kolonnu skaitu (rindas = kolonnas):");
			scanf("%d", &izm);
		}
		izm--;
		// Mas�va aizpildes pazi�ojums
		printf("Vai velaties aizpildit masivu pats (y/n)?:");
		flushall();
		scanf("%c", &aizp);
		// P�rbaudam vai lietot�js aizpild�s pats
		if ((aizp == 'y') || (aizp == 'Y')) {
			printf("\n\nIevadiet masiva elementus (naturalus skaitlus):\n");
			for (a = 0; a <= izm; a++) {
				for (b = 0; b <= izm; b++) {
					printf("mas[%d,%d] = ", a, b);
					scanf("%ld", &mas[a][b]);
					while (mas[a][b] <= 0) {
						// P�rbaude, vai netiek ievad�ti da�skait�i
						printf("Var ievadit tikai naturalus skaitlus!\n");
						printf("mas[%d.%d] = ", a, b);
						scanf("%ld", &mas[a][b]);
					}
				}
			}
		}
		else {
			// Aizpild�t ar random(100) skait�iem
			printf("\nMASIVS TIKA AIZPILDITS AR SKAITLIEM 1 LIDZ 100\n");
			randomize();
			for (a = 0; a <= izm; a++)
				for (b = 0; b <= izm; b++) {
					mas[a][b] = random(100) + 1;
				}
		}
		// Izvad�t �ener�to mas�vu
		printf("\nNepagriezts masivs\n\n");
		for (a = 0; a <= izm; a++) {
			for (b = 0; b <= izm; b++)
				printf("%3.2d ", mas[a][b]);
			printf("\n");
		}
		// Izvad�t pagriezto mas�vu
		printf("\nPagriezts masivs\n\n");
		for (a = 0; a <= izm; a++) {
			for (b = izm; b >= 0; b--)
				printf("%3.2d ", mas[b][a]);
			printf("\n");
		}
		// Vecais + pagrieztais mas�vs
		printf("\nJaunais masivs\n\n");
		for (a = 0; a <= izm; a++) {
			for (b = izm; b >= a; b--) {
				s = mas[a][b];
				mas[a][b] = mas[b][a];
				mas[b][a] = s;
			}
		}
		for (a = 0; a <= izm; a++) {
			for (b = 0; b <= izm; b++) {
				s = mas[b][a];
				mas[b][a] = mas[b][izm - a];
				mas[b][izm - a] = s;
			}
		}
		for (a = 0; a <= izm; a++) {
			for (b = 0; b <= izm; b++)
				printf("%3.2d ", mas[a][b]);
			printf("\n");
		}
		printf("\nLai atkartotu nospiediet Y, lai izietu jebkuru citu burtu:");
		flushall(); // Not�r�t buferi
		// Vai atk�rtot?
		scanf("%c", &exit);
		clrscr();
	}
	while ((exit == 'y') || (exit == 'Y')); // atk�rtot, ja ievad�ts y/Y
	return EXIT_SUCCESS;
}
