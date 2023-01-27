#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
double first_metod(double x) {
	double y;
	y = asin(sqrt(x / (x + 1)));
	return y;
}
int second_metod(double x, float* y) {
	*y = asin(sqrt(x / (x + 1)));
	if (*y < 0) {
		return -1;
	}
	else if (*y == 0) {
		return 0;
	}
	else if (*y > 0) {
		return 1;
	}
}
void tabulation(float step) {
	printf("|X \t\t\t|Y from 1 function \t|Y from 2 function \t|Return of 2 function\n");
	float x, y, second_metod_result; int retun_metod_2;
	for (x = 0; x <= 3; x = x + step) {

		y = first_metod(x);

		retun_metod_2 = second_metod(x, &second_metod_result);

		printf("|%.13lf \t|%.13lf \t|%.13lf \t|%d\n", x, y, second_metod_result, retun_metod_2);
	}
}
int main(void) {
	float step;
	printf("Enter the step of calculation: ");
	scanf("%f", &step);
	tabulation(step);
	return 0;
}