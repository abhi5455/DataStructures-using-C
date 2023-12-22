#include<stdio.h>

struct tuple {
	int row, col, val;
};

void createsparse(int m[10][10], struct tuple a[], int r, int c) {
	int k = 1, i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			if (m[i][j] != 0) {
				a[k].row = i;
				a[k].col = j;
				a[k].val = m[i][j];
				k++;
			}
	a[0].row = r;
	a[0].col = c;
	a[0].val = k - 1;
}

void displaysparse(struct tuple a[]) {
	printf("Sparse matrix \n");
	int i;
	for (i = 0; i <= a[0].val; i++)
		printf("%d  %d  %d\n", a[i].row, a[i].col, a[i].val);
}

void transpose(struct tuple a[], struct tuple b[]) {
	int n, i, j, q;
	n = a[0].val;
	b[0].col = a[0].row;
	b[0].row = a[0].col;
	b[0].val = n;
	q = 1;
	for (i = 0; i < a[0].col; i++)
		for (j = 1; j <= n; j++)
			if (a[j].col == i) {
				b[q].col = a[j].row;
				b[q].row = a[j].col;
				b[q].val = a[j].val;
				q = q + 1;
			}

}

void addsparse(struct tuple p[], struct tuple q[], struct tuple r[]) {
	r[0].col = p[0].col;
	r[0].row = p[0].row;
	int i, j, k;
	i = j = k = 1;
	while (i <= p[0].val && j <= q[0].val) {
		if (p[i].row > q[j].row || (p[i].row == q[j].row && p[i].col > q[j].col)) {
			r[k].row = q[j].row;
			r[k].col = q[j].col;
			r[k++].val = q[j++].val;
		} else if (p[i].row < q[j].row || (p[i].row == q[j].row && p[i].col < q[j].col)) {
			r[k].row = p[i].row;
			r[k].col = p[i].col;
			r[k++].val = p[i++].val;
		} else {
			r[k].row = q[j].row;
			r[k].col = q[j].col;
			r[k++].val = p[i++].val + q[j++].val;
		}
	}
	while (i <= p[0].val) {
		r[k].row = p[i].row;
		r[k].col = p[i].col;
		r[k++].val = p[i++].val;
	}
	while (j <= q[0].val) {
		r[k].row = q[j].row;
		r[k].col = q[j].col;
		r[k++].val = q[j++].val;
	}
	r[0].val = k - 1;
}

void main() {
	int m1[10][10], m2[10][10], m, n, i, j, p, q;
	struct tuple a[20], b[20], c[30], at[20], bt[20];
	printf("Enter the row and columns of 1st matrix : ");
	scanf("%d%d", &m, &n);
	printf("Enter the %d elements : ", m * n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &m1[i][j]);
	printf("Enter the row and columns of 2nd matrix: ");
	scanf("%d%d", &p, &q);
	printf("Enter the %d elements : ", p * q);
	for (i = 0; i < p; i++)
		for (j = 0; j < q; j++)
			scanf("%d", &m2[i][j]);
	createsparse(m1, a, m, n);
	createsparse(m2, b, p, q);
	transpose(a, at);
	transpose(b, bt);
	displaysparse(at);
	printf("\n");
	displaysparse(bt);
	printf("\n");
	if ((m != p) || (n != q))
		printf("Addition not possible");
	else {
		printf("Added ");
		addsparse(a, b, c);
		displaysparse(c);
	}
}
