#ifndef _DOUBLYSORTEDLINKED_LIST_H
#define _DOUBLYSORTEDLINKED_LIST_H

#include "PlayList.h"
#include "DoublyIterator.h"

//#define min MusicType(INT_MIN)
//#define max MusicType(INT_MAX)


template<typename T>
class DoublyIterator;

/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< �� ����� ������.
	DoublyNodeType* prev;   ///< ���� ����� ������
	DoublyNodeType* next;	///< ���� ����� ������
};


/**
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;  ///< DoublyIterator�� ģ�� Ŭ����.
public:
	/**
	*	����Ʈ ������.
	*/
	DoublySortedLinkedList();

	/**
	*	�Ҹ���.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	���� á���� �ƴ����� �˷��ش�.
	*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T &item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*/
	void Delete(T &item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	void Replace(T &item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	T* Get(T& item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	T* GetPoint(T& item);

	DoublySortedLinkedList<T>& operator= (const DoublySortedLinkedList<T> &obj)
	{
		int length = obj.GetLength();
		DoublyIterator<T> itor(obj);

		for (int i = 0; i < length; i++)
			Add(itor.GetNextNode()->data);

		return *this;
	}
private:
	DoublyNodeType<T>* m_pFirst;	///< Pointer for pointing a first node.
	DoublyNodeType<T>* m_pLast;
	int m_nLength;	///< Number of node in the list.
};

// ����Ʈ�� �� ó���� ���� ���θ� ����Ű�� �����ϰ� ����Ʈ�� ���̸� 0���� �ʱ�ȭ���ѳ��´�.
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->next = m_pLast; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.
	m_pFirst->prev = NULL; // ó��.

	m_pLast->next = NULL; // ��.
	m_pLast->prev = m_pFirst; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.

	m_nLength = 0; // ���̴� 0.
}


// Class destructor
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	delete m_pFirst;
	delete m_pLast;
}


// ����Ʈ�� ������� �˻��Ѵ�.
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty()
{
	if (m_nLength == 0)
		return true;
	else
		return false;
}

// ����Ʈ�� �� ���ִ��� �˻��Ѵ�.
template <typename T>
bool DoublySortedLinkedList<T>::IsFull()
{
	if(m_nLength == 10)
		return true;
	else
		return false;
}

// ����Ʈ�� ����.
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	DoublyNodeType<T> *pItem;
	DoublyIterator<T> itor(*this);

	itor.GetNextNode();
	while (itor.NextNotNull())
	{
		pItem = itor.m_pCurPointer;
		itor.GetNextNode(); // ���� �����͸� �������� �̵�.
		delete pItem;
	}

	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;

	return;
}


// Get number of elements in the list.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

// Add music into this list.
template <typename T>
int DoublySortedLinkedList<T>::Add(T &item)
{
	DoublyIterator<T> itor(*this);
	DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
	itor.GetNextNode(); // �������� �̵�.

	if (IsEmpty()) // ó�� ������ ��
	{
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}

	while (1)
	{
		if (item < itor.m_pCurPointer->data) // �´� �ڸ��� ã�´�.
		{
			pItem->data = item;
			pItem->prev = itor.m_pCurPointer->prev;
			pItem->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev->next = pItem;
			itor.m_pCurPointer->prev = pItem; // �������� ����.
			m_nLength++;
			return 1;
		}
		else if (itor.m_pCurPointer->next == NULL)
		{
			pItem->data = item;
			pItem->prev = itor.m_pCurPointer->prev;
			pItem->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev->next = pItem;
			itor.m_pCurPointer->prev = pItem;
			//pItem->next = NULL;
			//itor.m_pCurPointer->next = pItem;
			//m_pLast = pItem;
			m_nLength++;
			return 1;
		}
		else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
			return 0; // 0�� ��ȯ.
		else
			itor.GetNextNode(); // �������� �̵�.
	}
}


//���ϴ� ��ġ�� �ڷḦ �����ϴ� �޼ҵ�, ���� �ڷ�� 0�� ����Ѵ�.
template <typename T>
void DoublySortedLinkedList<T>::Delete(T& item)
{
	DoublyIterator<T> itor(*this);
	itor.GetNextNode(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item) // ��ġ�ϴ� �����͸� ã�´�.
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			pItem->prev->next = itor.GetNextNode();// itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // �����ϴ� ����� �հ� �ڸ� ���� �̾��ش�.
			delete pItem; // ����.
			return;
		}
		else
			itor.GetNextNode();
	}
	m_nLength--; // ���� ����.
	return;
}

//�ش��ϴ� ��带 �������ְ� ���� ��� 0�� ���
template <typename T>
void DoublySortedLinkedList<T>::Replace(T& item)
{
	DoublyIterator<T> itor(*this);
	itor.GetNextNode(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; // ������ ��ü.
			return;
		}
		else
			itor.GetNextNode();
	}

	return;
}

// �Է¹��� �����۰� ��ġ�ϴ� �������� ����Ʈ���� ã�� �����´�.
template <typename T>
T* DoublySortedLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> itor(*this);
	itor.GetNextNode();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			//item = itor.m_pCurPointer->data;
			return &itor.m_pCurPointer->data; // ��ġ�ϸ� 1�� ��ȯ.
		}
		else
			itor.GetNextNode(); // �������� �̵�.
	}

	return NULL; // ��ġ���� ������ 0�� ��ȯ.
}

// �Է¹��� �����۰� ��ġ�ϴ� �������� �ּҸ� ����Ʈ���� ã�� �����´�.
template <typename T>
T* DoublySortedLinkedList<T>::GetPoint(T &item)
{
	DoublyIterator<T> itor(*this);
	itor.GetNextNode();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return &itor.m_pCurPointer->data; // ��ġ�ϸ� 1�� ��ȯ.
		}
		else
			itor.GetNextNode(); // �������� �̵�.
	}

	return 0; // ��ġ���� ������ 0�� ��ȯ.
}

#endif //_DOUBLYSORTEDLINKEDLIST_H
