#pragma once
#ifndef _LINEAR_LIST_H
#define _LINEAR_LIST_H

#include <string>
using namespace std;

const int MAXSIZE = 10;//˳��������޶�����

template<typename T>
class Contiguous_List
{
public:
	T* data; //˳����Ԫ�أ�ָ�����ڶ�̬����
	int length; //˳���ĳ���

	//˳���Ĳ���
	bool ListInsert(int i, T e);
	//˳����ɾ������
	bool ListDelete(int i, T& e);
	//˳����˳�����
	T LocateElem(T e);
	//˳�����޸Ĳ���
	bool ListUpdate(int i, T e);
	//��ӡ��ǰ����Ԫ��
	string toString();

	Contiguous_List() {}
	Contiguous_List(T* data, int length) { *this->data = data; *this->length = length; }
	~Contiguous_List(){}
};


/*
* @info �������
* @params ����λ�� ����Ԫ��
* @returns bool
*/
template<typename T>
bool Contiguous_List<T>::ListInsert(int i, T elem)
{
	if (i < 1 || i > length + 1)//�������λ��Խ��
	{
		return false;
	}
	if (length >= MAXSIZE)//��������
	{
		return false;
	}
	for (int j = length; j >= i; j--)// �������е�i��Ԫ�ؼ�֮��������
		data[j] = data[j - 1]; 
	data[i - 1] = elem; // ������i�Ϸ��ϲ���Ԫ��
	length++;
	return true;
}

/*
* @info ɾ������
* @params ɾ��λ�� ɾ������Ԫ��
* @returns bool 
*/
template<typename T>
bool Contiguous_List<T>::ListDelete(int i, T& elem)
{
	if (i < 1 || i > length)//��ɾ��λ��Խ��
	{
		return false;
	}
	elem = data[i - 1];//��ȡɾ��Ԫ��
	for (int j = i; j < length; j++)//���ȶ�λ����ɾ��Ԫ�ص�λ��
		data[j - 1] = data[j];//��ɾ��λ�ú��Ԫ����ǰ��
	length--;
	return true;
}

/*
* @info ��ֵ����
* @params Ҫ���ҵ�Ԫ��
* @returns ���ҵ���Ԫ���±꣨������
*/
template<typename T>
T Contiguous_List<T>::LocateElem(T e)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == e)
		{
			return i+1; //���ﲻֱ���������±���Ǽ�һ�����һ��
		}
	}
	return -1;//û���ҵ��ͷ���-1
}

/*
* @info �޸Ĳ���
* @params �޸�λ�� ��Ҫ�޸ı�ɵ�Ԫ��
* @returns bool
*/
template<typename T>
bool Contiguous_List<T>::ListUpdate(int i, T elem)
{
	//���ﰴ�ռ�����������������Ĵ�0��ʼ
	if (i < 1 || i > length)
	{
		return false;
	}
	data[i - 1] = elem; 
	return true;
}

/*
* @info ��ӡ��ǰ���к���
* @params
* @returns ���ر������г�Ա
*/
template<typename T>
string Contiguous_List<T>::toString()
{
	string temp;
	for (int i = 0; i < length; i++)
	{
		//to_string()���������ֳ���ת��Ϊstring����Ҫʹ��ͷ�ļ�<string>
		temp.append(to_string(data[i]));
		temp.append(" ");
	}
	return temp;
}

#endif // !