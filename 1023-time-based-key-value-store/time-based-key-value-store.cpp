class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";

        vector<pair<int, string>>& v = mp[key];

        
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i].first <= timestamp) {
                return v[i].second;
            }
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */