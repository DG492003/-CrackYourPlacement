// Approach -> O(1)

// we maintain vector and map of int & set to maintain complexity O(1)

// insert
//     if element present then just insert it in both  

// remove
//     swap element from pos to last to show we can delete in O(1) we get pos from map as we delete first occurence that why we choose set which stores in sorted order

class RandomizedCollection {
private:
    // we want most of the opeartions in a O(1) that why we use both vector and
    // map

    // vector have O(1) complexity in indexing as well as inserting
    vector<int> vect;
    // idx to track indexes and total size
    int idx = 0;
    // unordered_map have O(1) complexity in inserting as well as deletion
    // map of int , set because it is given it is a multiset
    // we store val with all their indexes which must be in a sorted order to
    // retrieve & delete value
    unordered_map<int, set<int>> umap;

public:
    RandomizedCollection() {
        // reset the data structures
        int idx = 0;
        vect.clear();
        umap.clear();
    }

    bool insert(int val) {
        // insert the values in data structures
        vect.push_back(val);
        // vect.size() - 1 this gives the index of all value which store in a
        // set
        umap[val].insert(vect.size() - 1);

        // if val is present then return true else false
        if (umap[val].size() == 1)
            return true;

        return false;
    }

    bool remove(int val) {
        // to remove first find the value
        auto it = umap.find(val);
        // if val is presenet
        if (it != umap.end()) {
            // find the position as it is given we want to delete first
            // occurence
            auto pos = *it->second.begin();
            // delete from the map
            it->second.erase(it->second.begin());

            // swap the value with last of a vector
            vect[pos] = vect.back();
            // update the map with new changes
            umap[vect.back()].insert(pos);
            // after that delete it
            umap[vect.back()].erase(vect.size() - 1);
            vect.pop_back();

            if (it->second.size() == 0)
                umap.erase(it);

            return true;
        }
        return false;
    }

    int getRandom() { return vect[rand() % vect.size()]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */