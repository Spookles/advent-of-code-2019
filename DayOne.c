#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	FILE* fp = fopen("input.txt", "r");
	if (!fp) printf("File not found");
	else {
		int modules[101];
		int c;
		int teller = 0;
		int fuel = 0;
		int totalFuel = 0;

		while (fscanf(fp, "%d", &c) != EOF) {
			teller++;
			modules[teller] = c;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
		//Part 1

		for (int i = 1; i < 101; i++) {
			fuel += (int)round(modules[i] / 3) - 2;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
		//Part 2

		for (int o = 1; o < 101; o++) {
			int tFuel = modules[o];
			int tempFuel = 0;
			while (tFuel > 0) {
				tFuel = (int)round(tFuel / 3) - 2;
				if (tFuel > 0) {
					tempFuel += tFuel;
				}
			}
			totalFuel += tempFuel;
		}

		printf("%d\n", fuel); //1
		printf("%d\n", totalFuel); //2
	}
	return 0;
}
