#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<io.h> //using access

int min(int a, int b) {
	if (a > b) { return b; }
	else { return a; }
}
int A[1001][1001],B[1001][1001];
char calcu[5] = { 'A','B','*','+', '\'' };
FILE *f1;
int main() {
	int n;
	srand(time(NULL));
	f1 = fopen("hw1_input.txt", "w");
	printf("Enter the number: ");
	scanf("%d", &n);
	fprintf(f1, "%d\n", n);
	fprintf(f1, "$\n");
	int cnt = rand() % min(9996, n*n);
	if (cnt < 5)cnt += 5;
	while (cnt != 0) {
		int a = rand() % n + 1;
		int b = rand() % n + 1;
		if (A[a][b] == 0) {
			A[a][b] = rand() % 21 - 10;
			cnt--;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fprintf(f1, "%d ", A[i][j]);
		}
		fprintf(f1, "\n");
	}
	fprintf(f1, "$\n");
	cnt = rand() % min(9996, n*n) + 5;
	while (cnt != 0) {
		int a = rand() % n + 1;
		int b = rand() % n + 1;
		if (B[a][b] == 0) {
			B[a][b] = rand() % 21 - 10;
			cnt--;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fprintf(f1, "%d ", B[i][j]);
		}
		fprintf(f1, "\n");
	}
	fprintf(f1, "$\n");
	cnt = rand() % 500 + 1;
	int a, b;
	a = rand() % 2;
	b = rand() % 3 + 2;
	fprintf(f1, "%c", calcu[a]);
	for (int i = 1; i <= cnt; i++) {
		a = rand() % 2;
		b = rand() % 3 + 2;
		fprintf(f1, "%c", calcu[b]);
		if (b != 4) {
			fprintf(f1, "%c", calcu[a]);
		}
	}
	a = rand() % 2;
}