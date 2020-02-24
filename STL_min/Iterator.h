#pragma once
//单向迭代器

#include<iostream>
using namespace std;

class Iterator_forword {};
class Iterator_binary :public Iterator_forword {};
class Iterator_random :public Iterator_binary {};


//公共函数 advance
template<typename T>
auto _advance(T &obj, int n, Iterator_random)
{
	return (obj + n);
}

//前驱迭代器(单向)
template<typename T>
auto _advance(T &obj, int n, Iterator_forword)
{
	if (n < 0)
	{
		cerr << "参数异常 file" << __FILE__ << " line:" << __LINE__ << endl;
		throw bad_alloc();
	}
	while (n > 0)
	{
		n--;
		obj--;
	}
	return obj;
}

//公共函数 vec迭代器
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
	T *point;//封装的数据类型
	typedef typename Iterator_random iterator_;//迭代器类型
};

template<typename T>
Iterator<T>::Iterator()//初始化迭代器
{
	point = nullptr;
}

template<typename T>
Iterator<T>::Iterator(T *p_)//初始化迭代器
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
bool Iterator<T>::operator ==(const Iterator<T>& it_)//决策两个迭代器所指的内容是否相同
{
	return point == it_.point;
}

template<typename T>
bool Iterator<T>::operator !=(const Iterator& it_)//决策两个迭代器所指的内容是否相同
{
	return point != it_.point;
}

 

template<typename T>
int Iterator<T>::operator -(Iterator it_)
{
	return  point - it_.point;
}

//template<typename T>
//T& Iterator<T>::operator *()//获取
//{
//	return *point;
//}

template<typename T>
Iterator<T> Iterator<T>::operator --(int)//前置自减
{
	Iterator point_temp = point;
	point = _advance(point, -1, Iterator::iterator_());
	return point_temp;
}

template<typename T>
Iterator<T> Iterator<T>::operator --()//后置自减
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

