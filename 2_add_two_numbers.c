/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode* cur_node = head;
  int carry = 0;
  int first = 1;
  while (l1 && l2)
    {
      if(!first)
        {
	  cur_node->next = (struct ListNode*) malloc(sizeof(struct ListNode));
	  cur_node = cur_node->next;
        }
      else
        {
	  first = 0;
        }

      cur_node->val = (carry + l1->val + l2->val) % 10;
      carry = (carry + l1->val + l2->val) / 10;

      l1 = l1->next;
      l2 = l2->next;
    }
    
  while (l1)
    {
      cur_node->next = (struct ListNode*) malloc(sizeof(struct ListNode));
      cur_node = cur_node->next;

      cur_node->val = (carry + l1->val) % 10;
      carry = (carry + l1->val) / 10;

      l1 = l1->next;
    }

  while (l2)
    {
      cur_node->next = (struct ListNode*) malloc(sizeof(struct ListNode));
      cur_node = cur_node->next;

      cur_node->val = (carry + l2->val) % 10;
      carry = (carry + l2->val) / 10;

      l2 = l2->next;
    }

  if (carry)
    {
      cur_node->next = (struct ListNode*) malloc(sizeof(struct ListNode));
      cur_node = cur_node->next;

      cur_node->val = carry;

    }

  cur_node->next = NULL;

  return head;
}
