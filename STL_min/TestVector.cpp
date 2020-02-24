//#include"vector.h"
//#include<iostream>
//#include<string>
//using namespace std;
//
//void TravalVec(Vector<int> &vec,string test)
//{
//	int i = 0;
//	cout << endl << test;
//	//迭代器顺序遍历
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
//	//测试逆向遍历
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
//	//测试下标操作符访问
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
//	//测试普通初始化
//	Vector<int> vec;
//	TravalVec(vec, "vec empty:");
//	Vector<int> vec1(50);
//
//	//验证是否插入了50个节点
//	//FillVec(vec1, 50);
//	FillVecUp(vec1, 0);
//	{
//		//测试find函数
//		auto i = vec1.find(20);
//		cout<<"test find" << *i << endl;
//	}
//	TravalVec(vec1, "填充了 50个50 的buf");
//
//	Vector<int> val2(30, 20);
//	//输出初始化的结果
//	TravalVec(val2, "30个 20");
//	
//	//测试拷贝构造初始化
//	Vector<int> val3(val2);
//	TravalVec(val3, "拷贝构造上一个");
//	//测试赋值操作
//	auto i = val3;
//	TravalVec(i, "测试赋值操作符");
//
//	//测试迭代器初始化 
//	Vector<int> val4(val2.begin(), val2.begin()+5);
//	TravalVec(val4, "5个 20");
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
//	TravalVec(vec1, "vec1 前10的数据");
//
//	cout<<"find 第20个元素" << *vec1.rfind(20) << endl;
//	
//	system("pause");
//	return 1;
//}