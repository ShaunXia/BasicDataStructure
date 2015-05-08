#include <iostream>
using namespace std;
int qsort(int arr[],int l,int r)
{  
	if (l < r)
	{
		int pivot=arr[l];
		int ll=l;
		int rr=r;
		while(ll<rr)
		{
			while(ll<rr&&arr[rr]>=pivot)
				--rr;
			if(ll<rr)
				arr[ll++]=arr[rr];
			while(ll<rr&&arr[ll]<=pivot)
				++ll;
			if(ll<rr)
				arr[rr--]=arr[ll];
		}
		arr[ll]=pivot;
		qsort(arr,l,ll-1);
		qsort(arr,ll+1,r);
	}
}
	
int main()
{
	int arr[10]={5,7,8,4,2,6,9,3,1,0};
	qsort(arr,0,9);
	for(int i=0;i<10;++i){
		cout<<arr[i]<<" ";
	}
}
