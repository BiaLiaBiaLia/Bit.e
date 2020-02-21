//双向链表的逆置

//逆置方法一：从两头走，交换数据
/*
	void Reverse()
    {
        ListNode* begin = _head;
        ListNode* end = _tail;
        while (!((begin == end) || (end->_next == begin)))
        {
            swap(begin->_data, end->_data);
            begin = begin->_next;
            end = end->_prev;
        }
    }
*/

//逆置方法二：交换节点的前驱和后继
/*
	void Reverse()
    {
        ListNode* cur = _head;
        while (cur)
        {
            swap(cur->_prev, cur->_next);
            cur = cur->_prev;
        }
        swap(_head, _tail);
    }
*/

//逆置方法三：摘节点，头插该节点
/*
void Reverse()
{
	ListNode* cur  = _head;
	ListNode* newhead  = NULL;
	while (cur)
	{
		ListNode* tmp  = cur;
		cur  = cur->_next;
		if (newhead  == NULL)
		{
			newhead  = tmp;

			newhead->_next  = NULL;
			newhead->_prev  = NULL;
			_head  = _tail  = newhead;
		}
			else
			{
			newhead->_prev  = tmp;
			tmp->_next  = newhead;
			newhead  = tmp;
			_head  = newhead;
			_head->_prev  = NULL;
			}
	}
}
*/