#include <map>
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
using namespace std;

class Solution {
    map<Node *,Node *> original_to_clone;
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node * current = head;
        Node * previous_clone = NULL;
        while(current != NULL){
            Node * current_clone = new Node(current->val);
            // map original pointers to cloned pointers
            original_to_clone[current] = current_clone;
            if(previous_clone != NULL){
                // set next in the clone linked list
                previous_clone->next = current_clone;
            }
            //step forward
            current = current->next;
            // current becomes prev since we're stepping forward
            previous_clone = current_clone;
        }
        for(auto elem : original_to_clone){
            if(elem.first->random == NULL){
                // if an element in the original list's random is null
                // we dont need to set the corresponding random pointer in the clone list
                // since it defaults to null
                continue;
            }
            if(elem.second == NULL){
                //account for the tail being null
                continue;
            }
            // set the random pointer in the clone list to point to
            // the random pointer of the corresponding orignal element, 
            // but converted via our original_to_clone map
            
            // this is the only reason we constructed a map
            elem.second->random = original_to_clone[elem.first->random];
        }
        // retrun the converted head to the clone head
        return original_to_clone[head];   
    }
};
