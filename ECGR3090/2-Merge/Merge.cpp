/*From interviewbit.com - Merge Intervals
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary). You may assume that the intervals were initially sorted according to their start times. 
Example 1:  Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
Example 2: Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. Make sure the returned intervals are also sorted.


Use the following test program -*/

/*	Pesudo

find where lower digit fits
find last digit fits
squash all intervals in between

*/

 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


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
    Interval interval3(1,3), interval4(5,7), interval5(10,12), interval6(15,16), interval7(19,21);
    vector<Interval> intervalSet_in2 = {interval3, interval4, interval5, interval6, interval7};
    cout << "Interval set prior to inserting [4,9]" << endl;
    for(auto ele: intervalSet_in2) { // C++11 range loops
        cout << ele.start << " " << ele.end << endl;
    }
    vector<Interval> intervalSet_out2 = insert(intervalSet_in2, Interval(-1,6));
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
	
	auto i = intervals.begin();
	bool remove = false;
	
	if (newInterval.start < i->start) { // The new start is before first
		i->start = newInterval.start;
		remove = true;
	}
	
	for ( ; i != intervals.end(); ++i) {
		if (i != intervals.begin() and newInterval.end < i->start and newInterval.start > (i - 1)->end) { // Whole interval is inbetween
			intervals.insert(i, newInterval);
			break;
		}
	
		if (remove and newInterval.end < i->end and newInterval.end > i->start) { // found end num in an interval
			// (i - 1)->end = i->end;
			// intervals.erase(i);
			break;
		}
		
		if (remove and newInterval.end <= (i + 1)->start and newInterval.end > i->end) { // found end between two intervals
			i->end = newInterval.end;
			break;
		}
		
		if (remove) {
			intervals.erase(i--); // subtract one to account shift in one
			continue;
		}
		
		if (!remove and newInterval.start < i->start and newInterval.start > (i - 1)->end) { // found start num inbetween two intervals
			(i--)->start = newInterval.start; // pull start to new start and recheck for end condition
			remove = true;
			continue;
		}
		
		if (!remove and newInterval.start < i->end and newInterval.start > i->start) { // found start num in an interval
			remove = true;
			continue;
		}
	}
	
	return intervals;
}