#include <stdio.h>
#include <stdlib.h>

static int todo(int a, int b, int n);
static void test();
static void outputData(int a, int b, int nBegin, int nEnd);

static void test1_aEQb();
static void test2();
static void test3();
static void test4();
static void test5();
static void test6();

static void test10();
static void test11();

static int a = 1, b = 1, nBegin = 1, nEnd = 60;

int main()
{
	test();
	
	
	return 0;
}

static void test()
{
	//test1_aEQb();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	
	//test10();
	test11();
		
}

static void outputData(int a, int b, int nBegin, int nEnd)
{
	printf("a=%d, b=%d: \n", a, b, nBegin, nEnd);
	int n;
	int fn;
	for(n = nBegin; n <= nEnd; n++) {
		fn = todo(a, b, n);
		printf("%d-", fn);
	}
	printf("\n");
}

static int todo(int a, int b, int n)
{
	int fn_1 = 1;
	int fn_2 = 1;
	int fn = 0;
	
	if(n <= 2) {
		return 1;
	} else {
		int i;
		for(i = 0; i < n-2; i++) {
			fn = (a * fn_1 + b * fn_2) % 7;		
			fn_2 = fn_1;
			fn_1 = fn;
		}
	}
	
	return fn;
}

static void test1_aEQb()
{
	int i;
	for(i = 1; i <= 15; i++) {
		a = i; b = i;
		outputData(a, b, nBegin, nEnd);
	}	
}

static void test2()
{
	int i;
	for(i = 1; i <= 15; i++) {
		a = i; b = i + 1;
		outputData(a, b, nBegin, nEnd);
	}	
}

static void test3()
{
	int i;
	for(i = 1; i <= 15; i++) {
		a = i; b = i + 2;
		outputData(a, b, nBegin, nEnd);
	}	
}

static void test4()
{
	int i;
	for(i = 1; i <= 15; i++) {
		a = i + 1; b = i;
		outputData(a, b, nBegin, nEnd);
	}	
}

static void test5()
{
	int i;
	for(i = 1; i <= 15; i++) {
		a = i; b = 16 - a;
		outputData(a, b, nBegin, nEnd);
	}	
}

static void test6()
{
	int i;
	for(i = 1; i <= 14; i++) {
		a = i; b = 15 - a;
		outputData(a, b, nBegin, nEnd);
	}	
}


static void test10()
{
	int i;
	int abSum;
	for(abSum = 2; abSum <= 15; abSum++) {
		for(i = 1; i < abSum; i++) {
			a = i; b = abSum - a;
			outputData(a, b, nBegin, nEnd);
		}
	}
	
	return ;
}

static void test11()
{
	int i;
	int abSum;
	for(a = 1; a <= 7; a++) {
		for(b = 1; b <= 7; b++) {
			outputData(a, b, nBegin, nEnd);
		}
	}
	
	return ;
}














