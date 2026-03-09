class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source == target) return 0;

        unordered_map<int, vector<int>> stopToBus;

        int n = routes.size();

        for(int bus = 0; bus < n; bus++) {
            for(int stop : routes[bus]) {
                stopToBus[stop].push_back(bus);
            }
        }

        queue<int> q;
        unordered_set<int> visitedStops;
        vector<int> visitedBus(n, 0);

        q.push(source);
        visitedStops.insert(source);

        int buses = 0;

        while(!q.empty()) {

            int sz = q.size();
            buses++;

            for(int i=0;i<sz;i++) {

                int stop = q.front();
                q.pop();

                for(int bus : stopToBus[stop]) {

                    if(visitedBus[bus]) continue;
                    visitedBus[bus] = 1;

                    for(int nextStop : routes[bus]) {

                        if(nextStop == target)
                            return buses;

                        if(!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};