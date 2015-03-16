/* Implementation of functions in Herd.h
 * Add brings a new sheep into the herd
 * Remove removes a given sheep from the herd
 */

#include"Herd.h"
#include<algorithm>
#include<vector>
using namespace std;

void Herd::add( Sheep sheep ) {
	group.push_back(sheep);
}

void Herd::remove( Sheep sheep ) {
	vector<Sheep>::iterator ptr;
	ptr = find( group.begin() , group.end() , sheep );

	if (ptr != group.end()) {
		group.erase(ptr);
	}
}
