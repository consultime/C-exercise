#include <cstdio>
#include <cstdlib>
int n, A[10010];
bool hashT[10010];
int count = 0;
void geP(int index)
{
    if (index == n+1)
    {
        for (int i = 1; i < n+1; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
        count++;
        return;
    }
    for (int x = 1; x < n+1; x++)
    {
        if (hashT[x] == false)
        {
            bool flag = true;
            for (int pre = 1; pre < index; pre++)
            {
                if (abs(index-pre)==abs(x-A[pre]))
                {
                    flag = false; //误写成flag == false;
                    //可以在此加一句break，因有一个pre使得flag为false的话循环就无必要进行下去了。
                }
            }
            if (flag)
            {
                A[index] = x;
                hashT[x] = true;
                geP(index + 1);
                hashT[x] = false;
            }
        }
    }
}

int main()
{
    scanf_s("%d", &n);
    geP(1);
    printf("共有%d种方案\n", count);
    return  0;

}
