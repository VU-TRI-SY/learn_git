#include <bits/stdc++.h>
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
int max1(int a,int b){
    if(a>b) return a;
    else return b;
}
int maxsub4(int a[],int n){
    int smax=a[0];
    int ei=a[0];
    for(int i=1;i<=n-1;i++){
        ei=max1(a[i],a[i]+ei);
        smax=max1(ei,smax);
    }
    return smax;
}
int main()
{
	int a[1000];
    int n=1000;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i]=rand()%1000-300;
    }
    clock_t t;
    t=clock();
    int a1=maxsub1(a,n);
    t=clock()-t;
    cout<<"1)Brute force:value of sub array:"<<a1<<endl;
    cout<<"time="<<(float) t/CLOCKS_PER_SEC<<" second"<<endl;
    t=clock();
    int a2=maxsub2(a,n);
    t=clock()-t;
    cout<<"2)Brute force with better implementation:value of sub array:"<<a2<<endl;
    cout<<"time="<<(float) t/CLOCKS_PER_SEC<<" second"<<endl;
	t=clock();
    int a3=maxsub3(a,0,n-1);
    t=clock()-t;
    cout<<"3)Recursive(Divide and concer):value of sub array:"<<a3<<endl;
    cout<<"time="<<(float) t/CLOCKS_PER_SEC<<" second"<<endl;
    t=clock();
    int a4=maxsub4(a,n);
    t=clock()-t;
    cout<<"4)Dynamic programming:value of sub array:"<<a4<<endl;
    cout<<"time="<<(float) t/CLOCKS_PER_SEC<<" second"<<endl;
    
}