#pragma once
#ifndef _LINEAR_LIST_H
#define _LINEAR_LIST_H

#include <string>
using namespace std;

const int MAXSIZE = 10;//顺序表的最大限定长度

template<typename T>
class Contiguous_List
{
public:
	T* data; //顺序表的元素，指针用于动态创建
	int length; //顺序表的长度

	//顺序表的插入
	bool ListInsert(int i, T e);
	//顺序表的删除操作
	bool ListDelete(int i, T& e);
	//顺序表的顺序查找
	T LocateElem(T e);
	//顺序表的修改操作
	bool ListUpdate(int i, T e);
	//打印当前所有元素
	string toString();

	Contiguous_List() {}
	Contiguous_List(T* data, int length) { *this->data = data; *this->length = length; }
	~Contiguous_List(){}
};


/*
* @info 插入操作
* @params 插入位置 插入元素
* @returns bool
*/
template<typename T>
bool Contiguous_List<T>::ListInsert(int i, T elem)
{
	if (i < 1 || i > length + 1)//如果插入位置越界
	{
		return false;
	}
	if (length >= MAXSIZE)//数组满了
	{
		return false;
	}
	for (int j = length; j >= i; j--)// 将数组中第i个元素及之后往后移
		data[j] = data[j - 1]; 
	data[i - 1] = elem; // 在数组i上放上插入元素
	length++;
	return true;
}

/*
* @info 删除操作
* @params 删除位置 删除返回元素
* @returns bool 
*/
template<typename T>
bool Contiguous_List<T>::ListDelete(int i, T& elem)
{
	if (i < 1 || i > length)//当删除位置越界
	{
		return false;
	}
	elem = data[i - 1];//获取删除元素
	for (int j = i; j < length; j++)//首先定位到被删除元素的位置
		data[j - 1] = data[j];//将删除位置后的元素往前移
	length--;
	return true;
}

/*
* @info 按值查找
* @params 要查找的元素
* @returns 查找到的元素下标（索引）
*/
template<typename T>
T Contiguous_List<T>::LocateElem(T e)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == e)
		{
			return i+1; //这里不直接用数组下标而是加一好理解一点
		}
	}
	return -1;//没查找到就返回-1
}

/*
* @info 修改操作
* @params 修改位置 需要修改变成的元素
* @returns bool
*/
template<typename T>
bool Contiguous_List<T>::ListUpdate(int i, T elem)
{
	//这里按照计数来，不按照数组的从0开始
	if (i < 1 || i > length)
	{
		return false;
	}
	data[i - 1] = elem; 
	return true;
}

/*
* @info 打印当前所有函数
* @params
* @returns 返回表中所有成员
*/
template<typename T>
string Contiguous_List<T>::toString()
{
	string temp;
	for (int i = 0; i < length; i++)
	{
		//to_string()函数将数字常量转换为string，需要使用头文件<string>
		temp.append(to_string(data[i]));
		temp.append(" ");
	}
	return temp;
}

#endif // !