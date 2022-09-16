#include <bits/stdc++.h>
using namespace std;


struct Node{
    Node* links[26];
    bool flag;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
        return;
    }
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag=true;
        return;
    }
    void makeFalse(){
        flag=false;
        return;
    }
};


class Solution{
        Node* root;
    public:
        Solution(){
            root=new Node();
        }


     // This function will insert the word in the trie
    void insert(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setEnd();
    }


    // This function will search whether the given word can be formed by using two or more words from all the given words.
    bool search(string s,int i,Node* temp){
        if(i==s.length()){
        return temp->isEnd();
        }
        if(temp->isEnd()){
            if(search(s,i,root))
                return true;
        }
        if(temp->containsKey(s[i])){
            return search(s,i+1,temp->get(s[i]));
        }
        else{
            return false;
        }
    }


    // This function is used to set the flag of the word as false.
    void st(string s,int i,Node* temp){
            if(i==s.length()){
                temp->makeFalse();
                return;
            }
            st(s,i+1,temp->get(s[i]));
            return;
        }
        

    static bool cmp(string a,string b){  // Comparator function for sort
        if(a.length()==b.length())
        return a<b;
        return a.length()>b.length();
    }
    
    void longestWord(vector<string>& words) {
        vector<string> ans; 
        for(int i=0;i<words.size();i++){
            ans.push_back(words[i]);
            insert(words[i]);
        }
        sort(ans.begin(),ans.end(),cmp);  // Sorting is done to find the longest word
        // for(int i=0;i<words.size();i++)
        // cout<<ans[i]<<" ";
        string ans1="",ans2="";
        for(int i=0;i<ans.size();i++){
            st(ans[i],0,root); // Used to unmark the the flag of the word because if we didn't unmark the flag then it will always give the longest word as the answer because the flag of the word is true


            // cout<<wordst(ans[i],0,root);
            // cout<<ans[i]<<" ";

            if(search(ans[i],0,root)){ 
                // cout<<"Reach";
                if(ans1.length()==0)
                ans1=ans[i];
                else{
                    // ans2=ans1;
                    ans2=ans[i];
                    break;
                }
            }
            insert(ans[i]);  // Used to mark the flag of the word as true

            // cout<<wordst(ans[i],0,root);
        }

        cout<<ans1<<" "<<ans2<<endl;
        return;
    }
};

int main(){
    Solution st;
    ifstream infile;
    vector<string> ans;  // This vector is used to store all the words from input file.
    infile.open("Input_02.txt");
    if(infile.fail()){
        cout<<"You fail didn't work.";
    }
    else{
        string s;
        while(infile>>s){
            ans.push_back(s);
        }
        infile.close();
        // infile.clear();
        st.longestWord(ans);
    }
    return 0;
}