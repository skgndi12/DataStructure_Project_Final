#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	����Ʈ ������.
	*/
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList�� ģ�� Ŭ����.

	/**
	*	@brief	���� �����Ͱ� ����Ű�� ��尡 NULL���� Ȯ���ϴ� �Լ�
	*	@return	���� �����Ͱ� ����Ű�� ��尡 NULL�� �ƴϸ� true,������ true;
	*/
	bool NotNull();

	/**
	*	@brief	���� �������� ������ ����Ű�� �����Ͱ� NULL���� Ȯ���ϴ� �Լ�
	*	@pre	���� �����Ͱ� NULL�̸� �ȵȴ�
	*	@return	���� �������� ������ ����Ű�� �����Ͱ� NULL�� �ƴϸ� true, NULL�̸� false
	*/
	bool NextNotNull();

	bool PrevNotNull();

	/**
	*	@brief	ù node�� item�� �������ִ� �Լ�
	*	@return	list�� ù node�� item�� ����
	*/
	T First();


	bool Next(T& item);

	bool Prev(T& item);

	/**
	*	@brief	���� node�� �̵��ϰ� �������� ������ �ִ� �Լ�
	*	@pre	����
	*	@post	���� �����Ͱ� ���� node�� �̵��ϰ� �� �ּҰ��� ��ȯ����
	*	@return	���� node�� �̵��ϰ� �ش� node�� �ּҰ��� ����
	*/
	T* Next();

	T* Prev();

	T* Current();

	/**
	*	@brief	���� Node�� �ּҰ��� ��ȯ�� �ִ� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	���� Node�� �ּҰ��� ��ȯ.
	*/
	DoublyNodeType<T>* GetNextNode();

	DoublyNodeType<T>* GetPrevNode();

	/**
	*	@brief	���� Node�� ��ȯ�� �ִ� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	���� Node�� ��ȯ.
	*/
	DoublyNodeType<T> GetCurrentNode();

	/**
	*	@brief	iterator�񱳸� ���� ==������ �����ε�
	*	@return	iterator�� ������ true, �ٸ��� false�� ��ȯ
	*/
	bool operator==(DoublyIterator<T>& itor);

private:
	const DoublySortedLinkedList<T> &m_List;  // ����� ����Ʈ�� ���� ����
	DoublyNodeType<T>* m_pCurPointer;		  // iterator�� ����
};


//���� ����� ���� NULL���� �ƴ��� Ȯ���ϴ� �Լ�
template <typename T>
bool DoublyIterator<T> ::NotNull()
{
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

//���� ����� ���� NULL���� �ƴ��� Ȯ���ϴ� �Լ�
template <typename T>
bool DoublyIterator<T> ::NextNotNull()
{
	if (m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}

template <typename T>
bool DoublyIterator<T> ::PrevNotNull()
{
	if (m_pCurPointer->prev == NULL)
		return false;
	else
		return true;
}

//����� ���� ù ��° ���� ����
template <typename T>
T DoublyIterator<T> ::First()
{
	return m_List.m_pFirst->data;
}

//���� ����� �������� ����
template <typename T>
bool DoublyIterator<T> ::Next(T& item)
{
	m_pCurPointer = m_pCurPointer->next;	//�������� �����͸� �̵�
	if (!NextNotNull())
		return false;
	else {
		item = m_pCurPointer->data;
		return true;
	}
}
template <typename T>
bool DoublyIterator<T> ::Prev(T& item)
{
	m_pCurPointer = m_pCurPointer->prev;	//�������� �����͸� �̵�
	if (!PrevNotNull())
		return false;
	else {
		item = m_pCurPointer->data;
		return true;
	}
}

//���� ����� �������� ����
template <typename T>
T* DoublyIterator<T> ::Next()
{
	m_pCurPointer = m_pCurPointer->next;	//�������� �����͸� �̵�
	if (!NextNotNull())
		return NULL;
	else
		return &m_pCurPointer->data;
}

template <typename T>
T* DoublyIterator<T> ::Current()
{
	return &m_pCurPointer->data;		
}

template <typename T>
T* DoublyIterator<T> ::Prev()
{
	m_pCurPointer = m_pCurPointer->prev;
	if(!PrevNotNull())
		return NULL;
	else
		return &m_pCurPointer->data;
}


//���� node�� �̵��ϰ� �������� ������ �ִ� �Լ�
template<class T>
DoublyNodeType<T>* DoublyIterator<T>::GetNextNode()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer;
}

template<class T>
DoublyNodeType<T>* DoublyIterator<T>::GetPrevNode()
{
	m_pCurPointer = m_pCurPointer->prev;
	return m_pCurPointer;
}

//���� ����� �ּҰ��� ��ȯ�ϴ� �Լ�
template <typename T>
DoublyNodeType<T> DoublyIterator<T> ::GetCurrentNode()
{
	return *m_pCurPointer;
}

//�񱳿����� �����ε�
template<class T>
inline bool DoublyIterator<T>::operator==(DoublyIterator<T>& itor)
{
	return itor.m_pCurPointer ==m_pCurPointer;
}

#endif //_DOUBLYITERATOR_H