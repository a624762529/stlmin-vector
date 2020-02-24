//#include<iostream>
//#include<vector>
//#include"mem_pool.h"
//using namespace std;
//
////测试链表
//int main011()
//{
//	cout << sizeof(LinkNode) << endl;
//	Link testLink;
//	for (int i = 0; i < 50; i++)
//	{
//		testLink.insertNode(new LinkNode());
//	}
//	return 1;
//}
//
//
//int main02130()
//{
//	//测试其构造和析构
//	MemPool pool;
//	
//	{
//		for (int i = 0; i < 16; i++)
//		{
//			int size = (i + 1) * 8;
//			char *p = reinterpret_cast<char*>(pool.alloc(size));
//			//pool.delloc(p, size);
//		}
//
//		//测试申请功能
//		char *p = reinterpret_cast<char*>(pool.alloc(-1));
//		pool.delloc(p, -1);
//		p = reinterpret_cast<char*>(pool.alloc(16 * 8 + 1));
//		pool.delloc(p, 16 * 8 + 1);
//		p = reinterpret_cast<char*>(pool.alloc(16 * 8 + 100));
//		pool.delloc(p, 16 * 8 + 100);
//	}
//
//	vector<int> vec;
//
//	system("pause");
//	return 1;
//}