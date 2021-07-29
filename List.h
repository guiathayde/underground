#pragma once
#include<iostream>
using std::cout;
using std::endl;

template <class TypeElement>
class Element{
private:
    
    TypeElement info;
    Element<TypeElement> *pNext;
    Element<TypeElement> *pPrev;

public:

    Element(TypeElement *info);
    ~Element();
    
    void SetInfo(TypeElement &info);
    TypeElement GetInfo();

    void SetNext(Element<TypeElement>* pN);
    Element<TypeElement>* GetNext();
    
    void SetPrev(Element<TypeElement>* pP);
    Element<TypeElement>* GetPrev();

};

template <class TypeElement>
Element<TypeElement>::Element(TypeElement *info){
    SetInfo(&info);
    pNext = NULL;
    pPrev = NULL;
}

template <class TypeElement>
Element<TypeElement>::~Element(){
    pNext = NULL;
    pPrev = NULL;

}

template <class TypeElement>
void Element<TypeElement>::SetInfo(TypeElement &info){
    this->info = info;
}

template <class TypeElement>
TypeElement Element<TypeElement>::GetInfo(){
    return info;
}

template <class TypeElement>
void Element<TypeElement>::SetNext(Element<TypeElement>* pN){
    if(pN == NULL)
        cout << "Elemento Nulo" << endl; 
    else
        pNext = pN;
}

template <class TypeElement>
Element<TypeElement>* Element<TypeElement>::GetNext(){
    return pNext;
}

template <class TypeElement>
void Element<TypeElement>::SetPrev(Element<TypeElement>* pP){
    if(pP == NULL)
        cout << "Elemento Nulo" <<endl;
    else
        pPrev = pP;
}

template <class TypeElement>
Element<TypeElement>* Element<TypeElement>::GetPrev(){
    return pPrev;
}

template <class TypeList>
class List
{
private:
    
    
    Element<TypeList> *pFirst;
    Element<TypeList> *pLast;
    int size;
    



public:

    List();
    ~List();

    TypeList* operator[](int i);

    void Push_Back(TypeList pNew);
    void Erase(TypeList *element);
    void ClearAll();
    void ListAll();
    
    
    void SetSize(int s);
    int GetSize();

};


template<class TypeList>
TypeList* List<TypeList>::operator[](int i){
    if(i <= size && i >= 0 ){
        Element<TypeList> *tmp = pFirst;
        for(int j = 0; j != i ; j++){
            tmp = tmp->GetNext();
        }
        return tmp;
    }
    cout << "Local inacessível"<<endl;
    exit(1);
}


template <class TypeList>
List<TypeList>::List()
{
    pFirst = NULL;
    pLast = NULL;
    size = 0;
}
template <class TypeList>
List<TypeList>::~List()
{
    ClearAll();
}

template<class TypeList>
void List<TypeList>::Push_Back(TypeList pNew){
    if(pNew != NULL){
        Element<TypeList> *tmp = NULL;
        tmp = new Element<TypeList>(pNew);
        tmp->SetInfo(*pNew);
        
        if(pFirst == NULL){
            pFirst = tmp;
        }
        else{
            pLast->SetNext(tmp);
            tmp->SetPrev(pLast);
        }
        pLast = tmp;
        size++;
        SetSize(size);
    }
}
template<class TypeList>
void List<TypeList>::Erase(TypeList *element){
    
    if(element != NULL){
        Element<TypeList>* tmp = pFirst;
        while(tmp != NULL){
            if(tmp->GetInfo() == element){
                tmp->GetNext()->SetPrev(tmp->GetPrev);
                tmp->GetPrev()->SetNext(tmp->GetNext);
                tmp= NULL;
                break;
            }
            tmp->GetNext();
        }
        
    }
}

template<class TypeList>
void List<TypeList>::ClearAll(){
    while(pFirst != NULL){
        
        Element<TypeList>* tmp = pFirst;
        pFirst = pFirst->GetNext();
        pFirst->SetPrev(NULL);
        
        delete(tmp);
    }

}

template<class TypeList>
void List<TypeList>::ListAll(){
    if(pFirst != NULL){
        Element<TypeList> *tmp = pFirst;
        while(tmp != NULL){
            cout << tmp <<endl;
            tmp = tmp->GetNext();
        }
        
    }

}
template<class TypeList>
void List<TypeList>::SetSize(int s){
    size = s;
}

template<class TypeList>
int List<TypeList>::GetSize(){
    return size;
}