#pragma once
#include<iostream>
#include"vector.h"
#include"mem_pool.h"
#include <numeric>
#include<vector>
#include<string>
#include <chrono>
using namespace std;
class user_tag {};
class os_tag {};
//����vector������10000������
//ɾ��ż���ڵ�
//�ں���׷��5000���ڵ�
//���������
void printf(Vector<int> &vec)
{
	for (Vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template<typename T >
void do_process_(T &vec_1, user_tag tag )
{
 
	clock_t time = clock();
	for (int a = 0; a < 10000; a++)
	{
		vec_1.push_back(a);
	}
 
	for (Vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
	{
		if (it + 1 == vec_1.end())
		{
			break;
		}
		it = vec_1.erase(it);
	}

	for (int a = 0; a < 5000; a++)
	{
		vec_1.push_back(a);
	}
	//���
	/*for (Vector<int>::reverse_iterator it = vec_1.r_begin(); it != vec_1.r_end(); it++)
	{
		cout << *it << " ";
	}*/
	int a = 0; 
	cout << "ǰʮ����" << endl;
	for (Vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
	{
		if (a == 10)
			break;
		a++;
		cout << *it << " ";
	}
	cout << endl << "��ʮ����" << endl;
	a = 0;
	for (Vector<int>::iterator it = vec_1.r_begin(); it != vec_1.r_end(); it++)
	{
		if (a == 10)
			break;
		a++;
		cout << *it << " ";
	}
	cout << endl;


	cout << endl;
	clock_t time_ = clock();

	cout << "������ʱ��Ϊ/����" << time_ - time << endl;
}
vector<int >vec;

template<typename T >
void do_process_(T &vec_1, os_tag tag)
{
	 
	clock_t time = clock();
	for (int a = 0; a < 10000; a++)
	{
		
		vec_1.insert(vec_1.begin(), a);
	}
	for (vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
	{
		if (it + 1 == vec_1.end())
		{
			break;
		}
		
		it = vec_1.erase(it);
	}
	
	for (int a = 0; a < 5000; a++)
	{
		vec_1.push_back(a);
	}
	 
	int a = 0;
	cout << "ǰʮ����" << endl;
	for (vector<int>::iterator it = vec_1.begin(); it != vec_1.end(); it++)
	{
		if (a == 10)
			break;
		a++;
		cout << *it << " ";
	}
	a = 0;
	cout <<endl<< "��ʮ����" << endl;
	for (vector<int>::reverse_iterator it = vec_1.rbegin(); it != vec_1.rend(); it++)
	{
		if (a == 10)
			break;
		a++;
		cout << *it << " ";
	}
	cout << endl;
	clock_t time_ = clock();

	cout << "������ʱ��Ϊ/����" << time_ - time << endl;
}

template<typename T, typename tag_type>
void do_process(T &vec_1, tag_type tag, string st)
{
	cout << st << endl;
	do_process_(vec_1, tag);
}
