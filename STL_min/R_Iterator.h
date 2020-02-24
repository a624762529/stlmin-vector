#pragma once

#include<iostream>
using namespace std;
#include"Iterator.h"
//vec_ÄæÏòµü´úÆ÷
template<typename T>
class r_iterator
{

public:
	r_iterator(T *p_);

	r_iterator(const r_iterator& r_iter);
 
	void operator=(const r_iterator& r_iter);
	T& operator *(){ return *point; }
	bool operator ==(r_iterator it_);

	bool operator !=(r_iterator it_);

	r_iterator operator --(int);
	r_iterator operator --();


	r_iterator operator ++(int);
	r_iterator operator ++();

	r_iterator operator -(int n);
	r_iterator operator +(int n);
	int operator -(r_iterator it_);
	void operator =(T* it_);
public:
	T *point;
	typedef typename Iterator_random iterator_;
};

template<typename T>
r_iterator<T>::r_iterator(T *p_)
{
	point = p_;
}

template<typename T>
r_iterator<T>::r_iterator(const r_iterator& r_iter)
{
	point = r_iter.point;
}

template<typename T>
void r_iterator<T>::operator=(const r_iterator& r_iter)
{
	point = r_iter.point;
}

//template<typename T>
//T& r_iterator<T>::operator *()
//{
//	return *point;
//}

template<typename T>
bool r_iterator<T>::operator ==(r_iterator it_)
{
	return point == it_.point;
}

template<typename T>
bool r_iterator<T>::operator !=(r_iterator it_)
{
	return point != it_.point;
}

template<typename T>
r_iterator<T> r_iterator<T>::operator --(int)
{
	Iterator<char> point_temp = point;
	point = _advance(point, 1, r_iterator::iterator_());
	return point_temp.point;
}

template<typename T>
r_iterator<T> r_iterator<T>::operator --()
{
	point = _advance(point, 1, r_iterator::iterator_());
	return point;
}

template<typename T>
r_iterator<T> r_iterator<T>::operator ++(int)
{
	T* point_temp = point;
	point = _advance(point, -1, r_iterator::iterator_());
	return point_temp;
}

template<typename T>
r_iterator<T> r_iterator<T>::operator ++()
{
	point = _advance(point, -1, r_iterator::iterator_());
	return point;
}

template<typename T>
r_iterator<T> r_iterator<T>::operator -(int n)
{
	T *p_ = nullptr;
	p_ = _advance(point, n, r_iterator::iterator_());
	return p_;
}

template<typename T>
r_iterator<T> r_iterator<T>::operator +(int n)
{
	T *p_ = nullptr;
	p_ = _advance(point, -n, r_iterator::iterator_());
	return p_;
}

template<typename T>
int r_iterator<T>::operator -(r_iterator it_)
{
	return  point - it_.point;
}
template<typename T>
void r_iterator<T>::operator =(T* it_)
{
	this->point = it_;
}