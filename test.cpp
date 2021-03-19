#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main1(){
	int tmp = 0;
	#pragma omp parallel for //deleted by xwang
	for (int j=0; j<5;j++)
		tmp += j;
	printf("%d\n", tmp);
	return 1;
}

int main2(){
	int a, j;
	#pragma omp parallel for private(j) lastprivate(a)
	for (j=0; j<5;j++)
	{
		a = j + 2;
		printf("Thread %d has a value of a = %d for j = %d\n", omp_get_thread_num(), a, j);
	}
}

int main()
{
	return main2();
}