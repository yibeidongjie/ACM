#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LengthMAX 100000

/* ==== 全局变量 ==== */
int SG_Value = 0;

/* ==== 函数声明 ==== */
static int GetFn(int A, int B, int n);

static void AcmTest();
static void MyTest();

/* ==== 函数 ==== */
int main(int argc, char *agrv[])
{			
	AcmTest();
	
	//MyTest();
	
	return 0;
}

static void MyTest()
{
	int i;
	
	return ;
}

static void AcmTest()
{
	int i = 0;	
	int A, B, n;
	int Fn;
	while( scanf("%d %d %d", &A, &B, &n) != EOF ) {
		if(A == 0 && B == 0 && n == 0) {
			break;			
		} else {
			Fn = GetFn(A, B, n);
			printf("%d\n", Fn);
		}
		
	}	
	return ;
}


static int GetFn(int A, int B, int n)
{	
	/* Fn 结果 */
	int Fn = 1;
	/* FN_1 = F(n-1); FN_2 = F(n-2) */
	int FN_1 = 1, FN_2 = 1;
	
	/* 经测速发现，对于任意ab，n的最小周期为 6*7*8 */
	int Per = 6 * 7 * 8;
	/* Per周期的起始元素至少是第三个 */
	int iStart = 3;
	
	if(n <= 2) {
		return 1;
	} else {
		/* 使得 0 <= AB <= 6  */
		A = A % 7;
		B = B % 7;
		
		if(A == 0 && B == 0) {
			return 0;
		} else {
			if(n >= (Per + iStart)) {
				n = n % Per;
			}		
			int i = 0;
			/* 注意 i 的起始和结束 */
			for(i = 3; i <= n; i++) {
				Fn = (A * FN_1 + B * FN_2) % 7;
				FN_2 = FN_1;
				FN_1 = Fn;
			}
		}	
	} 
	
	return Fn;
}

















