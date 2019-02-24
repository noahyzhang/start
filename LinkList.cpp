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

void LinkList::PrintEndToFront()   //��β��ͷ��ӡ������
{
	this->print_end_front(this->root);
}

void LinkList::DeleteNode(ListNode* node)  //ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
{
	if (node->next == nullptr) //����ڵ���β�ڵ�
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

void LinkList::InsertNode(ListNode* node,int num)  //����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
{
	ListNode* new_node = new ListNode;
	new_node->val = num;

	new_node->next = node->next;
	node->next = new_node;
}

void LinkList::JoseCir()           //������ʵ��Լɪ��(JosephCircle)
{
	ListNode* temp = this->root;
	while (temp->next != nullptr)
		temp = temp->next;
	temp->next = this->root;
}


void LinkList::Reversal()          //����/��ת������
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

void LinkList::QuickSort(ListNode* left,ListNode* right)  //û�д�����ȵ����
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

void LinkList::Sort()              //����������ð������&��������
{
	ListNode* temp = root;
	while (temp->next != nullptr)
		temp = temp->next;
	QuickSort(root,temp);
}


void LinkList::Merge(ListNode* other_list)             //�ϲ�������������, �ϲ�����Ȼ����
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

ListNode* LinkList::FindBinNode()	      //���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
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


ListNode* LinkList::FindLastKNode(int k)        //���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
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


void LinkList::DeleteLastKNode(int k)    //ɾ������ĵ�����K�����
{
	assert(root);
	ListNode* delete_node = nullptr;
	delete_node = FindLastKNode(k);
	DeleteNode(delete_node);
}


bool LinkList::CheckCircle()       //�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������
{
	ListNode* quick = root;
	ListNode* slow = root;
	while(quick != nullptr && quick->next != nullptr && quick)


}


//T CheckListInter();//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
//T CheckListInterCircle();//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ�����
////��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬
////����һ��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ��������
//LinkList* CopyList();
//void UnionSet();//��������������������ͬ�����ݡ�