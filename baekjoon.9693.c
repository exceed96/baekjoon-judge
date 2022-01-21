#include <stdio.h>
/*수정*/
/*수정2*/
int main(void)
{
	int i = 1;
	while(1)
	{
		int N, r = 0;
		scanf("%d", &N);
		if(!N) break;
		else
		{
			while(N)
			{
				r += N / 5;
				N /= 5;
			}
		}
		printf("Case #%d: %d\n",i,r);
		i++;
	}
	return 0;
}
