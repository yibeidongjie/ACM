#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void sumOf_ab(int *abSum, int *sumLength, int *a, int aLength, int *b, int bLength);

int main(int argc, char *agrv[])
{
	int numCase = 0;
	char a[1000], b[1000]; 
	int abSum[1000 + 1];
	int aLength = 0, bLength = 0, sumLength = 0;
	
	scanf("%d", &numCase);
	int iCase = 0;
	while( scanf(""%s %s", a, b) != EOF ) {
		aLength = strlen(a);
		bLength = strlen(b);
		iCase++;
		printf("Case %d:\n", iCase);
		sumOf_ab(abSum, &sumLength, a, aLength, b, bLength);
		
		printf();
		printf("\n");
	}
	
	return 0;
}

static void sumOf_ab(int *abSum, int *sumLength, int *a, int aLength, int *b, int bLength)
{
	
}

















