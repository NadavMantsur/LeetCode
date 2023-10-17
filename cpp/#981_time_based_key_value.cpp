#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
public:

    TimeMap() 
    {}
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) {
            return "";
        }
        
        const vector<pair<int, string>>& timestamps = data[key];
        int left = 0;
        int right = timestamps.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (timestamps[mid].first == timestamp) {
                return timestamps[mid].second;
            } 
            else if (timestamps[mid].first < timestamp) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        
        // In case of the timestamp does not exist - return the former or ""
        if (left > 0) {
            return timestamps[left - 1].second;
        }
        
        return "";
    }

private:
    unordered_map<string, vector<pair<int, string>>> data;
};


int main() {
    TimeMap* obj = new TimeMap();
    obj->set("foo", "bar", 1);
    cout << obj->get("foo", 1) << endl; // Output: "bar"
    cout << obj->get("foo", 3) << endl; // Output: "bar"
    obj->set("foo", "bar2", 4);
    cout << obj->get("foo", 4) << endl; // Output: "bar2"
    cout << obj->get("foo", 5) << endl; // Output: "bar2"
    return 0;
}
