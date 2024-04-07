题目链接：https://leetcode.cn/problems/throne-inheritance/description/?envType=daily-question&envId=2024-04-07


思路：前序遍历的想法

class ThroneInheritance {
public:
    unordered_map<string,vector<string>> edges;
    unordered_set<string> dead;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        edges[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        function<void(const string&)> preorder = [&](const string& name){
            if(!dead.count(name)){
                ans.push_back(name);
            }
            if(edges.count(name)){
                for(const string& childName: edges[name]){
                    preorder(childName);
                }
            }
        };
        preorder(king);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */