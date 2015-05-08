//KMP算法 覆盖函数 学习 
// 2012年10月4日0:10:52 
// 真尼玛无聊啊 
#include <iostream>
#include <string>
using namespace std;
int& com_overlay(const string& pattern)
{
	int patlen=pattern.size();
	int *overlay_arr=new int[patlen];
	overlay_arr[0]=-1;
	int i,index;
	for(i=1;i<patlen;++i)
	{
		index=overlay_arr[i-1]; //index 用于判断当前的联系性
		while(index>=0&&pattern[i]!=pattern[index+1]) //如果不连续则将
		{
			index=overlay_arr[index]; 
			//index=-1; 一样效果？？
		}
		if(pattern[i]==pattern[index+1])
		{
			overlay_arr[i]=index+1;
		}
		else
		{
			overlay_arr[i]=-1;
		}
	}
	for(int i=0;i<patlen;++i)
	{
		cout<<overlay_arr[i]<<endl;
	}
	//delete[] overlay_arr;
	return *overlay_arr;
}

void GetNext(const string &p,int next[])
{
    int j = 1,k = 0;
    next[0] = -1;
    next[1] = 0;
    while(j<p.length()-1)
    {
    if(p[j] == p[k])
    {
    next[j+1] = k+1;
    j++;
    k++;
    }
    else if(k == 0)
    {
    next[j+1] = 0;
    j++;
    }
    else k = next[k];
    }
}

int main()
{
	string sources="abacabadababc";
	string pattern="abaabcac";
	            //覆盖数组  -1 -1 0 1
	int i,index;
	int patlen=pattern.size();
	int soulen=sources.size();
	int next[8];
	GetNext(pattern,next);
	for(int i=0;i<patlen;++i)
		cout<<next[i]+1<<" ";

	int *over=&com_overlay(pattern);

	for(int i=0;i<patlen;++i)
		cout<<over[i]+1<<" ";
	index=0;
	for(i=0;i<soulen;++i)
	{

		if(sources[i]==pattern[index])
			index++;
		else
			i+=over[index];
		//for(int j=0;j<patlen;++j)
	//	{

		//}
	}
	system("pause");
	return 0;
}
