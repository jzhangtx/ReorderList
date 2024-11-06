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

void SwitchNodes(ListNode** ppHead, ListNode* pTail, int& left, int& right)
{
    if (left >= right)
        return;     // left and right meet

    if (pTail == nullptr)
        return;     // only occurs when there is 1 element

    if (pTail->next == nullptr)
    {                       // reached the last element
        ++left;
        return;
    }

    SwitchNodes(ppHead, pTail->next, left, ++right);

    if (left != 0 && left < right)
    {                       // list end reached and left and right have not met
        if (*ppHead != pTail)
        {                   // if the element count in the list is even, when
                            //  left and right meet, head is the previous element
                            //  of the tail. we don't need to do anything in that
                            //  case
            // store the next of the left
            ListNode* pTemp = (*ppHead)->next;

            // link tail to the tail's next element
            pTail->next->next = pTemp;

            // link left to the right and clean the tail
            (*ppHead)->next = pTail->next;
            pTail->next = nullptr;

            // move to the next pair needs to be switched
            if ((*ppHead)->next != nullptr)
                *ppHead = (*ppHead)->next->next;
        }
        --right;
        ++left;
    }
}

ListNode* ReorderList(ListNode* head)
{
    int left = 0;
    int right = 1;
    ListNode* pHead = head;
    SwitchNodes(&pHead, head, left, right);
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
