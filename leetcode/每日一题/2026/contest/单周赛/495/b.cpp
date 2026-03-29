struct CompareSecond {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if(a.first != b.first){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};
class EventManager {
public:
    priority_queue<pair<int,int>,vector<pair<int, int>>,CompareSecond> maxHeap;
    map<int,int> cnt;
    map<int,int> st;
    
    
    EventManager(vector<vector<int>>& events) {
        int n = events.size();
        if(n){
            for(int i = 0;i < n;i++){
                maxHeap.push({events[i][1],events[i][0]});
                cnt[events[i][0]] = events[i][1];
            }
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(cnt[eventId] != newPriority){
            cnt[eventId] = newPriority;
            maxHeap.push({newPriority,eventId});
        }
        
    }
    
    int pollHighest() {
        while(maxHeap.size()){
            pair<int,int> t = maxHeap.top();
            //cout << t.first << " --- " << t.second << endl;
            maxHeap.pop();
            if(cnt[t.second] == t.first && !st[t.second]){
                st[t.second] = true;
                return t.second;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */