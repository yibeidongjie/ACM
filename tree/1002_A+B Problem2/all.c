#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void sumOf_ab(int *abSum, int *sumLength, char *a, int aLength, char *b, int bLength);
static void acmTest();
static void myTest();

int main(int argc, char *agrv[])
{			
	acmTest();
	
	//myTest();
	
	return 0;
}

static void myTest()
{
	int numCase = 0;
	char a[1000] = "123456789123456789123456789";
	char b[1000] = "987654321987654321987654321"; 
	int abSum[1000 + 1];
	int aLength = 0, bLength = 0, sumLength = 0;
	
	int i;
	int iCase = 0;
	
	aLength = strlen(a);
	bLength = strlen(b);
	iCase++;
	printf("Case %d:\n", iCase);
	printf("%s + %s = ", a, b);
	
	sumOf_ab(abSum, &sumLength, a, aLength, b, bLength);	
	for(i = 0; i < sumLength; i++) {
		printf("%d", abSum[i]);
	}		
	printf("\n");
	
	return ;
}

static void acmTest()
{
	int numCase = 0;
	char a[1000], b[1000]; 
	int abSum[1000 + 1];
	int aLength = 0, bLength = 0, sumLength = 0;
	
	int i = 0;
	int iCase = 0;
	
	scanf("%d", &numCase);
	
	while( scanf("%s %s", a, b) != EOF ) {
		aLength = strlen(a);
		bLength = strlen(b);
		
		iCase++;
		printf("Case %d:\n", iCase);
		
		printf("%s + %s = ", a, b);
		
		sumOf_ab(abSum, &sumLength, a, aLength, b, bLength);	
		
		for(i = 0; i < sumLength; i++) {
			printf("%d", abSum[i]);
		}		
		printf("\n");
		
		if(iCase < numCase) { printf("\n"); }  // 最后一个case不需要换行!!!
		
		sumLength = 0;
	}
	return ;
}


static void sumOf_ab(int *abSum, int *sumLength, char *a, int aLength, char *b, int bLength)
{
	//if(a == NULL || b == NULL || aLength <= 0 || bLength <= 0) { return ; }
	//if(abSum == NULL) { return ; }
	
	int i = 0;
	
	for(i = 0; i < aLength; i++) {
		if(a[i] > '9' || a[i] < '0') { return ; }
	}
	for(i = 0; i < bLength; i++) {
		if(b[i] > '9' || b[i] < '0') { return ; }
	}
	
	char tmpA[2], tmpB[2];
	tmpA[1] = '\0';
	tmpB[1] = '\0';
	
	int dLength = 0;
	int lengthLong = aLength, lengthShort = bLength;
	/* 调整a和b中元素的位置，使得a和b的长度相同 */ 
	if(aLength > bLength) {
		lengthLong = aLength;
		lengthShort = bLength;
		dLength = lengthLong - lengthShort;
		
		for(i = lengthLong - 1; i >= dLength; i--) {
			b[i] = b[i - dLength];
		}
		for(i = 0; i < dLength; i++) {
			b[i] = '0';
		}
		
	} else if(aLength < bLength) {
		lengthLong = bLength;
		lengthShort = aLength;
		dLength = lengthLong - lengthShort;
		
		for(i = lengthLong - 1; i >= dLength; i--) {
			a[i] = a[i - dLength];
		}
		for(i = 0; i < dLength; i++) {
			a[i] = '0';
		}
	} else {
		lengthLong = aLength;
		lengthShort = bLength;
	}
	
	/* 假设最高位会进位 */
	*sumLength = lengthLong + 1;
	abSum[0] = 0;
	
	/* 从个位开始累加 */
	for(i = lengthLong - 1; i >= 0; i--) {
		tmpA[0] = a[i];
		tmpB[0] = b[i];
		abSum[i + 1] = atoi(tmpA) + atoi(tmpB);		
	}
	
	/* 处理abSum中的进位问题 */
	for(i = (*sumLength) - 1; i >= 1; i--) {
		if(abSum[i] > 9) {
			abSum[i] -= 10;
			abSum[i - 1]++;
		}
	}
	
	/* 判断最高位是否进位 */
	if(abSum[0] == 0) {
		for(i = 0; i < (*sumLength) - 1; i++) {
			abSum[i] = abSum[i + 1 ];
		}
		(*sumLength)--;
	}
	
	return ;
}

















