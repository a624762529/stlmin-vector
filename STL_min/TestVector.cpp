//#include"vector.h"
//#include<iostream>
//#include<string>
//using namespace std;
//
//void TravalVec(Vector<int> &vec,string test)
//{
//	int i = 0;
//	cout << endl << test;
//	//������˳�����
//	
//		for (auto it = vec.begin(); it != vec.end(); it++)
//		{
//			if (i % 10 == 0)
//			{
//				cout << endl;
//			}
//			cout << *it << " ";
//			i++;
//		}
//		cout << endl;
//	
//	//�����������
//
//	//for (auto it = vec.r_begin(); it != vec.r_end(); it++)
//	//{
//	//	if (i % 10 == 0)
//	//	{
//	//		cout << endl;
//	//	}
//	//	cout << *it << " ";
//	//	i++;
//	//}
//	//cout << endl;
//
//	//�����±����������
//	//	for (int i = 0; i < vec.size_vec(); i++)
//	//	{
//	//		if (i % 10 == 0)
//	//		{
//	//			cout << endl;
//	//		}
//	//		cout << vec[i] << " ";
//	//	}
//	//	cout << endl;
//
//
//}
//
//template<typename T>
//void FillVec(Vector<T> &vec, T val)
//{
//	int fill_size = vec.capacity();
//	for (int i = vec.size_vec(); i < fill_size; i++)
//	{
//		vec.push_back(val);
//	}
//	cout << endl;
//}
//
//
//template<typename T>
//void FillVecUp(Vector<T> &vec, int val)
//{
//	int fill_size = vec.capacity();
//	for (int i = vec.size_vec(); i < fill_size; i++)
//	{
//		vec.push_back(val++);
//	}
//	cout << endl;
//}
//
//
//int main01111()
//{
//	//������ͨ��ʼ��
//	Vector<int> vec;
//	TravalVec(vec, "vec empty:");
//	Vector<int> vec1(50);
//
//	//��֤�Ƿ������50���ڵ�
//	//FillVec(vec1, 50);
//	FillVecUp(vec1, 0);
//	{
//		//����find����
//		auto i = vec1.find(20);
//		cout<<"test find" << *i << endl;
//	}
//	TravalVec(vec1, "����� 50��50 ��buf");
//
//	Vector<int> val2(30, 20);
//	//�����ʼ���Ľ��
//	TravalVec(val2, "30�� 20");
//	
//	//���Կ��������ʼ��
//	Vector<int> val3(val2);
//	TravalVec(val3, "����������һ��");
//	//���Ը�ֵ����
//	auto i = val3;
//	TravalVec(i, "���Ը�ֵ������");
//
//	//���Ե�������ʼ�� 
//	Vector<int> val4(val2.begin(), val2.begin()+5);
//	TravalVec(val4, "5�� 20");
//
//	system("pause");
//	return 1;
//}
//
//
//int main81238()
//{
//	/*	
//	void push_back(const T &value);
//	void push_front(const T &value);
//	void insert(Vector::iterator iter, int value);
//	void insert(Vector::iterator pos, Vector::iterator bg, Vector::iterator ed);
//	void clean();
// 
//	Vector::iterator erase(Vector::iterator begin_, Vector::iterator end_);
//	Vector::iterator erase(Vector::iterator it);
//	void pop_front();
//	Vector::iterator begin();
//	Vector::iterator end();
//	Vector::riterator r_begin();
//	Vector::riterator r_end();
//	riterator r__rend();
//	*/
//	Vector<int> vec;
//	vec.push_back(10);
//	vec.push_back(20);
//	//test push_back
//	for (int i = 0; i < 40; i++)
//	{
//		//push_back success
//		//vec.push_back(i);
//
//		//push_front success
//		//vec.push_front(i);
//
//		//insert
//		vec.insert(vec.begin(), i);
//	}
//	TravalVec(vec, "0-40");
//
//
//	Vector<int> vec1;
//	vec1.push_back(10);
//	vec1.push_back(20);
//	vec1.insert(vec1.begin()+1, vec.begin(), vec.begin() + 10);
//	TravalVec(vec1, "vec1 ǰ10������");
//
//	cout<<"find ��20��Ԫ��" << *vec1.rfind(20) << endl;
//	
//	system("pause");
//	return 1;
//}