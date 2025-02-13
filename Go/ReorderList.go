package main

import "fmt"

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) *ListNode {
	if len(v) == 0 {
		return nil
	}

	if len(v) == 1 {
		return &ListNode{v[0], nil}
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func Reorder(pHead, pTail *ListNode) *ListNode {
	if pTail == nil {
		return pHead
	}

	pNode := Reorder(pHead, pTail.next)
	if pNode == nil {
		return nil
	}

	if pNode == pTail || pNode.next == pTail {
		pTail.next = nil
		return nil
	}

	pNextHead := pNode.next
	pNode.next = pTail
	pTail.next = pNextHead

	return pNextHead
}

func ReorderList(head *ListNode) *ListNode {
	Reorder(head, head.next)
	return head
}

func main() {
	pHead := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, &ListNode{6, &ListNode{7, &ListNode{8, &ListNode{9, nil}}}}}}}}}

	ReorderList(pHead)

	pHead.Print()
}
