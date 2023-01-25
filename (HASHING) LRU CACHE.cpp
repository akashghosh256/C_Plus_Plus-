https://leetcode.com/problems/lru-cache/description/


-------------------------------------hashmap and doubly linked list approach the best---------------------------------------------------

In summary, the put method first checks if the key already exists in the cache, 
if so it removes the key-node pair from the unordered_map and the node from the doubly linked list. 
  Then it checks if the cache is at capacity, if so it removes the least recently used key-node pair 
  from the unordered_map and the node from the doubly linked list. Then it adds the new node to the front of 
  the doubly linked list and adds the key-node pair to the unordered_map. Overall, this class implements an 
    LRU cache data structure that takes O(1) time for get and put operations.
  

class LRUCache {
public:
    // Inner class to define a node in the doubly linked list
    class node {
        public:
            int key; // Key for the node
            int val; // Value for the node
            node* next; // Pointer to next node in the list
            node* prev; // Pointer to previous node in the list
        // Constructor to initialize key and value
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1); // Dummy head node
    node* tail = new node(-1,-1); // Dummy tail node
    
    int cap; // Capacity of the cache
    unordered_map<int, node*>m; // Map to store key-node pairs
    
    // Constructor that takes in capacity and initializes the dummy head and tail nodes
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    // Method to add a new node to the front of the doubly linked list
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    // Method to delete a node from the doubly linked list
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    // Method to get the value of a key from the cache
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_]; // Retrieve the node from the map
            int res = resnode->val;
            m.erase(key_); // Remove the key-node pair from the map
            deletenode(resnode); // Remove the node from the doubly linked list
            addnode(resnode); // Add the node to the front of the list
            m[key_] = head->next; // Add the key-node pair to the map
            return res; 
        }
    
        return -1; // Return -1 if the key is not in the cache
    }
    
    // Method to add a key-value pair to the cache
    void put(int key_, int value) {
        if(m.find(key_) != m.end()) { // If the key already exists in the cache
            node* existingnode = m[key_];
            m.erase(key_); // Remove the key-node pair from the map
            deletenode(existingnode); // Remove the node from the doubly linked list
        }
        if(m.size() == cap) { // If the cache is at capacity
            m.erase(tail->prev->key); // Remove the least recently used key-node pair from the map
                     deletenode(tail->prev); // Remove the least recently used node from the doubly linked list
        }
        
        addnode(new node(key_, value)); // Add the new node to the front of the doubly linked list
        m[key_] = head->next; // Add the key-node pair to the map
    }
};

