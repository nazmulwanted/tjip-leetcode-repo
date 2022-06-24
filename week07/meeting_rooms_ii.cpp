//Time complexity: O(N), N = number of intervals
//Space complexity: O(N), N = number of intervals

int minMeetingRooms(vector<vector<int>> &intervals){
    map<int, int> busy_rooms;
    for(auto interval: intervals){
        busy_rooms[interval[0]]++;
        busy_rooms[interval[1]]--;
    }
    int curr_busy_rooms = 0, min_busy_rooms = 0;
    for(auto busy_room: busy_rooms){
        curr_busy_room += busy_room.second;
        min_busy_room = max(min_busy_rooms, curr_busy_room);
    }
    return min_busy_rooms;
}
