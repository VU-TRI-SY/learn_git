#include <iostream>
using namespace std;
//brute force
int maxsub1(int a[], int n)
{
	int maxsum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			
			int sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum += a[k];
			}
			if (maxsum < sum)
				maxsum = sum;
		}
	}
	return maxsum;
}
int maxsub2(int a[], int n)
{
	int maxsum = 0;

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			if (sum > maxsum)
				maxsum = sum;
		}
	}
	return maxsum;
}
int max(int a, int b, int c)
{
	if (a < b)
	{
		if (b < c)
			return c;
		else
			return b;
	}
	else
	{
		if (a < c)
			return c;
		else
			return a;
	}
}
int maxleft(int a[], int low, int mid)
{
	int maxsum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= low; i--)
	{
		sum += a[i];
		if (sum > maxsum)
			maxsum = sum;
	}
	return maxsum;
}

int maxright(int a[], int mid, int high)
{
	int maxsum = INT_MIN;
	int sum = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += a[i];
		if (sum > maxsum)
			maxsum = sum;
	}
	return maxsum;
}
int maxsub3(int a[], int low, int high)
{
	if (low == high)
		return a[low];
	int mid = (low + high) / 2;
	int ML = maxsub3(a, low, mid);
	int MR = maxsub3(a, mid + 1, high);
	int MM = maxleft(a, low, mid) + maxright(a, mid, high);
	return max(ML, MR, MM);
}

int main()
{
	int a[] = {-2, -5, 20, 21, -12, 34, -10, 7, 6};
	int n = 9;
    int a1=maxsub1(a,n);
    int a2=maxsub2(a,n);
	int a3= maxsub3(a, 0, n - 1);
   
    
	cout << a1<<" "<<a2<<" "<<a3;
}