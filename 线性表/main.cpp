#include <iostream>
#include "contiguous_list.h"
using namespace std;

void Contiguous_List_Manpulate()
{
	//需要取出顺序表的话，传入参数加上个引用就行
	Contiguous_List<int> l;
	l.data = (int*)malloc(sizeof(int) * 10);
	l.length = 0;
	for (int i = 0; i < 5; i++)
	{
		l.data[i] = i + 1;
		l.length++;
	}//赋值完后为 1 2 3 4 5， length = 5
	int temp;
	l.ListInsert(3, 10);//1 2 10 3 4 5, length = 6
	l.ListDelete(2, temp);//1 10 3 4 5, length = 5
	l.ListUpdate(1, 20);//20 10 3 4 5, length = 5
	cout << l.toString() << endl;
	cout << temp << endl; // temp = 2
}

int main()
{
	Contiguous_List_Manpulate();
	return 0;
}