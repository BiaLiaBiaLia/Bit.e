#include <iostream>
using namespace std;

struct ListNode
{
	ListNode *pnext;
	int val;
	ListNode(int x) :val(x), pnext(nullptr) {}
};
int main()
{
	int t;
	ListNode *phead = new ListNode(0);
	ListNode *pcurr = phead;
	int n = 0;
	while (cin >> t)
	{
		pcurr->pnext = new ListNode(t);
		pcurr = pcurr->pnext;
		n++;
		if (getchar() == '\n')
			break;
	}
	int k;
	cin >> k;
	if (n == 1)
	{
		cout << phead->pnext->val << endl;
		return 0;
	}
	int m = n / k;
	ListNode *pfirst = phead->pnext, *psecond = pfirst->pnext, *pstart1 = phead, *pstart2 = pfirst;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < k - 1; ++j)
		{
			ListNode *ptemp = psecond->pnext;
			psecond->pnext = pfirst;
			pfirst = psecond;
			psecond = ptemp;
		}
		pstart1->pnext = pfirst;
		ListNode *ptemp2 = psecond->pnext;
		pfirst = psecond;
		psecond = ptemp2;
		pstart1 = pstart2;
		pstart2 = pfirst;
	}
	pstart1->pnext = pstart2;
	ListNode *pcur = phead->pnext;
	cout << pcur->val;
	pcur = pcur->pnext;
	while (pcur)
	{
		cout << " " << pcur->val;
		pcur = pcur->pnext;
	}
	cout << endl;

	system("pause");
	return 0;
}