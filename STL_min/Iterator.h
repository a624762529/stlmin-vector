#pragma once
//���������

#include<iostream>
using namespace std;

class Iterator_forword {};
class Iterator_binary :public Iterator_forword {};
class Iterator_random :public Iterator_binary {};


//�������� advance
template<typename T>
auto _advance(T &obj, int n, Iterator_random)
{
	return (obj + n);
}

//ǰ��������(����)
template<typename T>
auto _advance(T &obj, int n, Iterator_forword)
{
	if (n < 0)
	{
		cerr << "�����쳣 file" << __FILE__ << " line:" << __LINE__ << endl;
		throw bad_alloc();
	}
	while (n > 0)
	{
		n--;
		obj--;
	}
	return obj;
}

//�������� vec������
template<typename T>
class Iterator
{

public:
	Iterator(T *p_);
	Iterator();
	Iterator(const Iterator& iter);
	void operator=(const Iterator& iter);
	bool operator ==(const Iterator& it_);
	bool operator !=(const Iterator& it_);
	T& operator *() { return *point; }
	Iterator operator --(int);
	Iterator operator --();
	Iterator operator ++(int);
	Iterator operator ++();
	Iterator operator -(int n);
	int operator -(Iterator it_);
	Iterator operator +(int n);
public:
	T *point;//��װ����������
	typedef typename Iterator_random iterator_;//����������
};

template<typename T>
Iterator<T>::Iterator()//��ʼ��������
{
	point = nullptr;
}

template<typename T>
Iterator<T>::Iterator(T *p_)//��ʼ��������
{
	point = p_;
}

template<typename T>
Iterator<T>::Iterator(const Iterator& iter)
{
	this->point = iter.point;
}

template<typename T>
void Iterator<T>::operator=(const Iterator<T>& iter)
{
	this->point = iter.point;
}

template<typename T>
bool Iterator<T>::operator ==(const Iterator<T>& it_)//����������������ָ�������Ƿ���ͬ
{
	return point == it_.point;
}

template<typename T>
bool Iterator<T>::operator !=(const Iterator& it_)//����������������ָ�������Ƿ���ͬ
{
	return point != it_.point;
}

 

template<typename T>
int Iterator<T>::operator -(Iterator it_)
{
	return  point - it_.point;
}

//template<typename T>
//T& Iterator<T>::operator *()//��ȡ
//{
//	return *point;
//}

template<typename T>
Iterator<T> Iterator<T>::operator --(int)//ǰ���Լ�
{
	Iterator point_temp = point;
	point = _advance(point, -1, Iterator::iterator_());
	return point_temp;
}

template<typename T>
Iterator<T> Iterator<T>::operator --()//�����Լ�
{
	point = _advance(point, -1, Iterator::iterator_());
	return point;
}

template<typename T>
Iterator<T> Iterator<T>::operator ++(int)
{
	T* point_temp = point;
	point = _advance(point, 1, Iterator::iterator_());
	return point_temp;
}

template<typename T>
Iterator<T> Iterator<T>::operator ++()
{
	point = _advance(point, 1, Iterator::iterator_());
	return point;
}

template<typename T>
Iterator<T> Iterator<T>::operator -(int n)
{
	T *p_ = nullptr;
	p_ = _advance(point, -n, Iterator::iterator_());
	return p_;
}
 
template<typename T>
Iterator<T> Iterator<T>::operator +(int n)
{
	T *p_ = nullptr;
	p_ = _advance(point, n, Iterator::iterator_());
	return p_;
}

