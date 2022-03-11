#pragma once


class LinkedList
{
private:
	//结构体，表示节点
	struct Node
	{
		int data;
		Node* last;
		Node* next;
	};
	//链表头
	Node head;
	//指向当前节点的指针
	Node* cur;
public:
	int length;
public:
	//构建一个空链表
	LinkedList();
	//构建一个长度为n的链表，所有节点数据为0
	LinkedList(int n);
	//构建一个长度为n的链表，节点数据为数组dataList[]中的数据
	LinkedList(const int dataList[], int n);
	//复制构造函数
	LinkedList(const LinkedList& lt);
	//赋值构造函数重写，调用对象的指针总是指向链表头
	LinkedList& operator=(const LinkedList& lt);
	//设置当前节点的值
	void Set(int data);
	//返回当前节点值
	int Show() const;
	//移动到下一个节点
	void ToNext();
	//移动到上一个节点
	void ToLast();
	//在当前节点前增加一个节点，新增的节点两端与原节点连接
	void Add();
	void Add(int n);
	//删除当前节点，后一节点连接到前一节点，当前指针指向前一节点
	void Delete();
	//当前指针指向链表头
	void Reset();
	//虚析构函数
	virtual ~LinkedList();
};

