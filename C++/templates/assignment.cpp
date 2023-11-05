#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <limits>

using namespace std;

template<typename K, typename V>

class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	map<K,V> m_map;
    public:
        // constructor associates whole range of K with val
        interval_map(V const& val): m_valBegin(val) {}
        interval_map(vector<pair<K, V>> items){
            for(auto i: items){
                m_map.insert(make_pair(i.first, i.second));
            }
        }
        // interval_map( V const& val) {
        //     m_map.insert(m_map.end(), make_pair(numeric_limits<K>::lowest(),val));
        // }

        // Assign value val to interval [keyBegin, keyEnd).
        // Overwrite previous values in this interval.
        // Conforming to the C++ Standard Library conventions, the interval
        // includes keyBegin, but excludes keyEnd.
        // If !( keyBegin < keyEnd ), this designates an empty interval,
        // and assign must do nothing.
        void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
            if (!(keyBegin < keyEnd))
                return;
            // m_map[keyBegin]  = val;
            auto before_begin_bound = m_map.lower_bound(keyBegin);
            if (before_begin_bound != m_map.begin()) {
                --before_begin_bound;
            }
            auto insert_res = before_begin_bound->second == val ?
                before_begin_bound : m_map.insert_or_assign(before_begin_bound, keyBegin, val);

            auto end_interval = m_map.lower_bound(keyEnd);

            if (end_interval != m_map.end() && end_interval->second == val)
                end_interval++;

            insert_res++;
            m_map.erase(insert_res, end_interval);

            if (end_interval == m_map.end())
                this->assign(keyEnd, std::numeric_limits<K>::max(), before_begin_bound->second);
            else
                this->assign(keyEnd, end_interval->first, before_begin_bound->second);
           
        }

        // look-up of the value associated with key
        V const& operator[]( K const& key ) const {
            auto it=m_map.upper_bound(key);
            if(it==m_map.begin()) {
                return m_valBegin;
            } else {
                return (--it)->second;
            }
        }

        void print(){
            for(auto key: m_map){
                cout << key.first << " -> " << key.second << endl;
            }
        }

        // interval_map<K, V>* operator= (initializer_list<pair<K, V>> items){
        interval_map<K, V>* operator= (vector<pair<K, V>> items){
            for(auto i: items){
                m_map.insert(make_pair(i.first, i.second));
            }
            return *this;
        }


        
};


// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

void IntervalMapTest(){
    interval_map<int, char> dict{'A'};
    dict.assign(8, 12, 'A');
    dict.assign(2, 12, 'B');
    dict.assign(2, 12, 'C');
    dict.assign(5, 12, 'D');
    dict.assign(4, 10, 'A');
    dict.assign(4, 12, 'E');
    dict.assign(8, 13, 'G');
    dict.assign(6, 9, 'L');
    dict.print();
}



int main(){
    IntervalMapTest();
    return 0;
}
