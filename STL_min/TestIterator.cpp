//#include"Iterator.h"
//#include"R_Iterator.h"
//#include<iostream>
//using namespace std;
//int main0012301()
//{
//	auto myArry = "123456789";
//	{
//		//测试迭代器的顺序打印
//		Iterator<char> iter(const_cast<char*>(myArry));
//		for (int i = 0; i < strlen(myArry); i++)
//		{
//			cout << *iter << "  ";
//			iter++;
//		}
//		cout << endl;
//
//		//访问迭代器对应的第6个元素
//		Iterator<char> iterv(const_cast<char*>(myArry));
//		cout<<"测试迭代器对应的第五个元素" << *(iterv+5) << endl;
//
//
//		//测试迭代器的逆向打印
//		Iterator<char> iter1(const_cast<char*>(myArry + strlen(myArry) - 1));
//		for (int i = 0; i < strlen(myArry); i++)
//		{
//			cout << *iter1 << "  ";
//			iter1--;
//		}
//		cout << endl;
//	}
//
//	cout << endl;
//	{
//		//测试逆向迭代器的遍历
//		r_iterator<char> r_iter(const_cast<char*>(myArry + strlen(myArry) - 1));
//		for (int i = 0; i < strlen(myArry); i++)
//		{
//			cout << *r_iter << "  ";
//			r_iter++;
//		}
//		cout << endl;
//
//		r_iterator<char> r_iterv(const_cast<char*>(myArry + strlen(myArry) - 1));
//		cout << "测试逆向迭代器对应的倒数第三个元素"<<*(r_iterv+3) << endl;
//
//
//		r_iterator<char> r_iter1(const_cast<char*>(myArry));
//		for (int i = 0; i < strlen(myArry); i++)
//		{
//			cout << *r_iter1 << "  ";
//			r_iter1--;
//		}
//	}
//	cout << endl;
//	system("pause");
//	return 1;
//}
//
//
//int main0002()
//{
//	//测试迭代器的构造函数和析构函数 以及拷贝构造函数
//	auto myArry = "123456789";
//	{
//		//测试迭代器的顺序打印
//		Iterator<char> iter(const_cast<char*>(myArry));
//		Iterator<char> iterv = iter;
//		iter = iterv;
//	}
//
//	{
//		r_iterator<char> iter(const_cast<char*>(myArry));
//		r_iterator<char> iterv = iter;
//		iterv = iter;
//	}
//
//	system("pause");
//	return 1;
//}