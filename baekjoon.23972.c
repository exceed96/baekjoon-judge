#include <stdio.h>

int main(void)
{
	long long K,N, result = 0;

	scanf("%d %d", &K,&N);

	if(N == 1) printf("-1");
	else
	{
		result = (K * N) / (N - 1);
		if((K * N) % (N - 1)) result += 1;
		printf("%d", result);
	}
	return 0;
}
