#include <iostream>
using namespace std;
class List{
private:
	int elem;
	List *next;
public:
	void insert(List &l,int i,int e){
		List *p=&l;
		int j=0;
		while(j<=i-1)
			{
				p=p->next;
				++j;
			}
		List *s=new List();
		s->elem=e;
		s->next=p->next;
		p->next=s;
	}
	void display(List ls,int i){
		cout<<ls.elem<<endl;
	}
};
int main(){
	List ls;
	ls.insert(ls,1,3);
	ls.display(ls,1);
	system("pause");
	return 0;
}
