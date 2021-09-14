

#include <cstdio>
int partition(int A[], int left, int right) {
    int temp = A[left];
	while (left < right)
	{
		while (left < right && A[right] > temp)
		{
			right--;
		}
		A[left] = A[right];
		while (left< right && A[left] <= temp)
		{
			left++;
		}
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

int Ksort(int A[], int L, int R, int K) {
	if (L == R)
	{
		return A[L];
	}
	int p = partition(A, L, R);
	int M = p - L + 1;  //我写的是int M = p + 1,这样写代码，A[6]={5, 12, 7, 2, 9, 3},k=4时运行发生堆栈溢出。
	if (M == K)
	{
		return A[p];
	}
	if (M > K)
	{
		return Ksort(A, L, p - 1, K);
	}
	else
	{
		return Ksort(A, p + 1, R, K - M);
	}

}

int main()
{
	int A[6], k;
	
	for (int i = 0; i < 6; i++)
	{
		scanf_s("%d", &A[i]);
	}
	scanf_s("%d", &k);
	printf("%d\n", Ksort(A, 0, 5, k)); //开始我误将k写成3，导致一直输出5
	return 0;
}