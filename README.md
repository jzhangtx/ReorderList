Reorder List


Given a linked list of the form:

N0 → N1 → N2 → ....Nn-2 → Nn-1
Reorder the list in the following format:

N0 → Nn-1 → N1 → Nn-2 → N2 → ....
Example
Linked list: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9
Result: 1 → 9 → 2 → 8 → 3 → 7 → 4 → 6 → 5
Linked list: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
Result: 1 → 8 → 2 → 7 → 3 → 6 → 4 → 5
Testing
Input Format
The first line contains an integer ‘T’ denoting the number of independent test cases.

For each test case the input has two lines:

An integer ‘n’ denoting the length of the linked list.
n space-separated integers denoting elements of the linked list.
Output Format
For each test case, a line containing ‘n’ space-separated integers denoting the resultant linked list elements.

Sample Input
2
9
1 2 3 4 5 6 7 8 9
8
1 2 3 4 5 6 7 8
Expected Output
1 9 2 8 3 7 4 6 5
1 8 2 7 3 6 4 5