class LRUCache{
public:
    //双向链表实现，用哈希表来加速key的搜
    LRUCache(int capacity_): size(0), capacity(capacity_) {
        assert(capacity > 0);
        rear = new Node;
        rear->key = INT_MAX;
        rear->val = -1;
        rear->prev = rear->next = rear;
    }
    
    int get(int key) {
        if(keyMap.find(key) != keyMap.end()) {
            Node *cur = keyMap[key];
            //move cur to the front
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            
            cur->next = rear->next;
            rear->next->prev = cur;
            rear->next = cur;
            cur->prev = rear;
            return cur->val;
        }
        else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if(get(key) == -1) {
            Node *node = new Node;
            node->key = key;
            node->val = value;
            keyMap[key] = node;
            
            node->next = rear->next;
            rear->next->prev = node;
            rear->next = node;
            node->prev = rear;
            ++size;
            
            invalidate();
        }
        else {
            rear->next->val = value;
        }
    }
private:
    struct Node { 
        int key, val;
        Node *prev, *next;
    };
    Node *rear;
    int size, capacity;
    unordered_map<int, Node*> keyMap;
    
    void invalidate() {
        if(size > capacity) {
            --size;
            //delete the last node
            Node *node = rear->prev;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            keyMap.erase(keyMap.find(node->key));
            delete node;
        }
    }
};
