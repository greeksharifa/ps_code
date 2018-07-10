#include "re_define.h"
#include "bit_library.h"

#include <stdio.h>
#include <vector>
int arr[11] = {0, 5, 3, 1, 0, 9, 3, -2, 6, -5, 2};
struct FenwickTree
{
    int size;
    vector<int> data;
    FenwickTree(int N){
        size = 1;
        while (size < N){
            size <<= 1;
        }
        data = vector<int>(size + 1, 0);
        for (int i = 1; i <= N; i++)
        {
            int j = i;
            while (j <= size)
            {
                data[j] += arr[i];
                j += j & (-j);
            }
        }
    }
    void update(int n, int val)
    {
        int before = n;
        while (n <= size)
        {
            data[n] += val – arr[before];
            n += n & (-n);
        }
        arr[before] = val;
    }
    int sum(int n)
    {
        int result = 0;
        while (n)
        {
            result += data[n];
            n &= n – 1;
        }
        return result;
    }
    int sum(int a, int b)
    {
        return sum(b) – sum(a – 1);
    }
};
int main()
{
    FenwickTree BIT = FenwickTree(10);
    printf(“% d\n”, BIT.sum(2, 5));
    BIT.update(4, 7);
    printf(“% d\n”, BIT.sum(2, 5));
    return 0;
}
