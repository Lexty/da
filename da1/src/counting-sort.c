void csort(int *a, char *t[64], int k, int n, int *b, char *v[64])
{
	int c[k];

	for (int i = 0; i < k; i++)
		c[i] = 0;

	for (int i = 0; i < n; i++)
		c[a[i]]++;

	for (int i = 1; i < k; i++)
		c[i] += c[i-1];

	for (int i = (n-1); i >= 0; i--) {
		b[c[a[i]]-1] = a[i];
		v[c[a[i]]-1] = t[i];
		c[a[i]]--;
	}
}
