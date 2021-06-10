class MyCalendar {
    //O(bookcalls * (bookcalls +1))/2
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> curr = {start, end};

        for(pair<int, int> dz : st) {
            if(intersects(dz, curr)) return false;
        }
        st.insert(curr);
       
        return true;
    }
    private: bool intersects(pair<int, int> p1, pair<int, int> p2) {
       return (p1.first >= p2.first  && p1.first < p2.second) || (p2.first >= p1.first
                                                                 && p2.first < p1.second);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */