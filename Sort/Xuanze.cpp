#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
	int tp=a;
	a=b;
	b=tp;
}
int main()
{
	int tp;
	int j;
	int min;
	int arr[]={1,5,4,3,9,7,8,2,6};
	for(int i=0;i<9;++i)
	{
		min=arr[i];
		tp=i;
		for(j=i;j<9;++j)
		{
			if(arr[j]<min)
				{
					tp=j;
					min=arr[j];
				}
		}

	//	cout<<tp<<"  "<<arr[tp]<<endl;
		swap(arr[i],arr[tp]);

	}
	for(int i=0;i<9;++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
