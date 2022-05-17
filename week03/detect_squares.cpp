// Time complexity: O(N), N = number of points on the plane.
// Space complexity: O(N)

unordered_map<long long, int> points;
int BASE = 1000000007;

long long getSingleValue(pair<int, int> p){
    return (1LL * p.first * BASE) + p.second;
}

DectectSquares{
    points.clear();
}

void add(vector<int> point){
    int x = point[0];
    int y = point[1];
    points[getSingleValue({x, y})]++;
}

int count(vector<int> qpoint){
    int total = 0;
    for(auto point: points){
        int x2 = qpoint[0];
        int y2 = qpoint[1];
        int x4 = point.first / BASE;
        int y4 = point.first % BASE;
        long long value_x4y2 = getSingleValue({x4, y2});
        long long value_x2y4 = getSingleValue({x2, y4});

        if(x2 == x4 || (abs(x2 - x4) != abs(y2 - y4))) continue;
        if(points.count(value_x4y2) && points.count(value_x2y4)){
            total += points[value_x4y2] * points[value_x2y4] * point.second;
        }
    }
    return total;
}
