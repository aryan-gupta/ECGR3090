/*From interviewbit.com - Merge Intervals
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary). You may assume that the intervals were initially sorted according to their start times. 
Example 1:  Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
Example 2: Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. Make sure the returned intervals are also sorted.


Use the following test program -*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace me {
	template <typename T>
	inline T min (T a, T b) {
		return (a < b)? a : b;
	} 
	
	template <typename T>
	inline T max (T a, T b) {
		return (a > b)? a : b;
	}
}

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval); // To be implemented


int main()
{
    Interval interval1(1,3), interval2(6,9);
    vector<Interval> intervalSet_in1 = {interval1, interval2}; // C++11 initialization
    cout << "Interval set prior to inserting [2,5]" << endl;
    for(auto ele: intervalSet_in1) { // C++11 range loops
        cout << ele.start << " " << ele.end << endl;
    }
    vector<Interval> intervalSet_out1 = insert(intervalSet_in1, Interval(2,5));
    cout << "Interval set after inserting [2,5]" << endl;
    for(auto ele: intervalSet_out1) {
        cout << ele.start << " " << ele.end << endl;
    }
    cout << endl;
    Interval interval3(1,2), interval4(3,5), interval5(6,7), interval6(8,10), interval7(12,16);
    vector<Interval> intervalSet_in2 = {interval3, interval4, interval5, interval6, interval7};
    cout << "Interval set prior to inserting [4,9]" << endl;
    for(auto ele: intervalSet_in2) { // C++11 range loops
        cout << ele.start << " " << ele.end << endl;
    }
    vector<Interval> intervalSet_out2 = insert(intervalSet_in2, Interval(4,9));
    cout << "Interval set after inserting [4,9]" << endl;
    for(auto  ele: intervalSet_out2) {
        cout << ele.start << " " << ele.end << endl;
    }
    
    return 0;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	if (newInterval.end < intervals[0].start) { // Interval before all
		intervals.insert(intervals.begin(), newInterval);
		return intervals;
	} else if (newInterval.start > (--intervals.end())->end) { // interval after all
		intervals.push_back(newInterval);
		return intervals;
	}
	
	Interval& ni = newInterval;
	auto i = intervals.begin();
	
	// Expand intervals
	for (; i != intervals.end(); ++i) {
		if (i != --intervals.end() and i->end < ni.start and (i + 1)->start > ni.end) { // if intervals is between 2 intervals
			intervals.insert(++i, ni);
			return intervals;
		}
		
		if (ni.start > i->end) { // if interval is below the new interval
			continue;
		}
		
		if (i->start > ni.end) { // if interval is greater than new interval
			continue;
		}
		
		i->start = me::min(i->start, ni.start); // new interval is overlapping current interval, expand it
		i->end   = me::max(i->end, ni.end);
		
		if (i != intervals.begin()) {
			auto prev = i - 1;
			if (i->start < prev->end) { // current interval is overlapping prev interval
				prev->start = me::min(i->start, prev->start); // squash it into one interval
				prev->end   = me::max(i->end, prev->end);
				intervals.erase(i--);                     // and remove the other one
			}
		}
	}
	
	return intervals;
}