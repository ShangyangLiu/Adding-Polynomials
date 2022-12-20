#include <iostream>
using namespace std;

struct DATA
{
	int xidata;
	int zhidata;
};

struct NODE
{
	DATA data;
	NODE* next;
};


NODE* creat_link()
{
	//创建数组
	int xidata, zhidata;
	int xiarr[100];
	int zhiarr[100];
	int n = 0;
	while (1)
	{
		cout << "请输入系数" << endl;
		cin >> xidata;
		cout << "请输入指数" << endl;
		cin >> zhidata;
		if (xidata == 0 && zhidata == 0)
		{
			break;
		}
		xiarr[n] = xidata;
		zhiarr[n] = zhidata;
		n++;
	}

	//创建链表
	NODE* head, * p, * node;
	head = new(NODE);
	head->next = NULL;
	for (int i = 0; i < n; i++)
	{
		p = head;
		if (xiarr[i] == 0)
		{
			continue;
		}
		node = new(NODE);
		node->data.xidata = xiarr[i];
		node->data.zhidata = zhiarr[i];
		while (p->next != NULL && p->next->data.zhidata > node->data.zhidata)
		{
			p = p->next;
		}
		if (p->next != NULL && p->next->data.zhidata == node->data.zhidata)
		{
			delete node;
			p->next->data.xidata += xiarr[i];
		}
		else
		{
			node->next = p->next;
			p->next = node;
		}
	}
	return head;
}


void display(NODE* head)
{
	NODE* p;
	p = head->next;
	while (p != NULL)
	{
		if (p == head->next)
		{

			if (p->data.xidata == 1)
			{
				if (p->data.zhidata == 0)
				{
					cout << p->data.xidata;
				}
				else if (p->data.zhidata == 1)
				{
					cout << "x";
				}
				else
				{
					cout << "x^" << p->data.zhidata;
				}
			}
			else if (p->data.xidata == -1)
			{
				if (p->data.zhidata == 0)
				{
					cout << p->data.xidata;
				}
				else if (p->data.zhidata == 1)
				{
					cout << "-x";
				}
				else
				{
					cout << "-x^" << p->data.zhidata;
				}
			}
			else
			{
				if (p->data.zhidata == 1)
				{
					cout << p->data.xidata << "x";
				}
				else if (p->data.zhidata == 0)
				{
					cout << p->data.xidata;
				}
				else
				{
					cout << p->data.xidata << "x^" << p->data.zhidata;
				}
			}
		}
		else
		{
			if (p->data.xidata > 0 && p->data.xidata != 1)
			{
				if (p->data.zhidata == 0)
				{
					cout << "+" << p->data.xidata;
				}
				else if (p->data.zhidata == 1)
				{
					cout << "+" << p->data.xidata << "x";
				}
				else
				{
					cout << "+" << p->data.xidata << "x^" << p->data.zhidata;
				}
			}
			else if (p->data.xidata < 0 && p->data.xidata != -1)
			{
				if (p->data.zhidata == 0)
				{
					cout << p->data.xidata;
				}
				else if (p->data.zhidata == 1)
				{
					cout << p->data.xidata << "x";
				}
				else
				{
					cout << p->data.xidata << "x^" << p->data.zhidata;
				}
			}
			else if (p->data.xidata == 1)
			{
				if (p->data.zhidata == 0)
				{
					cout << "+" << p->data.xidata;
				}
				else if (p->data.zhidata == 1)
				{
					cout << "+x";
				}
				else
				{
					cout << "+x^" << p->data.zhidata;
				}
			}
			else if (p->data.xidata == -1)
			{
				if (p->data.zhidata == 0)
				{
					cout << p->data.xidata;
				}
				else if (p->data.zhidata == 1)
				{
					cout << "-x";
				}
				else
				{
					cout << "-x^" << p->data.zhidata;
				}
			}
		}
		p = p->next;
	}
}

NODE* add(NODE* head01, NODE* head02)
{
	NODE* p, * q, * head, * q_front, * p_front;
	p = head01;
	q = head02;
	q_front = head02->next;
	p_front = head01->next;
	head = head01;
	while (p->next != NULL && q->next != NULL)
	{
		if (p->next->data.zhidata > q->next->data.zhidata)
		{
			p = p->next;
			p_front = p_front->next;
		}
		else if (p->next->data.zhidata == q->next->data.zhidata)
		{
			p->next->data.xidata += q->next->data.xidata;
			if (p->next->data.xidata == 0)
			{
				p->next = p_front->next;
				delete p_front;
				p_front = p->next;
				q = q->next;
				q_front = q_front->next;
			}
			else
			{
				p = p->next;
				q = q->next;
				q_front = q_front->next;
				p_front = p_front->next;
			}
		}
		else
		{
			if (q_front->next == NULL)
			{
				q_front->next = p->next;
				p->next = q_front;
			}
			q->next = q_front->next;
			q_front->next = p->next;
			p->next = q_front;
			p = p->next;
			p_front = p_front->next;
			q_front = q->next;

		}
	}
	q = head02;
	p = head02->next;
	while (p != NULL)
	{
		q->next = p->next;
		delete p;
		p = q->next;
	}
	delete q;
	return head;
}

int main()
{
	cout << "创建第一个多项式：" << endl;
	NODE* linkhead01 = creat_link();
	cout << "创建第二个多项式：" << endl;
	NODE* linkhead02 = creat_link();
	cout << "第一个多项式：" << endl;
	display(linkhead01);
	cout << endl;
	cout << "第二个多项式：" << endl;
	display(linkhead02);
	cout << endl;
	//多项式相加
	NODE* linkhead = add(linkhead01, linkhead02);
	cout << endl;
	cout << "多项式相加得：" << endl;
	display(linkhead);
	cout << endl;
	system("pause");
	return 0;
}