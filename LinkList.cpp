#include "LinkList.hpp"

LinkList::LinkList(std::vector<int> vec)
{
	int len = vec.size();
	this->root = new ListNode;
	ListNode* temp = this->root;

	for (int i = 1; i < len; ++i)
	{
		ListNode* node = new ListNode;
		node->val = vec[i];
		node->next = nullptr;
		temp->next = node;
		temp = temp->next;
	}
}

void LinkList::Destory(ListNode* root)
{
	if (root != nullptr)
		Destory(root->next);
	delete root;
	root = nullptr;
}

LinkList::~LinkList()
{
	this->Destory(this->root);
}

void LinkList::print_end_front(ListNode* node)
{
	if (node->next != nullptr)
		print_end_front(node->next);
	std::cout << node->val << " ";
}

void LinkList::PrintEndToFront()   //从尾到头打印单链表
{
	this->print_end_front(this->root);
}

void LinkList::DeleteNode(ListNode* node)  //删除一个无头单链表的非尾节点（不能遍历链表）
{
	if (node->next == nullptr) //如果节点是尾节点
	{
		delete node;
		node = nullptr;
	}
	int temp = node->val;
	node->val = node->next->val;
	node->next->val = temp;

	ListNode* t_node = node->next->next;
	delete node->next;
	node->next = t_node;
}

void LinkList::InsertNode(ListNode* node,int num)  //在无头单链表的一个节点前插入一个节点（不能遍历链表）
{
	ListNode* new_node = new ListNode;
	new_node->val = num;

	new_node->next = node->next;
	node->next = new_node;
}

void LinkList::JoseCir()           //单链表实现约瑟夫环(JosephCircle)
{
	ListNode* temp = this->root;
	while (temp->next != nullptr)
		temp = temp->next;
	temp->next = this->root;
}


void LinkList::Reversal()          //逆置/反转单链表
{
	assert(this->root == nullptr);
	ListNode* sec = root;
	ListNode* thi = nullptr;
	if (sec->next != nullptr)
		thi = sec->next;

	while (sec != nullptr)
	{
		sec->next = thi;
		thi->next = root;
		root = thi;
		thi = sec->next;
	}
}

void LinkList::SwapNode(ListNode* left, ListNode* right)
{
	int tmp = left->val;
	left->val = right->val;
	right->val = tmp;
}

void LinkList::QuickSort(ListNode* left,ListNode* right)  //没有处理相等的情况
{
	ListNode* index = left;
	ListNode* index_front = index;
	ListNode* next_node = index->next;
	while (next_node != nullptr)
	{
		if (next_node->val < index->val)
		{
			index_front = index;
			index = index->next;
			SwapNode(index, next_node);
		}
		next_node = next_node->next;
	}
	SwapNode(left, index);
	QuickSort(left, index_front);
	QuickSort(index->next, right);
}

void LinkList::Sort()              //单链表排序（冒泡排序&快速排序）
{
	ListNode* temp = root;
	while (temp->next != nullptr)
		temp = temp->next;
	QuickSort(root,temp);
}


void LinkList::Merge(ListNode* other_list)             //合并两个有序链表, 合并后依然有序
{
	assert(root == nullptr);
	assert(other_list == nullptr);
	ListNode* first_list = nullptr;
	ListNode* second_list = nullptr;
	ListNode* first_list_front = nullptr;
	if (root->val > other_list->val)
	{
		first_list = other_list;
		second_list = root;
	}
	else
	{
		first_list = root;
		second_list = other_list;
	}
	root = first_list;
	while (first_list != nullptr && second_list != nullptr)
	{
		first_list_front = first_list;
		if (first_list->val >= second_list->val)
		{
			ListNode* tmp = second_list;
			second_list = second_list->next;
			tmp->next = first_list->next;
			first_list->next = tmp;
			SwapNode(first_list, tmp);
		}
		first_list = first_list->next;
	}
	if (first_list == nullptr)
		first_list_front->next = second_list;
}

ListNode* LinkList::FindBinNode()	      //查找单链表的中间节点，要求只能遍历一次链表
{
	assert(root);
	ListNode* quick = root;
	ListNode* slow = root;
	while (quick != nullptr && quick->next != nullptr)
	{
		quick = quick->next->next;
		slow = slow->next;
	}
	return slow;
}


ListNode* LinkList::FindLastKNode(int k)        //查找单链表的倒数第k个节点，要求只能遍历一次链表
{
	assert(root == nullptr);
	ListNode* quick = root;
	ListNode* slow = root;
	while (quick != nullptr)
	{
		while (k--)
			quick = quick->next;
		quick = quick->next;
		slow = slow->next;
	}
	return slow;
}


void LinkList::DeleteLastKNode(int k)    //删除链表的倒数第K个结点
{
	assert(root);
	ListNode* delete_node = nullptr;
	delete_node = FindLastKNode(k);
	DeleteNode(delete_node);
}


bool LinkList::CheckCircle()       //判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算
{
	ListNode* quick = root;
	ListNode* slow = root;
	while(quick != nullptr && quick->next != nullptr && quick)


}


//T CheckListInter();//判断两个链表是否相交，若相交，求交点。（假设链表不带环）
//T CheckListInterCircle();//判断两个链表是否相交，若相交，求交点。（假设链表可能带环）
////复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，
////还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，返回复制后的新链表。
//LinkList* CopyList();
//void UnionSet();//求两个已排序单链表中相同的数据。