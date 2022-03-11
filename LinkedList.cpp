#include "LinkedList.h"

LinkedList::LinkedList()
{
    cur = nullptr;
    head.data = 0;
    head.last = nullptr;
    head.next = cur;
    length = 0;
}

LinkedList::LinkedList(int n) : LinkedList()
{
    if (n <= 0)
        return;
    Node* p;
    cur = new Node{ 0, &head, nullptr };
    head.next = cur;
    for (int i = 1; i < n; i++) {
        p = new Node{ 0, cur, nullptr };
        cur->next = p;
        cur = p;
    }
    Reset();
    length = n;
}

LinkedList::LinkedList(const int dataList[], int n) : LinkedList()
{
    if (n <= 0)
        return;
    Node* p;
    cur = new Node{ dataList[0], &head, nullptr };
    head.next = cur;
    for (int i = 1; i < n; i++) {
        p = new Node{ dataList[i], cur, nullptr };
        cur->next = p;
        cur = p;
    }
    Reset();
    length = n;
}

LinkedList::LinkedList(const LinkedList& lt) : LinkedList()
{
    length = lt.length;
    if (length == 0) {
        return;
    }
    Node* p;
    Node* pCur = lt.head.next;//指向lt的临时指针，用于遍历lt，从而给当前对象赋值
    cur = new Node{ pCur->data, &head, nullptr };
    head.next = cur;    
    for (int i = 1; i < length; i++) {
        pCur = pCur->next;
        p = new Node{ pCur->data, cur, nullptr };
        cur->next = p;
        cur = p;
    }
    Reset();
}

LinkedList& LinkedList::operator=(const LinkedList& lt)
{
    //若将自己赋值给自己，则不进行任何操作
    if (&lt == this)
        return *this;

    //赋值之前应先释放原链表
    Reset();
    while (cur != nullptr) {
        Node* temp = cur->next;
        delete cur;
        cur = temp;
    }

    cur = nullptr;
    length = lt.length;
    head.data = 0;
    head.last = nullptr;
    head.next = cur;
    if (length == 0) {
        return *this;
    }
    Node* p;
    Node* pCur = lt.head.next;//指向lt的临时指针，用于遍历lt，从而给当前对象赋值
    cur = new Node{ pCur->data, &head, nullptr };
    head.next = cur;
    for (int i = 1; i < length; i++) {
        pCur = pCur->next;
        p = new Node{ pCur->data, cur, nullptr };
        cur->next = p;
        cur = p;
    }
    Reset();
    return *this;
}

void LinkedList::Set(int data)
{
    if (cur == nullptr)
        return;
    cur->data = data;
}

int LinkedList::Show() const
{
    return cur->data;
}

void LinkedList::ToNext()
{
    if (cur == nullptr || cur->next == nullptr)
        return;
    cur = cur->next;
}

void LinkedList::ToLast()
{
    if (cur == nullptr || cur->last == &head)
        return;
    cur = cur->last;
}

void LinkedList::Add()
{
    if (cur == nullptr) {
        cur = new Node{ 0, &head, nullptr };
        head.next = cur;
    }
    else {
        Node* temp = cur->last;
        temp->next = new Node{ 0, temp, cur };
        cur->last = temp->next;
    }
    length++;
}

void LinkedList::Add(int n)
{
    if (cur == nullptr) {
        cur = new Node{ n, &head, nullptr };
        head.next = cur;
    }
    else {
        Node* temp = cur->last;
        temp->next = new Node{ n, temp, cur };
        cur->last = temp->next;
    }
    length++;
}

void LinkedList::Delete()
{
    if (cur == nullptr)
        return;
    Node* temp = cur->last;
    cur->last->next = cur->next;
    if(cur->next != nullptr)
        cur->next->last = cur->last;
    delete cur;
    length--;
    if (length == 0)
        cur = nullptr;
    else
        cur = temp;
}

void LinkedList::Reset()
{
    cur = head.next;
}


LinkedList::~LinkedList()
{
    Reset();
    Node* temp;
    while (cur != nullptr) {
        temp = cur->next;
        delete cur;
        cur = temp;
    }
}
