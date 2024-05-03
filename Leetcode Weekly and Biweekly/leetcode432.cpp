class Node{
    public:
    int freq;
    unordered_set<string>data;
    Node* prev;
    Node* next;

    Node(int f) {
        data.clear();
        freq = f;
        prev = nullptr;
        next = nullptr;
    }

    void add(string &s){
        data.insert(s);
    }

    void remove(string &s){
        data.erase(s);
    }
};

class AllOne {
public:
    unordered_map<string,int> mp1; // key -> count
    unordered_map<int, Node*> mp2; // count-> node address
    int sz;
    Node *head, *tail;
    AllOne() {
        sz = 0;
        head = new Node(INT_MIN);
        tail = new Node(INT_MAX);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if(mp1.find(key) == mp1.end()) {
            mp1[key]++;
            if(mp2.find(1) == mp2.end()) {
                Node* newNode = new Node(1);
                // newNode->data.insert(key);
                // cout<<"head\n";
                addNode(newNode, head);
                mp2[1] = newNode;
                sz++;
            }
            mp2[1]->data.insert(key);
        }else {
            int x = mp1[key];
            // add the key to the next pointer
            int y = x+1;
            if(mp2.find(y)==mp2.end()) {
                Node* newNode = new Node(y);
                addNode(newNode, mp2[x]);
                mp2[y] = newNode;
                sz++;
            }
            mp2[y]->data.insert(key);
            mp1[key]++; // increase the counter


            // remove the key from the previous bucket
            mp2[x]->data.erase(key);
            if(mp2[x]->data.size()==0) {
                deleteNode(mp2[x]);
                mp2.erase(x);
                sz--;
            }            
        }
    }

    void deleteNode(Node* temp) {
        Node* prevv = temp->prev;
        Node* nextt = temp->next;
        prevv->next = nextt;
        nextt->prev = prevv;
        delete temp;
    }

    void addNode(Node* temp, Node* p) {
        Node* nextt = p->next;
        p->next = temp;
        temp->next = nextt;
        temp->prev = p;
        nextt->prev = temp;
    }
    
    void dec(string key) {
        // int x = mp1[key];
        // v[x].remove(key);
        // if(x==minn && v[x].data.size()==0) {
        //     minn = INT_MAX;
        // }
        // if(x==maxx && v[x].data.size()==0) {
        //     maxx = INT_MIN;
        // }
        // mp1[key]--;
        // if(mp1[key]==0) {
        //     mp1.erase(key);
        // } else {
        //     v[x-1].add(key);
        //     minn = min(minn, mp1[key]);
        //     maxx = max(maxx, mp1[key]);
        // }
        int x = mp1[key];
        mp1[key]--;

        int y = x-1;
        if(y>0 && mp2.find(y) == mp2.end()) {
            Node* newNode = new Node(y);
            addNode(newNode, mp2[x]->prev);
            mp2[y] = newNode;
            sz++;
        }
        if(y>0) mp2[y]->data.insert(key);

        // remove the key from the previous bucket
        mp2[x]->data.erase(key);
        if(mp2[x]->data.size()==0) {
            deleteNode(mp2[x]);
            mp2.erase(x);
            sz--;
        }

        if(mp1[key]==0){
            mp1.erase(key);
        }
    }
    
    string getMaxKey() {
        if(sz==0) return "";
        Node* maxBucket = tail->prev;
        return *(maxBucket->data.begin());
    }
    
    string getMinKey() {
        if(sz==0) return "";
        Node* minBucket = head->next;
        return *(minBucket->data.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
