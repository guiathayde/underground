#pragma once
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

template <class T1>
class List
{
public:
    template <class T2>
    class Element
    {
    private:
        //aqui guarda a informação
        T2 *info;

        //ponteiros para a lista duplamente encadeada
        Element<T2> *pNext;
        Element<T2> *pPrev;

    public:
        Element(T2 *info)
        {

            SetInfo(info);
            pNext = NULL;
            pPrev = NULL;
        }

        ~Element()
        {

            pNext = NULL;
            pPrev = NULL;
        }

        //funções set
        void SetInfo(T2 *in)
        {
            if (in != NULL)
                info = in;
            else
                cerr << "Info NULL!" << endl;
        }
        void SetNext(Element<T2> *pN)
        {
            pNext = pN;
        }
        void SetPrev(Element<T2> *pP)
        {
            pPrev = pP;
        }

        //funções get return info;
        T2 *GetInfo() { return info != NULL ? info : NULL; }
        Element<T2> *GetNext() { return pNext; }
        Element<T2> *GetPrev() { return pPrev; }
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

    Element<T1> *GetFirstList()
    {
        if (pFirst == NULL)
        {
            cerr << "pFirst in List is NULL!" << endl;
            return NULL;
        }
        return pFirst;
    }

    Element<T1> *GetNextList(Element<T1> *paux)
    {
        paux = paux->GetNext();
        if (paux == NULL)
            return NULL;
        return paux;
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
    if (pnew == NULL)
        cerr << "Triyed insert null element!" << endl;

    Element<T1> *tmp = NULL;
    tmp = new Element<T1>(pnew);

    if (pFirst == NULL)
    {
        pFirst = tmp;
        pFirst->SetPrev(NULL);
        pFirst->SetNext(NULL);
        pLast = pFirst;
    }
    else
    {
        pLast->SetNext(tmp);
        tmp->SetPrev(pLast);
        pLast = tmp;
    }

    n_elementos++;
}

template <class T1>
void List<T1>::ClearAll()
{
    Element<T1> *tmp = NULL;
    while (pFirst != NULL)
    {
        tmp = pFirst;
        pFirst = pFirst->GetNext();
        delete (tmp);
    }
}

template <class T1>
void List<T1>::RemoveInfo(T1 *pRemove)
{
    pFirst = pAux;
    while (pAux != NULL)
    {

        if (pAux->GetInfo() == pRemove)
        {
            pAux->GetPrev()->SetNext(pAux->GetNext());
            pAux->GetNext()->SetPrev(pAux->GetPrev());
            delete (pAux);
        }
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
            //cout << i <<endl;
            if (pA)
                pA = pA->GetNext();
        }
        if (pA)
            return pA->GetInfo();
    }
    else
        cout << "Feliz aniverssario Garret" << endl;
    return NULL;
}