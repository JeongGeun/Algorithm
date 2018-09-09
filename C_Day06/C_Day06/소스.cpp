#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STUDENT 4
#define SUBJECT_COUNT 2
#define KOR 0
#define ENG 1
void CreateMemorySet(float *arr, int count);
void plus(int a, int *b);
void check(int *arr);
int main()
{
	//int* arr=0;
	//int count=5;
	//int n=0;
	//int b=116;
	//if(arr==0)
	//{
	//	arr=(int*)malloc(count*(sizeof(int)));
	//}
	//for(n=0;n<count;++n)
	//{
	//	arr[n]=n+1;
	//}
	//for(n=0;n<count;++n)
	//	printf("arr[%d]=%d\n",n,arr[n]);
	///*arr=&b;
	//printf("*arr:%d\n",*arr);
	//printf("*arr[3]:%d\n",arr[3]);*/
	//if(arr!=0)
	//{
	//	free(arr);
	//	arr=0;
	//}

	//float* farr=0;
	//int a=10;
	//CreateMemorySet(&farr,10);
	////printf("a=%d\n",a);
	////plus(8,&a);
	////printf("a=%d\n",a);
	//free(farr);
	//farr=0;


	/*int *farr=0;
	check(&farr);*/
	/*int Scores[SUBJECT_COUNT][STUDENT]={0,};
	char *SubjectName[]={"국어","영어"};
	int n=0,m=0;
	int selectSub=0;
	int selectStu=0;
	int isExit=0;

	char *buff=0;
	srand(time(0));
	for(n=0;n<SUBJECT_COUNT;++n)
	{
	for(m=0;m<STUDENT;++m)
	{
	Scores[n][m]=rand()%101;
	}
	}

	for(n=0;n<SUBJECT_COUNT;++n)
	{
	buff=SubjectName[n];
	for(m=0;m<STUDENT;++m)
	{
	printf("[%d번 %s점수   : %d]\n",m+1,buff,Scores[n][m]);
	}
	}

	while(!isExit)
	{
	printf("1.국어\n2.영어\n열람하고 싶은 과목을 선택하세요: ");
	scanf_s("%d",&selectSub);
	switch(selectSub)
	{
	case 1:
	selectSub=KOR;
	isExit=1;
	break;
	case 2:
	selectSub=ENG;
	isExit=1;
	break;
	default:
	printf("다시 입력하세요.\n");
	break;
	}
	}

	while(1)
	{
	printf("열람하고 싶은 학생을 선택하세요(1~%d): ",STUDENT);
	scanf_s("%d",&selectStu);
	if(selectStu<1||selectStu>STUDENT)
	{
	printf("다시입력하세요\n");
	}
	else
	{
	selectStu--;
	break;
	}
	}
	printf("열람하신 학생의 점수: %d\n",Scores[selectSub][selectStu]);*/
	int n = 3;
	int *p = &n;
	int **pp = &p;
	printf("%d\n", n);
	printf("%d\n", &n);
	printf("%d\n", p);//위와 같음
	printf("%d\n", *p);//3
	printf("%d\n", *pp);//위와같음
	printf("%d\n", **pp);//3
	printf("%d\n", pp);
	system("pause");
}

void plus(int a, int *b)

{

	*b += a;

}

void CreateMemorySet(float **arr, int count)

{



	*arr = (float*)malloc(count * sizeof(float));



}

void check(int **arr)

{

	int num = 0;

	int i = 0;

	int tot = 0;

	int score = 0;

	srand(time(0));

	printf("학생 수를 입력하세요: ");

	scanf_s("%d", &num);

	*arr = (int*)malloc(num * sizeof(int));

	for (i = 0; i<num; i++)

	{



		score = rand() % 60 + 40;

		(*arr)[i] = score;

		printf("%d번: %d\n", i + 1, score);

	}

	for (i = 0; i<num; i++)

	{

		tot += (*arr)[i];

	}

	printf("전체 평균: %.2f", (float)tot / num);



}




