#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

#define NumberMax 1000
#define LengthMAX 15

/* ==== 全局变量 ==== */
int SG_Value = 0;
char SG_StrData[NumberMax][LengthMAX] = {"\0", "\0"};
char *SG_pToStrData[NumberMax];

/* ==== 函数声明 ==== */
static char* MostPopularBalloon(int NumBalloon,char **Balloon);
	static void SortBalloon(int NumBalloon, char **Balloon, char **pToBalloon);
		static void QuickSort(char **pToBalloon, int indexBegin, int indexEnd);
		static int Partition(char **pToBalloon, int indexBegin, int indexEnd);

static int CompareTwoStrings(char *Str1, char *Str2);
		
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
	
	char **Balloon = SG_StrData;	
	int NumBalloon = 0;
		
	while( scanf("%d", &NumBalloon) != 0 ) {
		for(i = 0; i < NumBalloon; i++) {
			scanf("%s", Balloon[i]);
		}
			
		char *pPopularBalloon = MostPopularBalloon(NumBalloon, Balloon);
		
		i = 0;
		while(pPopularBalloon[i] != '\0') {
			printf("%c", pPopularBalloon[i]);
		}
		printf("\n");
		
	}
	
	return ;
}


static char* MostPopularBalloon(int NumBalloon, char **Balloon)
{	
	if(Balloon == NULL || *Balloon == NULL) { return NULL; }
	
	char **pToBalloon = SG_pToStrData;
	SortBalloon(NumBalloon, Balloon, pToBalloon);
	
	char *pPopularBalloon = NULL;
	int i = 0;
	
	
	
	
	
	
	
	return pPopularBalloon;
}


static void SortBalloon(int NumBalloon, char **Balloon, char **pToBalloon)
{
	if(NumBalloon < 0 || Balloon == NULL || *Balloon == NULL) { return ; }
	
	int i;
	for(i = 0; i < NumBalloon; i++) {
		pToBalloon[i] = Balloon[i];
	}
	
	QuickSort(pToBalloon, 0, NumBalloon);
	
	return ;
}
static void QuickSort(char **pToBalloon, int indexBegin, int indexEnd)
{
	
	if(indexBegin == indexEnd) {
		return ;
	}
	
	int index = Partition(pToBalloon, indexBegin, indexEnd);
	QuickSort(pToBalloon, indexBegin, index - 1);
	QuickSort(pToBalloon, index + 1, indexEnd);
		
	return ;
}

static int Partition(char **pToBalloon, int indexBegin, int indexEnd)
{
	int KeyIndex = indexEnd;
	
	int indexSmall = indexBegin - 1;
	
	int index;
	for(index = indexBegin; index < indexEnd; index++) {
		int Flag = CompareTwoStrings(pToBalloon[index], pToBalloon[KeyIndex]);
		if(Flag == -1) {
			indexSmall++;
			SwapTwoPointers(&pToBalloon[index], &pToBalloon[indexSmall]);
		}		
	}
	
	indexSmall++;
	SwapTwoPointers(&pToBalloon[indexSmall], &pToBalloon[indexEnd]);	
	
	return indexSmall;
}

static int CompareTwoStrings(char *Str1, char *Str2)
{
	int Flag = 0;
	
	/*
		(*Str1 == *Str2) ==> (Flag = 0);
		(*Str1 > *Str2) ==> (Flag = 1);
		(*Str1 < *Str2) ==> (Flag = -1);
	*/
	
	int i = 0;
	while(Str1[i] != '\0' && Str2[i] != '\0') {
		if(Str1[i] > Str2[i]) {
			Flag = 1; return Flag;
		} else if(Str1[i] < Str2[i]) {
			Flag = -1; return Flag;
		} else {
			i++;
		}		
	}
		
	return Flag;
}

static void SwapTwoPointers(char **p1, char **p2)
{
	if(p1 == NULL || p2 == NULL) { return ; }
	char *pTmp;
	pTmp = *p1;
	*p1 = *p2;
	*p2 = pTmp;
	
	return ;
}










