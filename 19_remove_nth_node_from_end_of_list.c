/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  struct ListNode* curNode = head;

  // if n = 1, just remove the tail
  if (n == 1)
    {
      // if there is only 1 element, return NULL
      if (!head->next)
        {
	  free(head);
	  return NULL;
        }

      struct ListNode* prevNode;

      while (curNode->next != NULL)
        {
	  prevNode = curNode;
	  curNode = curNode->next;
        }
        
      prevNode->next = NULL;
      free(curNode);
        
      return head;
    }

  struct ListNode** nodelist = (struct ListNode**) malloc((n+1) * sizeof(struct ListNode*));

  // fill a circular array
  for (int index = 0; index < (n+1); index++)
    {
      nodelist[index] = curNode;
      if (curNode != NULL)
	curNode = curNode->next;
    }

  // if circular array is not fully populated, directly remove the head element
  if (curNode == NULL && nodelist[n] == NULL)
    {
      head = nodelist[1];
      free(nodelist[0]);
      free(nodelist);
      return head;
    }
    
  // track the end of the circular array
  int endtrack = 0;

  // continue replacing elements of the circular array until the end is reached
  while (curNode != NULL) 
    {
      nodelist[endtrack] = curNode;
      curNode = curNode->next;
      endtrack = (endtrack + 1) % (n+1);
    }

  // re-link the elements around the one to be freed
  nodelist[(endtrack) % (n+1)]->next = nodelist[(endtrack + 2) % (n+1)];

  // free the target and the storage array
  free(nodelist[(endtrack + 1) % (n+1)]);
  free(nodelist);

  return head;
}
