#pragma once
#include "HeadList.h"

template <typename TData>
class RingHeadList : public HeadList<TData>
{
public:
    RingHeadList() : HeadList<TData>()
    {
        this->pLast = this->pHead;
        this->pHead->pNext = this->pLast;
        this->pStop = this->pHead;
    }
    RingHeadList(const RingHeadList<TData>& list): HeadList(list)
    {
        if (list.pFirst == nullptr)//через базовый не получитс€ из за наличи€ головы
        {
            this->pFirst = nullptr;
            this->pLast = this->pHead;
            this->pHead->pNext = this->pLast;
            this->pStop = this->pHead;
            return;
        }
        this->pStop = this->pHead;
        this->pLast->pNext = this->pHead;//закольцовка
    }

    void push_front(TNode<TData>* newNode)
    {
        HeadList<TData>::push_front(newNode);
        this->pLast->pNext = this->pHead;
    }
    void push_back(TNode<TData>* newNode)
    {
        HeadList<TData>::push_back(newNode);
        this->pLast->pNext = this->pHead;
    }
    void push_after(TNode<TData>* newNode, TData target_key)
    {
        if (this->pLast->key == target_key)//вдруг хотим вставить в конец? нужно следить за pLast
        {
            this->push_back(newNode);
            return;
        }
        if (this->pHead->key == target_key)
        {
            this->push_front(newNode);
            return;
        }
        HeadList<TData>::push_after(newNode, target_key);
    }
    //в пуш бефоре никак ласт не задеваетс€, переписывать не надо, сам возьметот пхеда

    void remove(TData target_key)
    {
        if (this->pFirst->key == target_key && this->pFirst == this->pLast)
        {
            //нельз€ оставить общий случай, тут необходимо зациклить голову на себе 

            this->pLast = this->pHead;
            this->pLast->pNext = this->pHead;
            this->pFirst = nullptr;
            return;
        }
        HeadList<TData>::remove(target_key);
        this->pLast->pNext = this->pHead;//на вс€кий случай, вдруг последний изменилс€
    }

    const RingHeadList<TData>& operator = (const RingHeadList<TData>& list)
    {
        if (list.pFirst == nullptr)
        {
            this->pFirst = nullptr;
            this->pLast = this->pHead;
            this->pHead->pNext = this->pLast;
            this->pStop = this->pHead;
            return *this;
        }

        HeadList<TData>::operator=(list);

        this->pStop = this->pHead;
        this->pLast->pNext = this->pHead;
    }

};