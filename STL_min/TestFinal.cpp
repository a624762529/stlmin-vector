#pragma once
#include<iostream>
#include"vector.h"
#include"mem_pool.h"
#include <numeric>
#include<string>
#include <chrono>
#include<vector>
#include"TestVector.cpp"
using namespace std;
void TestVector(Vector<int> &myvec)
{
	int tvn = clock();
	for (int i = 0; i < 10000; i++)
	{
		myvec.push_back(i);
	}
	cout << "push access time" << clock() - tvn << endl;
	//ÒÆ³ýµôÅ¼Êý²¿·Ö
	auto rx = myvec.begin();
	int tv1 = clock();
	for (int i = 0; i < 5000; i++)
	{
		rx=myvec.erase(rx);
		rx++;
	}
	cout << "remove access time" << clock() - tv1 << endl;
}
void Testvector(vector<int> &myvec)
{
	int tvn = clock();
	for (int i = 0; i < 10000; i++)
	{
		myvec.push_back(i);
	}
	cout << "push access time" << clock() - tvn << endl;
	//ÒÆ³ýµôÅ¼Êý²¿·Ö
	auto rx = myvec.begin();
	int tv1 = clock();
	for (int i = 0; i < 5000; i++)
	{
		rx = myvec.erase(rx);
		rx += 1;
	}
	cout << "remove access time" << clock() - tv1 << endl;
}
void TravalVec(Vector<int> &vec,string test)
{
	int tv1 = clock();
	int i = 0;
	cout << endl << test;
	//µü´úÆ÷Ë³Ðò±éÀú
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		if (i % 10 == 0)
		{
			//cout << endl;
		}
		//cout << *it << " ";
		i++;
	}
	cout << endl;
	cout << "traval access" << clock() - tv1 << endl;
}

void Travalvec(vector<int> &vec, string test)
{
	int tv1 = clock();
	int i = 0;
	cout << endl << test;
	//µü´úÆ÷Ë³Ðò±éÀú
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		if (i % 10 == 0)
		{
			//cout << endl;
		}
		//cout << *it << " ";
		i++;
	}
	cout << endl;
	cout << "traval access" << clock() - tv1 << endl;
}
int main()
{
	cout << "user vector" << endl;
	Vector<int > vec_2;	
	TestVector(vec_2);
	TravalVec(vec_2, "doit after");

	cout << "os vector" << endl;
	vector<int> vec;
	Testvector(vec);
	Travalvec(vec, "doit after");
	system("pause");
	return 1;
}
