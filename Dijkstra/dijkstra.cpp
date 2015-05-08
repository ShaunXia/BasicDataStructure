#include <iostream>
#include <string>
using namespace std;
class Dijkstra
{
public:
	Dijkstra(int n);
	void input();
	void display();
	void search();
private:
	int vertexNum;
	char *vertexChar;
	int **vertex;
	char start;
	int startloc;
	int *D;
	int *P;
	int *S;
};
Dijkstra::Dijkstra(int n)
{
	vertexNum=n;
	int **vertexx=new int*[vertexNum];
	vertex=vertexx;
	vertexChar=new char[vertexNum];
	D=new int[vertexNum];
	P=new int[vertexNum];
	S=new int[vertexNum];
	for(int i=0;i<vertexNum;++i)
	{
		D[i]=9999;
	}
	P[0]=0;
	input();
}
void Dijkstra::input()
{
	int i,j;
	for(i=0;i<vertexNum;++i)
	{
		cin>>vertexChar[i];
	}
	for(i=0;i<vertexNum;++i)
	{
		vertex[i]=new int[vertexNum];
		for(j=0;j<vertexNum;++j)
		{
			cin>>vertex[i][j];
			if(vertex[i][j]==-1)
				vertex[i][j]=9999;
		}
	}
	cin>>start;
}

void Dijkstra::search()
{
	int count=1,i,j,k,min=99999;
	int *visited=new int[vertexNum];
	for(i=0;i<vertexNum;++i)
	{
		visited[i]=0;
	}
	//找到开始点
	for(i=0;i<vertexNum;++i)
	{
		if(start==vertexChar[i])
			startloc=i;
	}

	visited[startloc]=1; 

	// 第一次初始化
	for(j=0;j<vertexNum;++j)
	{
		if(vertex[startloc][j]!=9999&&startloc!=j)
		{
			D[j]=vertex[startloc][j];
			P[j]=startloc;
			if(min>vertex[startloc][j])
				min=j;
		}
	}

	count=1;
	int flag=1;
	visited[min]=1;
	// 循环查找
	while(1)
	{
		flag=1;
		for(i=0;i<vertexNum;++i)
		{
			if(D[min]+vertex[min][i]<D[i])
				{
					D[i]=D[min]+vertex[min][i];
					P[i]=min;
				}

		}

		visited[min]=1;

		min=9000;

		for(i=0;i<vertexNum;++i)
		{
			if(D[i]<min&&visited[i]==0)
					min=i;
		}

		cout<<min<<endl;

		for(i=0;i<vertexNum;++i)
		{
			if(visited[i]==0)
				flag=0;
		}
		if(flag==1)
			break;
	}
}

void Dijkstra::display()
{
	for(int i=0;i<vertexNum;++i)
	{
		cout<<D[i]<<" ";
	}

	for(int i=0;i<vertexNum;++i)
	{
		cout<<P[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int i,j,k,n,temp;
	cin>>n;
	Dijkstra dijk(n);
	dijk.search();
	dijk.display();
	return 0;
}

