/* A herd of sheep which contains a vector of sheep.
 * Tracks the positions of each sheep in the surrounding environment.
 */

#ifndef HERD_H
#define HERD_H

#include"Sheep.h"
#include<vector>
using namespace std;

class Herd {
	public:
		void add( Sheep ); // Add a sheep to the group vector
		void remove( Sheep ); // Remove a particular sheep from the group vector
	private:
		vector<Sheep> group;
};
#endif
