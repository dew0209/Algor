#include <iostream>
#include <vector>

using namespace std;

class MagicDictionary {
public:
    vector<string> d;
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        d = dictionary;
    }
    
    bool search(string searchWord) {
        bool ok = false;
        for(auto &c : d){
            if(c.length() == searchWord.length()){
                int diff = 0;
                for(int i = 0;i < searchWord.length();i++){
                    if(searchWord[i] != c[i]){
                        diff++;
                    }
                }
                if(diff == 1){
                    ok = true;
                }
            }
        }
        return ok;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */