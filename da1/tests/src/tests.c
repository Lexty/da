#include <stdio.h>
#include <string.h>
#include "../../src/counting-sort.c"

int quiet, failed;

int main(int argc, char **argv)
{
	quiet = (argc == 1 ? 0 : 1);
	failed = 0;

	void test(const char *t_name, const int t_result);
	int char_arr_eq(const char *s1, const char *s2);
	int int_arr_eq(const int *a, const int *b);
	int str_arr_eq(char *s1[], char *s2[], const int size);
	int getMax(int arr[], int size);

	int k, n;

	int keys_in1[] = {324, 2, 4326, 3425, 44234, 63820, 7326, 53, 480, 4383, 32435};
	char *val_in1[64] = {
		"03 324 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"01 1 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"06 4328 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"05 3425jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"10 44234 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"11 63820 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"08 7326 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"02 53 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"04 480 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"07 4383 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"09 32435 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ"
	};
	char *val_out1[64];
	n = sizeof(keys_in1)/sizeof(keys_in1[0]);
	k = getMax(keys_in1, n) + 1;
	int keys_out1[n];
	int keys_exp1[] = {2, 53, 324, 480, 3425, 4328, 4383, 7326, 32435, 44234, 63820};
	char *val_exp1[64] = {
		"01 1 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"02 53 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"03 324 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"04 480 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"05 3425jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"06 4328 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"07 4383 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"08 7326 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"09 32435 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"10 44234 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ",
		"11 63820 jaop389dj[0EOC[0923JDNIEHD9DJ2JDISJ"
	};
	csort(keys_in1, val_in1, k, n, keys_out1, val_out1);
	test("Test sort keys #1", int_arr_eq(keys_out1, keys_exp1));
	test("Test sort values #1", str_arr_eq(val_out1, val_exp1, n));

	int keys_in2[] = {2, 5, 3, 0, 2, 3, 0, 3};
	char *val_in2[64] = {
		"2 dfasg aerg jqw34gjqoiwerhf qws",
		"5 asdh iowerh;oanf ;vower",
		"3 adl lskdfn;glwenhr[3prdfvasd g",
		"0 asfk bgwuirqo3hro;fwdklvn;q3iornf[uioq wernhvoq n;d",
		"2 np9wenheuiodvh;wklcdnv;oqeirn;g vowefnvmlwneorn 'qefmq;v mep",
		"3 lhasdlk vnaljkwbhvluiw34hilu fha;wdjvq;w3uioeh.vsd",
		"0wd jqwebn rlqvu3bril vjbdk.bvq lejibvksncvjlq webr",
		"3 wvnoiwerhuohq3or ;dfjkvn; oqrejfndvj"
	};
	char *val_out2[64];
	n = sizeof(keys_in2)/sizeof(keys_in2[0]);
	k = getMax(keys_in2, n) + 1;
	int keys_out2[n];
	int keys_exp2[] = {0, 0, 2, 2, 3, 3, 3, 5};
	char *val_exp2[64] = {
		"0 asfk bgwuirqo3hro;fwdklvn;q3iornf[uioq wernhvoq n;d",
		"0wd jqwebn rlqvu3bril vjbdk.bvq lejibvksncvjlq webr",
		"2 dfasg aerg jqw34gjqoiwerhf qws",
		"2 np9wenheuiodvh;wklcdnv;oqeirn;g vowefnvmlwneorn 'qefmq;v mep",
		"3 adl lskdfn;glwenhr[3prdfvasd g",
		"3 lhasdlk vnaljkwbhvluiw34hilu fha;wdjvq;w3uioeh.vsd",
		"3 wvnoiwerhuohq3or ;dfjkvn; oqrejfndvj",
		"5 asdh iowerh;oanf ;vower"
	};
	csort(keys_in2, val_in2, k, n, keys_out2, val_out2);
	test("Test sort keys #2", int_arr_eq(keys_out2, keys_exp2));
	test("Test sort values #2", str_arr_eq(val_out2, val_exp2, n));

	return failed;
}


int getMax(int arr[], int size)
{
	int max = 0;
	for (int i = 0; i < size; i++) {
		max = (arr[i] > max ? arr[i] : max);
	}
	return max;
}

void test(const char *t_name, const int t_result)
{
	static char *tg = "\033[32m";
	static char *tr = "\033[31m";
	static char *tn = "\033[0m";

	failed = (t_result ? failed : 1);

	if (!quiet)
		printf("%s%s\t%s%s\n",
				(t_result ? tg : tr),
				t_name,
				(t_result ? "passed!" : "failed!"),
				tn);
}

/**
 * Check equal char arrays
 */
int char_arr_eq(const char *s1, const char *s2)
{
	return strcmp(s1, s2) == 0;
}

int str_arr_eq(char *s1[64], char *s2[64], const int size)
{
	int equal = 1;
	for (int i = 0; i < size; i++) 
		equal = (strcmp(s1[i], s2[i]) == 0 ? equal : 0);

	return equal;
}

/**
 * Check equal int arrays
 */
int int_arr_eq(const int *a, const int *b)
{
	return memcmp(a, b, sizeof(a)) == 0;
}
