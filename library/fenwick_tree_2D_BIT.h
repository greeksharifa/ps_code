#include "sharifa_header.h"

class FenwickTree2D {
public:
    int size;
	vector<vector<long long> > data;

    FenwickTree2D(int _N){
        size = _N;
        data = vector<vector<long long> >(size + 1, vector<long long>(size + 1));
    }

	void update(int x, int y, int val) {
		ll dval = val - sum(x,y,x,y);
		int yy;
		while (x <= size) {
			yy = y;
			while (yy <= size){
                data[x][yy] += dval;
                yy += yy&-yy;
            }
			x += x&-x;
		}
	}
	ll sum(int x, int y) {
		ll ret = 0;
		int yy;
		while (x) {
			yy = y;
			while (yy){
                ret += data[x][yy];
                yy -= yy&-yy;
            }
			x -= (x&-x);
		}
		return ret;
	}
	inline ll sum(int x1, int y1, int x2, int y2) {
		return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
	}
};
