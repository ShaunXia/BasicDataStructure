#include <iostream>
using namespace std;
class SeqSearch{
	public:
		void createList(int *,int);
		void searchKey(int);
		void display();
	private:
		int listLen;
		int list[32];
		int issucess;
		int pos;
		int count;
};
void SeqSearch::createList(int *arr,int n)
{
	listLen=n;
	for(int i=0;i<n;++i)
	{
		list[i]=arr[i];
	}
}

void SeqSearch::searchKey(int key)
{
	int i=listLen;
	while(list[i]!=key&&i>0) 
		i--;
	issucess=1;
	if(i==0)
		issucess=0;
	pos=0;
	if(i!=0)
		pos=i+1;
	count=listLen-pos+1;
}
void SeqSearch::display()
{
	cout<<issucess<<" "<<pos<<" "<<count<<endl;
}
int main()
{
	SeqSearch seq;
	int usrarr[32];
	int i,j,key;
	int testnum,samplenum;
	cin>>testnum;
	while(testnum--)
	{
		cin>>samplenum;
		for(i=0;i<samplenum;++i)
		{
			cin>>usrarr[i];
		}
		seq.createList(usrarr,samplenum);
		cin>>key;
		seq.searchKey(key);
		seq.display();

	}
	return 0;
}
