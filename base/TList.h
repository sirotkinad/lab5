#ifndef TLIST_H
#define TLIST_H
template<typename T>
struct Node
{
	T data;
	Node* prev, * next; //��������� �� ���������� � ��������� ������
};

template<typename T> //������ ����������� ������
class TList
{
	Node<T>* head, * tail; //������ � ��������� ��������

public:
	// �����������
	TList()
	{
		head = tail = nullptr;
	}

	//����������� �����������
	TList(const TList& L)
	{
		head = tail = nullptr;
		Node<T>* tmp = L.getHead();
		while (tmp != nullptr)
		{
			add_end(tmp->data);
			tmp = tmp->next;
		}
	}

	// ��������� ������� ��������
	Node<T>* getHead()
	{
		return head;
	}

	// ��������� ���������� ��������
	Node<T>* getTail()
	{
		return tail;
	}

	//��������� ������� �� ���������
	bool operator==(const TList& L)
	{
		Node<T>* tmp1, tmp2;
		tmp1 = head;
		tmp2 = L.head;
		while (tmp1 != nullptr)
		{
			if (tmp1->data != tmp2->data)
				return false;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		return true;
	}

	//�������� ������������
	TList& operator=(const TList& L)
	{
		if (*this == L)
			return (*this);
		this->clear();
		Node<T>* tmp = L.head;
		while (tmp != nullptr)
		{
			add_end(tmp->data);
			tmp = tmp->next;
		}
		return (*this);
	}
	
	// ���������� �������� � ����� ������
	void add_end(const T& elem)
	{
		Node<T>* tmp = new Node<T>;
		tmp->next = nullptr;
		tmp->data = elem;

		if (head != nullptr)
		{
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
		}
		else
		{
			tmp->prev = nullptr;
			head = tail = tmp;
		}
	}
	//�������� ������
	void clear()
	{
		head = tail = nullptr;
	}

	// ���������� ������
	void list_sort()
	{
		Node<T>* p = head;
		if (p != nullptr)
			while (p->next != nullptr)
			{
				Node<T>* q = p->next;
				while (q != nullptr)
				{
					if (p->data < q->data)
					{
						T tmp = p->data;
						p->data = q->data;
						q->data = tmp;
					}
					q = q->next;
				}
				p = p->next;
			}
	}
};

#endif
