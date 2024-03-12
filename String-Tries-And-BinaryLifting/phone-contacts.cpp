// GFG Phone contacts HARD
// User function Template for C++

class Solution{
public:
struct Node{
    Node*a[26];
    bool is;
    Node(){
        for(int i=0;i<26;i++)a[i]=0;
        is=0;
    }
};
void insert(string s,Node*root){
    for(auto i:s){
        if(!root->a[i-'a'])
        root->a[i-'a']=new Node();
        root=root->a[i-'a'];
        
    }
    root->is=1;
}
void make(string s,Node*root,vector<string>&v){
    if(!root)return ;
    if(root->is){
        v.push_back(s);
    }
    for(int i=0;i<26;i++){
        char ch='a';
        ch=ch+i;
        make(s+ch,root->a[i],v);
    }
    
    
    
}

    vector<vector<string>> displayContacts(int n, string a[], string s)
    {
        Node*root=new Node();
        for(int i=0;i<n;i++ )insert(a[i],root);
        
        vector<vector<string>> ans;
        string s1="";
        for(auto i:s){
            s1+=i;
            if(root)
            root=root->a[i-'a'];
            vector<string>v;
            make(s1,root,v);
            if(!v.size())v.push_back("0");
            ans.push_back(v);
            
        }
        return ans;
        
        // code here
    }
};
