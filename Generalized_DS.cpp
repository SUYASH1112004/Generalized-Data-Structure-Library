///////////////////////////////////////////////////////////////////
//
//          Generalized Data Structure Library
//
///////////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------------------------------------
Type                Name of class for node              Name of class for Functionality
-----------------------------------------------------------------------------------------------------------------
Singly Linear       SinglyLLLnode                       SinglyLLL                               
Singly Circular     SinglyCLLnode                       SinglyCLL                               
Doubly Linear       DoublyLLLnode                       DoublyLLL                               
Doubly Circular     DouublyCLLnode                      DoublyCLL                               
-----------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;
#pragma pack(1)

///////////////////////////////////////////////////////////////////
//
//         Singly Linear Linked List using Generic Approach
//
///////////////////////////////////////////////////////////////////


template<class T>
class SinglyLLLnode{

    public :
        T data;
        SinglyLLLnode <T>*next;

        SinglyLLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
        }

};

template<class T>
class SinglyLLL
{

    private :              
        SinglyLLLnode <T> *first;            
        int iCount;

    public:

        SinglyLLL();
        void InsertFirst(T );
        void InsertLast(T );
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int count();

};

template<class T>
SinglyLLL <T>:: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created \n";
    first=NULL;
    iCount=0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Suyash Jagdish Patil
//  Date :              06/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T>::InsertFirst(T no)
{

    SinglyLLLnode <T>*newn = NULL;
    newn = new SinglyLLLnode<T>(no);
    
    newn->next=this->first;               
    this->first=newn;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL <T>::InsertLast(T no)
{
    SinglyLLLnode <T>* temp = NULL;
    SinglyLLLnode <T>* newn = NULL;
    int i = 0;
    newn = new SinglyLLLnode<T>(no);

    if(this->iCount==0)               
    {
        first=newn;
    }
    else
    {
        temp=this->first;
        
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node , Position of node
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL <T>::InsertAtPos(T no,int pos)
{

    int i = 0;

    SinglyLLLnode <T>* newn = NULL;
    SinglyLLLnode <T>* temp = NULL;
    

    if(pos<1 || pos>this->iCount+1)
    {
        cout<<"Invalid Position \n";
        return;
    }
    else if(pos==1)
    {
        this->InsertFirst(no);
    }
    else if(pos==this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);
        temp =this->first;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        this->iCount++;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL <T>::DeleteFirst()
{
    SinglyLLLnode <T>* temp = NULL;
    if(this->first==NULL)
    {
        return;
    }
    else if(this->first->next==NULL)        
    {
        delete this->first;
        this->first=NULL;
    }
    else
    {
        
        temp = this->first;
        this->first=this->first->next;
        delete temp;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL <T>::DeleteLast()
{
    SinglyLLLnode <T>* temp = NULL;
    if(this->first==NULL)
    {
        return;
    }
    else if(this->first->next==NULL)         
    {
        delete this->first;
        this->first=NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next->next != NULL)
        {
            temp=temp->next;
        }

        delete temp->next;
        temp->next=NULL;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position of node
//  Output :            Nothing
//  Description :       Used to delete node at given position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL <T>:: DeleteAtPos(int pos)
{
    int i = 0;

    SinglyLLLnode <T>* temp = NULL;
    SinglyLLLnode <T>* target = NULL;

    if(pos<1 || pos>this->iCount)
    {
        cout<<"Invalid Position \n";
        return;
    }
    else if(pos==1)
    {
        this->DeleteFirst();
    }
    else if(pos==iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp =this->first;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        target = temp->next;
        temp->next=temp->next->next;
        delete target;

        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Linked list is displayed
//  Description :       Used to display the Linked List
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL <T>::Display()
{
    SinglyLLLnode <T>* temp = NULL;
    int iCnt = 0;

    temp = this->first;
    for(iCnt = 1; iCnt <= this->iCount;iCnt++)        
    {
        cout<<" | "<<temp->data<<" | ->";
        temp=temp->next;
    }
    cout<<"NULL \n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to return the count of nodes in linked list
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T>::count()
{
    return this->iCount;
}




/////////////////////////////////////////////////////////////////////////
//
//          Doubly Linear Linked List using Generic Approach
//
/////////////////////////////////////////////////////////////////////////



template <class T>
class  DoublyLLLnode{

    public :
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
            this->prev = NULL;
        }

};

template <class T>
class DoublyLLL{

    private:
        DoublyLLLnode<T> *first;
        int iCount;
    
    public:
        DoublyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int count();

};

template <class T>
DoublyLLL <T> :: DoublyLLL()
{
    cout<<"LinkedList Gets Created \n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>:: InsertFirst(T no)
{
    DoublyLLLnode <T>*newn = NULL;
    newn= new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first=newn;
    }
    else
    {
        newn->next=this->first;
        this->first->prev=newn;
        this->first=newn;

    }
    this->iCount++;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>::InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;
    newn= new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first=newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp=temp->next;
        }

        temp->next=newn;
        newn->prev=temp;
        

    }
    this->iCount++;
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>::DeleteFirst()
{
    if(this->first == NULL)              
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first=NULL;        
    }
    else
    {   
        
        this->first=this->first->next;
        delete this->first->prev;
        this->first->prev=NULL;
    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>::DeleteLast()
{
    DoublyLLLnode <T>*temp = NULL;
    if(this->first == NULL)                
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first=NULL;        
    }
    else
    {   
        temp = this->first;
        while(temp->next->next != NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    this->iCount--;
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position of node
//  Output :            Nothing
//  Description :       Used to delete node at given position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp =NULL;
    int iCnt = 0;

    if(pos<1 || pos>this->iCount)
    {
        cout<<"Incorrect Position";
        return;
    }
    else if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        
        temp = this->first;
        
        for(iCnt = 1; iCnt<pos -1 ;iCnt++)
        {
            temp=temp->next;   
        }
        
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        this->iCount--;
    }
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Linked list is displayed
//  Description :       Used to display the Linked List
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>::Display()
{
    DoublyLLLnode <T>*temp = NULL;
    temp=first;
    cout<<"\nNULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp=temp->next;
    }
    cout<<"NULL\n";

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to return the count of nodes in linked list
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL <T>::count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node , Position of node
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp =NULL;
    DoublyLLLnode<T> *newn = NULL;
    int iCnt = 0;

    if(pos<1 || pos>this->iCount+1)
    {
        cout<<"Incorrect Position";
        return;
    }
    else if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = first;
        
        for(iCnt = 1; iCnt<pos -1 ;iCnt++)
        {
            temp=temp->next;   
        }
        
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev = temp;

        this->iCount++;
    }

    
}


/////////////////////////////////////////////////////////////////////////
//
//          Singly Circular Linked List using Generic Approach
//
/////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLLnode{
    public :
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCircular{

    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public :
        SinglyCircular();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int);
        void InsertAtPos(T ,int );
};

template <class T>
SinglyCircular<T>::SinglyCircular()
{
    cout<<"Object of Singly circular linked list created \n";
    this->first =NULL;
    this->last=NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircular<T>::InsertFirst(T no)
{
    SinglyCLLnode <T>*newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    newn->data=no;
    newn->next=NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first=newn; 
        this->last = newn;
       
    }
    else
    {
        newn->next=this->first;
        this->first=newn; 
    }

    this->iCount++;
    this->last->next=this->first;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircular<T>::InsertLast(T no)
{
    
    SinglyCLLnode <T>*newn = NULL;
    newn = new SinglyCLLnode<T>(no);
    newn->data=no;
    newn->next = NULL;

    if(this->first==NULL && this->last==NULL)
    {
        this->first=this->last=newn;
        
    }
    else
    {
        this->last->next=newn;
        this->last=newn;

    }
    
    this->iCount++;
    this->last->next=this->first;


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircular<T>::DeleteFirst()
{
    SinglyCLLnode<T> *target = NULL;
    if(this->first == NULL || this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
        this->iCount--;
    }
    else
    {
        
        target = this->first;
        this->first=this->first->next;
        delete target;
        this->last->next=this->first;
        this->iCount--;
    }
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircular<T>::DeleteLast()
{
    if(this->first == NULL || this->last == NULL)
    {
        return;
    }
    else if(this->first == last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
        this->iCount--;
    }
    else
    {
        SinglyCLLnode<T> *target = NULL;
        SinglyCLLnode <T>*temp = NULL;
        temp=this->first;
        
        while(temp->next != last)
        {
            temp=temp->next;
        }

        this->last=temp;
        temp=temp->next;
        delete temp;

        this->last->next=this->first;
        this->iCount--;

        

    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Linked list is displayed
//  Description :       Used to display the Linked List
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircular<T>::Display()
{
    if(this->first == NULL || this->last == NULL)
    {
        cout<<"Empty Linked List \n";
        return;
    }
    SinglyCLLnode <T>*temp = this->first;
    cout<<"->";
    do
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;

    } while (temp!=first);
    cout<<"\n";
                
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to return the count of nodes in linked list
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCircular<T>::Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position of node
//  Output :            Nothing
//  Description :       Used to delete node at given position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircular<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;

    if(pos < 1 || pos> this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        SinglyCLLnode<T> *target = NULL;
        target = temp->next;
        temp->next=target->next;
        delete target;
        this->iCount--;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node , Position of node
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircular<T>::InsertAtPos(T no,int pos)
{
    SinglyCLLnode <T>*newn = NULL;

    if(pos < 1 || pos> this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        SinglyCLLnode<T> *temp = this->first;
        
        newn = new SinglyCLLnode<T>(no);

        newn->data=no;
        newn->next = NULL;


        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        iCount++;
        this->last->next = this->first;

    }

    
}


/////////////////////////////////////////////////////////////////////////
//
//          Doubly Circular Linked List using Generic Approach
//
/////////////////////////////////////////////////////////////////////////


template <class T>
class DoublyCLLnode{
    
    public:
        T data;
        DoublyCLLnode <T>*next;
        DoublyCLLnode <T>*prev;
        DoublyCLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
            this->prev=NULL;
        }
};


template <class T>
class DoublyCLL{

    private:
        DoublyCLLnode <T>* first;
        DoublyCLLnode <T>* last;
        int iCount;

    public :
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int );        
        void InsertAtPos(T ,int);
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of Doubly circular linked list created \n";
    first =NULL;
    last=NULL;
    iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode <T>*newn = NULL;
    newn = new DoublyCLLnode<T>(no);
    if(this->first == NULL && this->last == NULL)
    {
        
        this->first=newn; 
        this->last = newn;
    }
    else
    {
        newn->next=this->first;
        this->first->prev=newn;
        this->first=newn; 
    }

    this->iCount++;
    this->last->next=this->first;
    this->first->prev=this->last;

}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{

    DoublyCLLnode <T>*newn = NULL;
    newn = new DoublyCLLnode<T>(no);
    

    if(this->first == NULL && this->last == NULL)
    {
        
        this->first=newn; 
        this->last = newn;
        // iCount++;
    }
    else
    {
        this->last->next=newn;
        newn->prev=this->last;
        this->last=newn;
    }          

    this->iCount++;
    this->last->next=this->first;
    this->first->prev=this->last;


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(this->first == NULL || this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
        this->iCount--;
    }
    else
    {
        DoublyCLLnode <T>*target = NULL;
        target = this->first;
        this->first=this->first->next;
        delete target;
        this->last->next=this->first;
        this->first->prev=this->last;
        this->iCount--;
    }
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(this->first == NULL ||this->last == NULL)
    {
        return;
    }
    else if(this->first ==this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
        this->iCount--;
    }
    else
    {
        this->last=this->last->prev;
        delete this->last->next;
        

        this->last->next=this->first;
        this->first->prev=this->last;
        this->iCount--;

        

    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Linked list is displayed
//  Description :       Used to display the Linked List
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::Display()
{
    DoublyCLLnode <T>* temp = this->first;
    cout<<"<=>";
    do
    {
        cout<<temp->data<<" <=> ";
        temp=temp->next;

    } while (temp!=this->first);
    printf("\n");
                
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to return the count of nodes in linked list
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position of node
//  Output :            Nothing
//  Description :       Used to delete node at given position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{

    if(pos < 1 || pos> iCount)
    {
        printf("Invalid position\n");
        return;
    }

    else if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        DoublyCLLnode <T>* temp = this->first;

        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        DoublyCLLnode <T>* target = NULL;
        target = temp->next;
        temp->next=target->next;
        target->next->prev=temp;
        delete target;
        this->iCount--;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node , Position of node
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Suyash Jagdish Patil
//  Date :              07/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
    if(pos < 1 || pos> this->iCount+1)
    {
        printf("Invalid position\n");
        return;
    }

    else if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        DoublyCLLnode <T>* temp = this->first;
        DoublyCLLnode <T>* newn = NULL;
        newn = new DoublyCLLnode <T>(no);

        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        this->iCount++;
        this->last->next = this->first;
        this->first->prev=this->last;

    }

    
}



//////////////////////////////////  End Of Library    ///////////////////////////////////////
int main()
{
    return 0;
}
