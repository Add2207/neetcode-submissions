class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {} 
    };

    Node *head, *tail;

    unordered_map<int, Node*> cache;

    int capacity;

    void removeNode(Node* node){
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        if(node->next) node->next->prev = node->prev;
        else tail = node->prev;
    }

    void addNodetoFront(Node *node){
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = head;
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {
        
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        Node *node = cache[key];
        removeNode(node);
        addNodetoFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){ 
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addNodetoFront(node);
        } else {
            if (cache.size() >= capacity){
                cache.erase(tail->key);
                Node *temp = tail;
                removeNode(tail);
                delete temp;
            }

            Node *newNode = new Node(key, value);
            addNodetoFront(newNode);
            cache[key] = newNode;
        }
    }
};
