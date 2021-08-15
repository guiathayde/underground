#pragma once
#include "stdfix.h"

template <class T1>
class List
{
public:
    template <class T2>
    class Element
    {
    private:
        T2 *info;

        Element<T2> *pNext;

    public:
        Element(T2 *info)
        {

            SetInfo(info);
            pNext = NULL;
        }

        ~Element()
        {

            pNext = NULL;
        }

        void SetInfo(T2 *in)
        {
            if (in != NULL)
                info = in;
            else
                cerr << "Info to insert in List is NULL" << endl;
        }
        void SetNext(Element<T2> *pN)
        {
            pNext = pN;
        }
       

        T2 *GetInfo() { return info; }
        Element<T2> *GetNext() { return pNext; }
    };

private:
    Element<T1> *pFirst;
    Element<T1> *pLast;
    Element<T1> *pAux;

    int n_elementos;

public:
    List();
    ~List();

    void Insert(T1 *pnew);
    void ClearAll();
    void RemoveInfo(T1 *pRemove);
    void Delete(T1 *pDelete);
    void ListAll();

    int GetSize() { return n_elementos; }

    T1 *operator[](int x);

    T1 *GetFirstList()
    {

        pAux = pFirst;
        return pAux->GetInfo();
    }

    T1 *GetNextList()
    {
        pAux = pAux->GetNext();
        if (pAux == NULL)
            return NULL;
        return pAux->GetInfo();
    }
};

template <class T1>
List<T1>::List() : pFirst(NULL), pLast(NULL), pAux(NULL)
{
    n_elementos = 0;
}

template <class T1>
List<T1>::~List()
{
    ClearAll();
    pFirst = NULL;
}

template <class T1>
void List<T1>::Insert(T1 *pnew)
{

    Element<T1> *tmp = NULL;
    tmp = new Element<T1>(pnew);
    if (pFirst == NULL)
    {
        pFirst = tmp;
        pFirst->SetNext(NULL);
        pLast = pFirst;
    }

    else
    {
        pLast->SetNext(tmp);
        pLast = tmp;
    }

    n_elementos++;
}

template <class T1>
void List<T1>::ClearAll()
{
    while (pFirst != NULL)
    {
        Element<T1> *tmp = NULL;
        tmp = pFirst;
        if (pFirst)
            pFirst = pFirst->GetNext();
        delete (tmp);
    }
}

template <class T1>
void List<T1>::RemoveInfo(T1 *pRemove)
{

    Element<T1> *tmp_atual = NULL;
    Element<T1> *tmp_anterior = NULL;

    tmp_atual = pFirst;
    
    while (tmp_atual)
    {
        if (tmp_atual->GetInfo() == pRemove)
        {   
            if(tmp_anterior){
                tmp_anterior->SetNext(tmp_atual->GetNext());
            }
            delete(tmp_atual->GetInfo());
            delete(tmp_atual);
            n_elementos--;
            return;
        }
        if(tmp_atual)
            tmp_anterior = tmp_atual;
        
        if(tmp_atual)
            tmp_atual = tmp_atual->GetNext();
    }
}

template <class T1>
T1 *List<T1>::operator[](int x)
{
    if (x < n_elementos && x >= 0)
    {
        Element<T1> *pA;
        pA = pFirst;

        for (int i = 0; i < x; i++)
        {
            if (pA)
                pA = pA->GetNext();
        }
        if (pA)
            return pA->GetInfo();
    }
    else
        cerr << "Error using operator of the List"
             << "o n de elementos" << n_elementos << " o x " << x << endl;
    return NULL;
}