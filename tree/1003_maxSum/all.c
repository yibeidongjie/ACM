#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SeqLengthMAX 100000

/* ==== 全局变量 ==== */
static int SG_SeqData[SeqLengthMAX];

/* ==== 函数声明 ==== */
static void ToDo(int *MaxSeqSum, int *MaxSeqBegin, int *MaxSeqEnd, int *SeqData, int SeqBegin, int SeqEnd);
static void MaxSeqInMiddle(int *MidMaxSum, int *MidBegin, int *MidEnd, int *SeqData, int SeqBegin, int SeqMid, int SeqEnd);

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
	
	int *SeqData = SG_SeqData;
	
	int NumCase = 0, iCase = 0;
	int SeqLength = 0, SeqBegin = 0, SeqEnd = 0;
	
	int MaxSeqSum = 0, MaxSeqBegin = 0, MaxSeqEnd = 0;
	
	scanf("%d", &NumCase);
	
	while( scanf("%d", &SeqLength) != EOF ) {
		iCase++;
		
		for(i = 0; i < SeqLength; i++) {
			scanf( " %d", &SeqData[i]);
		}
		printf("Case %d:\n", iCase);		
		SeqBegin = 0; 
		SeqEnd = SeqBegin + SeqLength - 1;
		
		/* debug */
			/*
			printf("input is :\n");
			for(i = SeqBegin; i <= SeqEnd; i++) { printf("%d ",SeqData[i]); }
			printf("\n");
			*/
		
		ToDo(&MaxSeqSum, &MaxSeqBegin, &MaxSeqEnd, SeqData, SeqBegin, SeqEnd);
		printf("%d %d %d", MaxSeqSum, MaxSeqBegin + 1, MaxSeqEnd + 1);
		printf("\n");
		
		if(iCase < NumCase) { printf("\n"); }
	}
	
	return ;
}


static void ToDo(int *MaxSeqSum, int *MaxSeqBegin, int *MaxSeqEnd, int *SeqData, int SeqBegin, int SeqEnd)
{	
	int i = 0;
	
	if(SeqData == NULL || SeqBegin < 0 || SeqEnd < 0) { return ; }
	if(MaxSeqSum == NULL || MaxSeqBegin == NULL || MaxSeqEnd == NULL) { return ; }
	
	if(SeqBegin == SeqEnd) {
		*MaxSeqSum = SeqData[SeqBegin];
		*MaxSeqBegin = SeqBegin;
		*MaxSeqEnd = SeqEnd;
		return ;
	}
	
	int SeqMid = (SeqBegin + SeqEnd) >> 1;
	int LeftMaxSum, LeftBegin, LeftEnd;
	int RightMaxSum, RightBegin, RightEnd;
	int MidMaxSum, MidBegin, MidEnd;
	
	ToDo(&LeftMaxSum, &LeftBegin, &LeftEnd, SeqData, SeqBegin, SeqMid);
	ToDo(&RightMaxSum, &RightBegin, &RightEnd, SeqData, SeqMid + 1, SeqEnd);	
	MaxSeqInMiddle(&MidMaxSum, &MidBegin, &MidEnd, SeqData, SeqBegin, SeqMid, SeqEnd);
	
	if(LeftMaxSum >= MidMaxSum && LeftMaxSum >= RightMaxSum) {
		*MaxSeqSum = LeftMaxSum;
		*MaxSeqBegin = LeftBegin;
		*MaxSeqEnd = LeftEnd;
	} else if(MidMaxSum > LeftMaxSum && MidMaxSum >= RightMaxSum) {
		*MaxSeqSum = MidMaxSum;
		*MaxSeqBegin = MidBegin;
		*MaxSeqEnd = MidEnd;
	} else {		
		*MaxSeqSum = RightMaxSum;
		*MaxSeqBegin = RightBegin;
		*MaxSeqEnd = RightEnd;
	}
		
	return ;
}

static void MaxSeqInMiddle(int *MidMaxSum, int *MidBegin, int *MidEnd, int *SeqData, int SeqBegin, int SeqMid, int SeqEnd)
{
	int i;
	int Sum = 0, Max = 0, Index = 0;
	
	*MidMaxSum = 0;
	*MidBegin = SeqMid;
	*MidEnd = SeqMid + 1;
	
	
	Sum = 0;
	Index = SeqMid;
	Max = SeqData[Index];
	for(i = SeqMid; i >= SeqBegin; i--) {
		Sum = Sum + SeqData[i];
		if(Sum >= Max) {
			Max = Sum;
			Index = i;
		}
	}
	*MidMaxSum = (*MidMaxSum) + Max;
	*MidBegin = Index;
	
	Sum = 0;
	Index = SeqMid + 1;
	Max = SeqData[Index];
	for(i = SeqMid + 1; i <= SeqEnd; i++) {
		Sum = Sum + SeqData[i];
		if(Sum > Max) {
			Max = Sum;
			Index = i;
		}
	}
	*MidMaxSum = (*MidMaxSum) + Max;
	*MidEnd = Index;
	
	return ;
}















