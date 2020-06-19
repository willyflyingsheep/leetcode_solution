class UndergroundSystem {
private:
    // in_reports
    // key: person id
    // value: {startStation, enter_time}
    unordered_map<int, pair<string, int>> in_reports;
    
    // histories
    // key: startStation:endStation
    // value: {sum_of_times, counts}
    unordered_map<string, pair<double, int>> histories;
    
public:
    UndergroundSystem() {
        in_reports.reserve(20000);
        histories.reserve(20000);
    }
    
    void checkIn(int id, string stationName, int t) {
        in_reports[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        // Someone is missing @_@
        // Shall we call jingchashushu
        if (!in_reports.count(id)) {
            return;
        }
        
        auto in_record = in_reports[id];
        string route = in_record.first + ":" + stationName;
        int time_cost = t - in_record.second;
        
        histories[route].first += time_cost;
        histories[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + ":" + endStation;
        if (!histories.count(route)) {
            return 0;
        }
        return histories[route].first / histories[route].second;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */