// Time Complexity:O(N)
// Space Complexity:O(1)

class LRUCache {
private:
    // Node class to represent each node in the doubly linked list
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1); // Dummy head node
    Node* tail = new Node(-1, -1); // Dummy tail node

    int cap;                     // Capacity of the LRU Cache
    unordered_map<int, Node*> m; // Map to store key-node pairs

public:
    // Constructor to initialize the cache with a given capacity
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Function to add a new node right after the head
    void addNode(Node* newnode) {
        Node* temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    // Function to delete a node from the doubly linked list
    void deleteNode(Node* delnode) {
        Node* prevv = delnode->prev;
        Node* nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    // Function to get the value of the key if the key exists in the cache
    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int ans = resNode->val;

            m.erase(key);        // Remove the key from the map
            deleteNode(resNode); // Remove the node from the linked list
            addNode(resNode);    // Add the node back right after the head

            m[key] = head->next; // Update map with new position of node
            return ans;          // Return value of the node
        }
        return -1; // If the key does not exist, return -1
    }

    // Function to insert a key-value pair into the cache
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* curr = m[key];
            m.erase(key);     // Remove the existing key from the map
            deleteNode(curr); // Remove the existing node from the linked list
        }

        if (m.size() == cap) {
            // Remove the least recently used key from the map
            m.erase(tail->prev->key);
            // Remove least recently used node from linked list
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value)); // Add the new node right after the head
        m[key] = head->next;           // Update the map with the new node
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */