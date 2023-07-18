struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* res = malloc(sizeof(struct ListNode));
    res->next = NULL;
    
    struct ListNode* currentNode;
    
    int s = 0;
    int r = 0;
    currentNode = res;
    struct ListNode* l1Node = l1;
    struct ListNode* l2Node = l2;
    
    for (int i = 0; i < 100; i++) {
      s = (l1Node == NULL ? 0 : l1Node->val) + (l2Node == NULL ? 0 : l2Node->val);
      s += r;
      r = 0;
      
      if (s > 9) {
        r = 1;
        s = s - 10;
      }
      
      currentNode->val = s;
      
      if (l1Node != NULL && l1Node->next) {
        l1Node = l1Node->next;
      } else {
        l1Node = NULL;
      }
      
      if (l2Node != NULL && l2Node->next) {
        l2Node = l2Node->next;
      } else {
        l2Node = NULL;
      }
      
      if (l1Node == NULL && l2Node == NULL && r == 0) {
        break;
      } else {
        struct ListNode* anewnode = malloc(sizeof(struct ListNode));
        anewnode->next = NULL;
        
        currentNode->next = anewnode;
        currentNode = anewnode;
      }
      
    }
    
    return res;
};
