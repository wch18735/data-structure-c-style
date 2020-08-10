#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int factorial(int n) {
	if (n <= 1) return 1;
	else return (n*factorial(n - 1));
}

int main() {
	int n;
	printf("n! ÀÇ n:");
	scanf("%d", &n);
	printf("%d", factorial(n));
}