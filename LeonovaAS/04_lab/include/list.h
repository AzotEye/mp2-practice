#pragma once
#include <iostream>
using namespace std;

template <typename TData>
struct TNode
{
    TData key;
    TNode* pNext;

    TNode()
    {
        key = TData();
        pNext = nullptr;
    }
    TNode(TData key)
    {
        this->key = key;
        pNext = nullptr;
    }

    friend ostream& operator << (ostream& os, const TNode<TData>& node)
    {
        os << node.key;
        return os;
    }
    const TNode<TData>& operator = (const TNode<TData>& node)
    {
        if (this == &node)
        {
            return *this;
        }
        key = node.key;
        pNext = node.pNext;
        return *this;
    }
};

template <typename TData>
class TList
{
protected:
    TNode<TData>* pFirst;
    TNode<TData>* pCurr;
    TNode<TData>* pPrev;
    TNode<TData>* pLast;
    TNode<TData>* pStop;
public:
    TList()
    {
        pFirst = nullptr;
        pCurr = nullptr;
        pPrev = nullptr;
        pStop = nullptr;
        pLast = nullptr;
    }
    TList(const TList<TData>& list)
    {
        if (list.pFirst == nullptr)
        {
            pFirst = nullptr;
            return;
        }
        copy(list);
        pStop = nullptr;
    }
    ~TList()
    {
        reset();
        if (pFirst == nullptr)
        {
            return;
        }
        clear();
        pFirst = nullptr;
    }

    void copy(const TList<TData>& list)//из констуктора копирования(через навигацию не получается:( )
    {
        pFirst = new TNode<TData>(list.pFirst->key);
        TNode<TData>* curr_origin = list.pFirst->pNext;
        TNode<TData>* curr_copy = pFirst;
        while (curr_origin != list.pStop)
        {
            curr_copy->pNext = new TNode<TData>(curr_origin->key);
            curr_copy = curr_copy->pNext;
            curr_origin = curr_origin->pNext;
        }
        pLast = curr_copy;
    }

    void clear()//цикл из деструктора
    {
        reset();
        while (!(is_ended()))
        {
            TNode<TData>* tmp = pCurr->pNext;
            delete pCurr;
            pCurr = tmp;
        }
    }

    void reset()
    {
        pCurr = pFirst;
        pPrev = nullptr;
    }
    void next()
    {
        pPrev = pCurr;
        pCurr = pCurr->pNext;
    }
    bool is_ended()
    {
        return pCurr == pStop;
    }
    TNode<TData>* getCurr() const
    {
        return pCurr;
    }

    TNode<TData>* search(TData target_key)
    {
        reset();
        if (pCurr == nullptr)
        {
            return nullptr;
        }
        while (!(is_ended()))
        {
            if (pCurr->key == target_key)
            {
                return pCurr;
            }
            next();
        }
        return nullptr;
    } 

    virtual void push_front(TNode<TData>* newNode)
    {
        if (pFirst == nullptr)
        {
            pFirst = newNode;
            pLast = pFirst;
            return;
        }
        newNode->pNext = pFirst;
        pFirst = newNode;
    }
    virtual void push_back(TNode<TData>* newNode)
    {
        if (newNode == nullptr)
        {
            throw "node is empty!";
        }
        reset();
        if (pCurr == nullptr)
        {
            push_front(newNode);
            return;
        }
        while (pCurr->pNext != pStop)
        {
            next();
        }
        pCurr->pNext = newNode;
        pLast = pCurr->pNext;
    }
    virtual void push_after(TNode<TData>* newNode, TData target_key)
    {
        pCurr = this->search(target_key);
        if (pCurr == nullptr)
        {
            throw "no key found!";
        }
        newNode->pNext = pCurr->pNext;
        pCurr->pNext = newNode;
    }
    virtual void push_before(TNode<TData>* newNode, TData target_key)//переделано на поиск
    {
        reset();
        if (pCurr->key == target_key)
        {
            push_front(newNode);
            return;
        }
        pCurr = this->search(target_key);
        if (pCurr == nullptr)
        {
            throw "no key found!";
        }
        TNode<TData>* tmp = pCurr;
        pPrev->pNext = newNode;
        newNode->pNext = tmp;
    }

    virtual void remove(TData target_key)//переделано на поиск
    {
        reset();
        if (search(target_key) == nullptr)
        {
            throw "no key found!";
        }
        if (pFirst->key == target_key)
        {
            pFirst = pCurr->pNext;
            return;
        }
        pCurr = this->search(target_key);
        if (pCurr == pLast)//отлов последнего необходим 
        {
            pPrev->pNext = pCurr->pNext;
            pLast = pPrev;
            return;
        }
        pPrev->pNext = pCurr->pNext;
    }

    const TList<TData>& operator = (const TList<TData>& list)//добавлена копия, деструктор заменен на метод clear(), основной цикл заменен на copy()
    {
        TList<TData> listcopy(list);
        if (this == &list)
        {
            return *this;
        }
        if (listcopy.pFirst == nullptr)
        {
            pFirst = nullptr;
            pLast = nullptr;
            return *this;
        }
        if (pFirst != nullptr)
        {
            clear();
        }
        copy(listcopy);
        return *this;
    }
    bool operator == (const TList<TData>& list) const //переделано на работу через копии
    {
        TList<TData> myself(*this);
        TList<TData> listcopy(list);

        myself.reset();
        listcopy.reset();
        if (myself.pCurr == nullptr && listcopy.pCurr == nullptr)
        {
            return true;
        }
        while (!(listcopy.is_ended()) && !(myself.is_ended()))
        {
            if ((myself.pCurr->key != listcopy.pCurr->key))
            {
                return false;
            }
            listcopy.next();
            myself.next();
        }
        return true;
    }
    bool operator != (const TList<TData>& list) const
    {
        return !(*this == list);
    }
};