class MyCalendarTwo {
public:

    vector<pair<int,int>> bookings;
    vector<pair<int,int>> overlaps;

    MyCalendarTwo() {
        
    }

    bool book(int start, int end) {

        // check triple booking
        for(auto &o : overlaps){
            if(max(start,o.first) < min(end,o.second))
                return false;
        }

        // record new overlaps
        for(auto &b : bookings){

            int l = max(start,b.first);
            int r = min(end,b.second);

            if(l < r)
                overlaps.push_back({l,r});
        }

        bookings.push_back({start,end});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */