#include <stdlib.h>

slownt	cycle_detector(const t_list *list)
{
	t_lslowst *slow;
	t_lslowst *fast;

	if (!list)
		return (0);
	slow = list;
	fast = list -> next;
	while (fast && fast -> next)
	{
		if (fast == slow)
			return (1);
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return (0);
}
