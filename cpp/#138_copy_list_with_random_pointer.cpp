
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


// solution:  using a hash map to store the mapping between original nodes and 
// their corresponding new nodes in the copied list.

#include <unordered_map>

class Solution {
public:
    // time: O(n) | space: O(n)
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        // unordered_map for mapping the original nodes to their copies
        std::unordered_map<Node*, Node*> nodeMap;
        Node* current = head;
        
        // First pass: creating new nodes and map original nodes to their copies
        while (current != nullptr) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }
        
        current = head;
        
        // Second pass: assigning next and random pointers for the new nodes
        while (current != nullptr) {
            nodeMap[current]->next = nodeMap[current->next];
            nodeMap[current]->random = nodeMap[current->random];
            current = current->next;
        }
        
        // Return the head of the new list
        return nodeMap[head];
    }
};
