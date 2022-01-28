#include<stdio.h>
using namespace std;


int n,rply;

double a[101][101];


void SWAP(double &a, double &b) {
	
	double tmp = a;
	a = b;
	b = tmp;

}

void init() {

//	freopen("in.txt", "r", stdin);

	printf("input n\n");
	scanf_s("%d", &n);

	printf("input the matrix\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%lf", &a[i][j]);
		}
	}

//	fclose(stdin);

	/*
		input
	 */

}

void solve() {

	int cnt = 0;

	for (int i = 1; i <= n; i++) {

		if (!a[i][i]) {
			for (int row = i + 1; row <= n; row++) {
				if (a[row][i]) {
					for (int col = 1; col <= n; col++)
						SWAP(a[i][col], a[row][col]);
					break;
					cnt++;
				}
			}
		}

		/*
			If a[i][i] == 0 then
			find another row that satisfies a[row][i] != 0
			and swap the two rows
		 */

		for (int row = i + 1; row <= n; row++) {
			double k = a[row][i] / a[i][i];
			for (int col = 1; col <= n; col++) {
				a[row][col] += -k * a[i][col];
			}
		}

		/*
			make the determinant upper triangular
			column by column
		 */

	}

	double ans = 1;

	for (int i = 1; i <= n; i++) {
		ans *= a[i][i];
	}

	/*
		calculate the answer
	 */

	printf("%.6f\n", ans);

}

int main() {

	do {

		init();

		solve();
		
		printf("Do you want to input another matrix?\n[1] Yes [2] No\n");
		scanf_s("%d", &rply);

	} while (rply == 1);

}
