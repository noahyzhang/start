#pragma once
#include<iostream>
#include<vector>
#include<cassert>

class ListNode {
public:
	int val;
	ListNode* next;
};


class LinkList{
private:
	ListNode* root;

	void Destory(ListNode* root);
	void print_end_front(ListNode* node);
	void QuickSort(ListNode* left,ListNode* right);
	void SwapNode(ListNode* left, ListNode* right);
public:
	LinkList(std::vector<int> vec);
	~LinkList();

	void PrintEndToFront();   //从尾到头打印单链表
	void DeleteNode(ListNode* node);  //删除一个无头单链表的非尾节点（不能遍历链表）
	void InsertNode(ListNode* node,int num);  //在无头单链表的一个节点前插入一个节点（不能遍历链表）
	void JoseCir();           //单链表实现约瑟夫环(JosephCircle)
	void Reversal();          //逆置 / 反转单链表
	void Sort();              //单链表排序（冒泡排序&快速排序）
	void Merge(ListNode* other_list);             //合并两个有序链表, 合并后依然有序
	ListNode* FindBinNode();	      //查找单链表的中间节点，要求只能遍历一次链表
	ListNode* FindLastKNode(int k);      //查找单链表的倒数第k个节点，要求只能遍历一次链表
	void DeleteLastKNode(int k);         //删除链表的倒数第K个结点
	bool CheckCircle();//判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算
	int CheckListInter();//判断两个链表是否相交，若相交，求交点。（假设链表不带环）
	int CheckListInterCircle();//判断两个链表是否相交，若相交，求交点。（假设链表可能带环）
	//复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，
	//还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，返回复制后的新链表。
	LinkList* CopyList();
	void UnionSet();//求两个已排序单链表中相同的数据。
};

