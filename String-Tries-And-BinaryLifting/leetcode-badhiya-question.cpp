struct Node {
	Node *links[10];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - '0'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - '0'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - '0'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}
    
    int getCommonPrefix(string word) {
        Node *node = root;
        int i=0;
        int nn = word.size();
        while(i<nn) {
            if(!node->containKey(word[i])) {
                return i;
            }
            node = node->get(word[i]);
            i++;
        }
        return i;
    }

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        if(n<m) {
            return longestCommonPrefix(arr2,arr1);
        }
        
        Trie trie;
        for(int i=0;i<n;i++){
            string w = to_string(arr1[i]);
            trie.insert(w);
        }
        
        int maxx = 0;
        for(int i=0;i<m;i++){
            int temp = trie.getCommonPrefix(to_string(arr2[i]));
            maxx = max(maxx, temp);
            // cout<<"temp = "<<temp<<"\n";
        }
        
        return maxx;
    }
};
