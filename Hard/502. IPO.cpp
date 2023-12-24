class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         int n = profits.size();
    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        projects[i] = {capital[i], profits[i]};
    }
    sort(projects.begin(), projects.end());

    int idx = 0;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
        while (idx < n && projects[idx].first <= w) {
            pq.push(projects[idx].second);
            idx++;
        }
        if (pq.empty()) {
            break;
        }
        w += pq.top();
        pq.pop();
    }
    return w;
        
    }
};
