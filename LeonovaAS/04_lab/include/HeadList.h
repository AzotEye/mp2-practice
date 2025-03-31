#pragma once
#include "list.h"

template <typename TData>
class HeadList : public TList<TData>
{
protected:
    TNode<TData>* pHead;
public:
    HeadList() : TList<TData>()
    {
        pHead = new TNode<TData>();
        pHead->pNext = this->pFirst;
    }
    HeadList(const HeadList<TData>& list): TList(list)
    {
        pHead = new TNode<TData>();
        pHead->pNext = this->pFirst;
    }

    void push_front(TNode<TData>* newNode)
    {
        TList<TData>::push_front(newNode);//вызов пуш из TList
        pHead->pNext = this->pFirst;
    }
    void push_back(TNode<TData>* newNode)
    {
        TList<TData>::push_back(newNode);
        pHead->pNext = this->pFirst;
    }
    void push_before(TNode<TData>* newNode, TData target_key)
    {
        TList<TData>::push_before(newNode, target_key);
        pHead->pNext = this->pFirst;
    }

    void remove(TData target_key)
    {
        TList<TData>::remove(target_key);
        pHead->pNext = this->pFirst;
    }

    const HeadList<TData>& operator = (const HeadList<TData>& list)
    {
        TList<TData>::operator = (list);
        pHead->pNext = this->pFirst;//голова всегда пустая + создавать ее не надо, она точно уже будет т.к это не конструктор а оператор присваивания
        return *this;
    }
};