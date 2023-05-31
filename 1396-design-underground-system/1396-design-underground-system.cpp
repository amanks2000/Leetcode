class UndergroundSystem {
public:
    unordered_map<int, unordered_map<string, int>> mp;
    unordered_map<string, unordered_map<string, double>> time, count;
    unordered_map<int, string> checkInStation;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id][stationName] = t;
        checkInStation[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        string inStation = checkInStation[id];
        int timeTaken = t - mp[id][inStation];

        mp[id][stationName] = t;
        time[inStation][stationName] += timeTaken;
        count[inStation][stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return time[startStation][endStation]/count[startStation][endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */