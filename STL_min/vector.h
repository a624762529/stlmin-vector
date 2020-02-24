#pragma once
#include<iostream>
#include<string.h>
#include"mem_pool.h"
#include<ostream>
#include<string.h>
#include"R_Iterator.h"
#include"Iterator.h"
using namespace std;
 
//mem_pool alloc;

//vector��ʵ��
template<typename T, typename alloctype = mem_pool_>
class Vector
{
public:
	typedef typename T   value_type;//ģ������
	typedef typename T&  reference_type;//��������
	typedef typename T&& re_typenme;//��ֵ��������
	typedef typename Iterator<T>   iterator;
	typedef typename r_iterator<T> riterator;
	typedef typename Iterator<const T> const_iter_vec;
public:
	Vector();
	Vector(int size_);
	Vector(int size_, T value);
	Vector(const Vector &vec) ;
	Vector(Vector::iterator begin, Vector::iterator end);
	bool operator=(const Vector &vec);
	T operator[](int a);
	~Vector();
public:
	//�������
	void push_back(const T &value);
	void push_front(const T &value);
	void insert(Vector::iterator iter, int value);
	void insert(Vector::iterator pos, Vector::iterator bg, Vector::iterator ed);
	void clean();
public:
	//ɾ������
	Vector::iterator erase(Vector::iterator begin_, Vector::iterator end_);
	Vector::iterator erase(Vector::iterator it);
	void pop_front();
	Vector::iterator begin();
	Vector::iterator end();
	Vector::riterator r_begin();
	Vector::riterator r_end();
	riterator r__rend();
public:
	int size_vec();
	int capacity();
public:
	Vector::iterator find(T value);
	Vector::riterator rfind(T value);

	template<typename execute>
	Vector::iterator find_if(T value, execute obj);

	template<typename execute>
	Vector::riterator rfind_if(T value, execute obj);
private:
	//obj ����Ҫ�����ֵ value��finҪ���ڵ�ֵ
	int reload(int obj, int value);
	//����mem�ķ���
	void *refill(int size);
	void move_n_front(Vector::iterator it_begin, Vector::iterator it_end, int n);
private:
	//˳��������ĵײ�ӿ�
	Vector::iterator __begin();
	Vector::iterator __end();
	Vector::riterator __rbegin();
	Vector::riterator __rend();
	Vector::iterator __advance(Vector::iterator it, int n);
	void __push_back(const T value);
	void __push_font(const T value);
private:
	void clean_mem();
	void move_n_back(Vector::iterator it_begin, Vector::iterator it_end, int n);
	void move_one_back(Vector::iterator it_begin, Vector::iterator it_end);
	Vector::iterator _insert_aux(Vector::iterator it, int value);
private:
	T *m_arry;
	int m_size;
	int m_max_size;
	alloctype m_alloc;
};

template<typename T, typename alloctype>
Vector<T, alloctype>::Vector()
{
	m_arry = (T*)m_alloc.alloc(sizeof(T));
	memset(m_arry, 0, 1 * sizeof(T));
	m_size = 0;
	m_max_size = 1;
}


template<typename T, typename alloctype>
Vector<T, alloctype>::~Vector()
{
	this->clean_mem();
}

template<typename T, typename alloctype>
Vector<T, alloctype>::Vector(int size_)
{
	if (m_arry != nullptr)
		clean_mem();
	m_arry = (T*)m_alloc.alloc(sizeof(T) * size_);
	memset(m_arry, 0, size_ * sizeof(T));
	m_size = 0;
	m_max_size = size_;
}

template<typename T, typename alloctype>
Vector<T, alloctype>::Vector(int size_, T value)
{
	//�����ڴ�������Ӧ��С�Ŀռ�
	m_arry = (T*)m_alloc.alloc(sizeof(T) * size_);
	memset(m_arry, 0, size_ * sizeof(T));

	//����Ӧ�Ŀռ�����val
	//for (iterator it = begin(); it != end(); it++)
	//{
	//	*it = value;
	//}
	iterator it = begin();
	for (int i = 0; i < size_; i++)
	{
		(*it) = value;
		it++;
	}
	m_size = size_;
	m_max_size = size_;
}

template<typename T, typename alloctype>
Vector<T, alloctype>::Vector(const Vector &vec) : Vector(vec.m_max_size)
{
	m_size =  (const_cast<Vector*>(&vec))->size_vec();
	memcpy(m_arry, vec.m_arry, this->m_size * sizeof(T));
}

 
template<typename T, typename alloctype>
Vector<T, alloctype>::Vector(Vector::iterator begin, Vector::iterator end)
{
	m_arry = (T*)m_alloc.alloc(sizeof(T) * 5);
	memset(m_arry, 0, sizeof(5) * sizeof(T));
	m_size = 0;
	m_max_size = 5;
	for (Vector::iterator it = begin; it != end; it++)
	{
		__push_back(*it);
	}
}

template<typename T, typename alloctype>
bool Vector<T, alloctype>::operator=(const Vector &vec)
{
	clean_mem();
	refill(vec.m_max_size);
	m_size = vec.m_size;
	memcpy(m_arry, vec.m_arry, (vec.m_size * sizeof(T)));
	return true;
}

template<typename T, typename alloctype>
T Vector<T, alloctype>::operator[](int a)
{
	if (a > m_size)
		exit(0);
	return m_arry[a];
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::push_back(const T &value)
{
	__push_back(value);
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::push_front(const T &value)
{
	if (m_size == 0)
	{
		push_back(value);
		return;
	}
	__push_font(value);
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::insert(Vector::iterator iter, int value)
{
	
	if (iter == end())
	{
		__push_back(value);
	}
	else
	{
		if (m_size >= (m_max_size - 1))
		{
			int len = (iter - begin());
			refill(m_max_size * 2);
			iter = begin() + len;
		}
		_insert_aux(iter, value);
	}
}


template<typename T, typename alloctype>
void Vector<T, alloctype>::insert(Vector::iterator pos, Vector::iterator bg, Vector::iterator ed)
{
	int n = ed - bg;
	//iter��ǰ�ڵ��λ��
	iterator iter = pos;
	iterator cur = bg;
	//��������ڵ�ʣ��ռ䲻��Ļ�
	if (m_size + n >= (m_max_size - 1))
	{
		int len = (iter - begin());
		int to_increase = m_size + n;
		to_increase = reload(m_max_size, to_increase);
		refill(to_increase);
		iter = begin() + len;//�ض�λiter
		m_size += n;
	}
	//move_n_back(Iterator_vec it_begin, Iterator_vec it_end, int n)
	move_n_back(iter, end(), n);
	for (iterator it_ = iter; it_ != (iter + n); it_++)
	{
		*it_ = *cur;
		cur++;
	}
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::clean()
{
	memset(m_arry, 0, sizeof(m_arry));
	m_size = 0;
}

//ɾ������
template<typename T, typename alloctype>
typename Vector<T, alloctype>::iterator 
	Vector<T, alloctype>::erase( iterator begin_, iterator end_)
{
	if (begin_ == end_)
	{
		return erase(begin_);
	}
	int len_cur = begin_ - begin();
	int n = end_ - begin_;
	move_n_front(end_, this->end(), n);
	m_size = m_size - n;
	return begin() + len_cur;
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::iterator 
	Vector<T, alloctype>::erase( iterator it)
{
	if (it == begin())
	{
		pop_front();
		m_size = m_size - 1;
		return begin();
	}
	else if (it == (end() - 1))
	{
		m_size--;
		return (end() - 1);
	}
	int len_cur = it - begin();
	move_n_front(it + 1, this->end(), 1);
	m_size = m_size - 1;
	return begin() + len_cur;
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::pop_front()
{
	Vector::iterator bg = begin();
	Vector::iterator cur = begin() + 1;
	for (cur; cur != end(); cur++)
	{
		*bg = *cur;
		bg++;
	}
}
//����������
template<typename T, typename alloctype>
typename Vector<T, alloctype>::iterator 
	Vector<T, alloctype>::begin()
{
	return __begin();
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::iterator
	Vector<T, alloctype>::end()
{
	return __end();
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::riterator
	Vector<T, alloctype>::r_begin()
{
	return  (end()-1).point;
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::riterator
	Vector<T, alloctype>::r_end()
{
	return (begin()-1).point;
}

template<typename T, typename alloctype>
int Vector<T, alloctype>::size_vec()
{
	return this->m_size;
}

template<typename T, typename alloctype>
int Vector<T, alloctype>::capacity()
{
	return this->m_max_size;
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::iterator
	Vector<T, alloctype>::find(T value)
{
	for (Vector::iterator it = begin(); it != end(); it++)
	{
		if (*it == value)
		{
			return it;
		}
	}
	return end();
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::riterator
	Vector<T, alloctype>::rfind(T value)
{
	for (riterator it = __rbegin(); it != __rend(); it++)
	{
		if (*it == value)
		{
			return it;
		}
	}
	return end().point;
}

template<typename T, typename alloctype>
template<typename execute>
typename Vector<T, alloctype>::iterator
	Vector<T, alloctype>::find_if(T value, execute obj)
{
	for (iterator it = begin(); it != end(); it++)
	{
		if (obj(value))
		{
			return it;
		}
	}
	return end().point;
}

template<typename T, typename alloctype>
template<typename execute>
typename Vector<T, alloctype>::riterator
	Vector<T, alloctype>::rfind_if(T value, execute obj)
{
	for (riterator it = __rbegin(); it != __rend(); it++)
	{
		if (obj(value))
		{
			return it;
		}
	}
	return __rend();
}

//obj ����Ҫ�����ֵ value��finҪ���ڵ�ֵ
template<typename T, typename alloctype>
int Vector<T, alloctype>::reload(int obj, int value)
{
	while (obj <= value)
	{
		obj = obj * 2;
	}
	return obj;
}

//����mem�ķ���

//void * refill(int size);

template<typename T, typename alloctype>
void*  Vector<T, alloctype>::refill(int size)
{
	//��alloc�л�ȡ�µ��ڴ�
	int size_ = size * sizeof(T);
	void *temp_ = m_alloc.alloc(size_);
	if (temp_ == nullptr)
	{
		return temp_;
	}
	T *tmv = (T*)(temp_);
	//Ԫ�صĿ���
	memcpy(tmv, m_arry, this->m_size * sizeof(T));
	//�������Ԫ��
	m_alloc.delloc(m_arry, m_max_size * sizeof(T));
	//Ԫ�ص�ת��
	m_arry = tmv;
	m_max_size = size;
	return m_arry;
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::move_n_front
	(Vector::iterator it_begin, Vector::iterator it_end, int n)
{
	if (n == 0)
		return;
	iterator cur = it_begin - n;
	for (it_begin; it_begin != it_end; it_begin++)
	{
		*cur = *it_begin;
		cur++;
	}
}


template<typename T, typename alloctype>
typename Vector<T, alloctype>::iterator
	Vector<T, alloctype>::__begin()
{
	return m_arry;
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::iterator
	Vector<T, alloctype>::__end()
{
	return m_arry + m_size;
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::riterator
	Vector<T, alloctype>::__rbegin()
{
	return (__end().point - 1);
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::riterator 
	Vector<T, alloctype>::__rend()
{
	return __end().point;
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::riterator
	Vector<T, alloctype>::r__rend()
{
	return (__begin().point - 1);
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::iterator
	Vector<T, alloctype>::__advance(Vector::iterator it, int n)
{
	_advance(it, n, Vector<T>::iterator);
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::__push_back(const T value)
{
	if (m_size >= (m_max_size - 1))
	{
		refill(m_max_size * 2);
	}
	m_arry[m_size] = value;
	m_size++;
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::__push_font(const T value)
{
	if (m_size >= (m_max_size))
	{
		refill(m_max_size * 2);
	}
	move_n_back(begin(), end(), 1);
	m_arry[0] = value;
	m_size++;

}

template<typename T, typename alloctype>
void Vector<T, alloctype>::clean_mem()
{
	if (m_arry)
	{
		//(arry,max_size*sizeof(T))
		m_alloc.delloc(m_arry, m_max_size * sizeof(T));
		m_max_size = 0;
		m_size = 0;
		m_arry = nullptr;
	}
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::move_n_back
			(Vector::iterator it_begin, Vector::iterator it_end, int n)
{
	if (n == 0)
		return;
	iterator cur_back = it_end + n -1;
	iterator pre_back = it_end - 1;
	//ȷ���߼��ϵ�back��
	int len = it_end - it_begin;
	for (int i = 0; i < len; i++)
	{
		(*cur_back) = (*pre_back);
		cur_back--;
		pre_back--;
	}
}

template<typename T, typename alloctype>
void Vector<T, alloctype>::move_one_back
	(Vector::iterator it_begin, Vector::iterator it_end)
{

	iterator cur_back = it_end;
	iterator cur_front = it_end - 1;

	while (true)
	{
		if (cur_front == it_begin)
		{
			(*cur_back) = (*cur_front);
			break;
		}
		(*cur_back) = (*cur_front);
		--cur_front;
		--cur_back;
	}
}

template<typename T, typename alloctype>
typename Vector<T, alloctype>::iterator
	Vector<T, alloctype>::_insert_aux(Vector::iterator it, int value)
{
	move_n_back(it, end(), 1);
	*it = value;
	m_size++;
	return it;
}