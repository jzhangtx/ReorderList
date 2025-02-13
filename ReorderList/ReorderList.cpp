// ReorderList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;

    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

void SwitchNodes(ListNode** ppHead, ListNode* pTail)
{
    if (pTail == nullptr)
        return;     // only occurs when there is 1 element

    SwitchNodes(ppHead, pTail->next);

    if (*ppHead == nullptr)
        return;
    if (*ppHead == pTail || (*ppHead)->next == pTail)
    {
        pTail->next = nullptr;
        *ppHead = nullptr;
        return;
    }
    
    ListNode* pNextHead = (*ppHead)->next;
    (*ppHead)->next = pTail;
    pTail->next = pNextHead;
    *ppHead = pNextHead;
}

ListNode* ReorderList(ListNode* head)
{
    ListNode* pHead = head;
    SwitchNodes(&pHead, head);
    return head;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count <= 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        ReorderList(pHead);

        std::cout << "The re-ordered list: ";
        PrintList(pHead);
        std::cout << std::endl;

        FreeList(pHead);
    }
}
