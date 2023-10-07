#include <iostream>
#include <vector>
#include <algorithm> //upper_bound
#include <climits> //INT_MAX

using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) {
        updates.resize(length);
        curSnap = 0;
    }

    void set(int index, int val) {
        if (!updates[index].empty() && updates[index].back().first == curSnap)
            updates[index].back().second = val; // for saving the last update (saving memory)
        else
            updates[index].push_back({curSnap, val});
    }

    int snap() {
        ++curSnap;
        return curSnap - 1;
    }

    int get(int index, int snap_id) {
        // Iterate through the updates for the specified index.
        for (int i = updates[index].size() - 1; i >= 0; i--) {
            if (updates[index][i].first <= snap_id) {
                return updates[index][i].second; // Return the value when snap_id is greater or equal.
            }
        }
        return 0; // Return 0 if there are no relevant updates.
    }

    // more fast way is to use the upper_bound, but also more difficult to understand
    // int get(int index, int snap_id) {
    //     int idx = upper_bound(updates[index].begin(), updates[index].end(), make_pair(snap_id, INT_MAX)) - updates[index].begin();
    //     if (idx == 0){
    //         return 0;
    //     }

    //     return updates[index][idx - 1].second;
    // }

private:
    vector<vector<pair<int, int>>> updates;
    int curSnap;
};

int main() {
    SnapshotArray* obj = new SnapshotArray(1); // Create a SnapshotArray object with length 1.

    cout << "Constructor: SnapshotArray(1)" << endl;

    obj->set(0, 4); // Set index 0 with a value of 4.
    cout << "set(0, 4)" << endl;

    obj->set(0, 16); // Update the value at index 0 to 16.
    cout << "set(0, 16)" << endl;

    obj->set(0, 13); // Update the value at index 0 to 13.
    cout << "set(0, 13)" << endl;

    int snap_id1 = obj->snap(); // Take a snapshot, snap_id = 0.
    cout << "snap_id1: " << snap_id1 << endl;

    int val1 = obj->get(0, 0); // Get the value at index 0 from snap_id 0 (should return 13).
    cout << "get(0, 0) = " << val1 << endl;

    int snap_id2 = obj->snap(); // Take another snapshot, snap_id = 1.
    cout << "snap_id2: " << snap_id2 << endl;

    delete obj; // Don't forget to delete the object when done.

    return 0;
}