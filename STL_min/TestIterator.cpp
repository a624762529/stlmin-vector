//#include"Iterator.h"
//#include"R_Iterator.h"
//#include<iostream>
//using namespace std;
//int main0012301()
//{
//	auto myArry = "123456789";
//	{
//		//���Ե�������˳���ӡ
//		Iterator<char> iter(const_cast<char*>(myArry));
//		for (int i = 0; i < strlen(myArry); i++)
//		{
//			cout << *iter << "  ";
//			iter++;
//		}
//		cout << endl;
//
//		//���ʵ�������Ӧ�ĵ�6��Ԫ��
//		Iterator<char> iterv(const_cast<char*>(myArry));
//		cout<<"���Ե�������Ӧ�ĵ����Ԫ��" << *(iterv+5) << endl;
//
//
//		//���Ե������������ӡ
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
//		//��������������ı���
//		r_iterator<char> r_iter(const_cast<char*>(myArry + strlen(myArry) - 1));
//		for (int i = 0; i < strlen(myArry); i++)
//		{
//			cout << *r_iter << "  ";
//			r_iter++;
//		}
//		cout << endl;
//
//		r_iterator<char> r_iterv(const_cast<char*>(myArry + strlen(myArry) - 1));
//		cout << "���������������Ӧ�ĵ���������Ԫ��"<<*(r_iterv+3) << endl;
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
//	//���Ե������Ĺ��캯������������ �Լ��������캯��
//	auto myArry = "123456789";
//	{
//		//���Ե�������˳���ӡ
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