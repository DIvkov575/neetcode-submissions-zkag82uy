/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

using nmap = unordered_map<Node*, Node*>;


class Solution {
public:
    
Node* makenode(Node* head, nmap& mp) {
    if (!head) return nullptr;
    if (mp.count(head)) return mp[head];

    Node* tmp = new Node(head->val);
    mp[head] = tmp;

    tmp->next   = makenode(head->next, mp);
    tmp->random = makenode(head->random, mp);

    return tmp;
}

    Node* copyRandomList(Node* head) {
       unordered_map<Node*, Node*> mp(50);
       mp[nullptr] = nullptr;

       return makenode(head, mp);
    }
};
