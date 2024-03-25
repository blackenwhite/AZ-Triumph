// leetcode 460 lfu and lru cache --multilevel
class Node{
public:
    int key;
    int val;
    int cnt = 0;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(){}

    Node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};

class List{
public:
    Node* head;
    Node* tail;
    int sz;
    
    List() {
        head = new Node(-1,-1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        sz = 0;
    }

    void addNode(Node* node) {
        // add node to the start
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        sz++;
    }

    void removeNode(Node* node) {
        Node* prevv = node->prev;
        Node* nextt = node->next;
        
        prevv->next = nextt;
        nextt->prev = prevv;

        node->next = nullptr;
        node->prev = nullptr;

        --sz;
    }

    Node* removeLast() {
        Node* evict = tail->prev;
        removeNode(evict);
        return evict;
    }

    bool isEmpty() {
        return sz==0;
    }
};

class LFUCache {
public:
    int cap;
    map<int,List> freqList; // freq, LL 
    unordered_map<int,Node*> mp;
    int curSize;

    LFUCache(int capacity) {
        cap = capacity;
        curSize = 0;
    }

    void printCache() {
        cout<<"----- printing cache -----\n";
        for(auto it:freqList) {
            cout<<it.first<<" -> ";

        }
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) {
            return -1;
        }
        Node* node = mp[key];
        int result = node->val;
        int fr = node->cnt;
        freqList[fr].removeNode(node);
        if(freqList[fr].isEmpty()) freqList.erase(fr);
        node->cnt++;
        freqList[node->cnt].addNode(node);
        return result;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(mp.find(key)==mp.end()) {
            if(curSize==cap){
                // auto minf = *freqList.begin().first;
                cout<<"Out of memory, evicting...\n";
                int minf = freqList.begin()->first;
                Node* evict = freqList[minf].removeLast();
                int ek = evict->key;
                cout<<" evicted "<<ek<<"\n";
                
                // free(evict);
                mp.erase(ek);
                if(freqList[minf].isEmpty()) freqList.erase(minf);
                --curSize;
            }
            Node* newNode = new Node(key,value);
            newNode->cnt = 1;
            mp[key] = newNode;
            freqList[newNode->cnt].addNode(newNode);
            curSize++;
        } else {
            Node* node = mp[key];
            int fr = node->cnt;

            freqList[fr].removeNode(node);
            if(freqList[fr].isEmpty()) freqList.erase(fr);
            node->cnt++;
            node->val = value;
            freqList[node->cnt].addNode(node);
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
