// Time complexity: O(N), N = number of points on the plane.
// Space complexity: O(N)

map<pair<int, int>, int> points;

DectectSquares{
    points.clear();
}

void add(vector<int> point){
    int x = point[0];
    int y = point[1];
    points[{x, y}]++;
}

int count(vector<int> qpoint){
    int total = 0;
    for(auto point: points){
        int x2 = qpoint[0];
        int y2 = qpoint[1];
        int x4 = point.first.first;
        int y4 = point.first.second;

        if(x2 == x4 || (abs(x2 - x4) != abs(y2 - y4))) continue;
        if(points.count({x4, y2}) && points.count({x2, y4})){
            total += points[{x4, y2}] * points[{x2, y4}] * point.second;
        }
    }
    return total;
}
