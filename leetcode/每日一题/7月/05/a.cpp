#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class MyCalendar {
public:
    vector<pair<int,int>> a;
    MyCalendar() {

    }
    bool book(int start, int end) {
        if(a.size() == 0){
            a.push_back({start,end});
            return true;
        }else {
            bool ok = true;
            for(auto &c : a){
                int l = c.first;
                int r = c.second;
                //way 1
                // if(start <= l && end > l){
                //     return false;
                // }else if(end >= r && start < r){
                //     return false;
                // }else if(start >= l && end <= r){
                //     return false;
                // }
                //way 2
                // l  r   start  end
                // end <= l || start >= r
                // end > l && start < r
                if(end > l && start < r)return false;
            }
            a.push_back({start,end});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */