#include <vector>
#include "207_course_schedule.h"

#define NOT_VISITED 0
#define PROCESSING 1
#define PROCESSED 2

using namespace std;

bool dfs(vector<vector<int>> &graph, int n, vector<int> &visited) {
    if (visited[n] == PROCESSING) {
        return false;
    }
    visited[n] = PROCESSING;

    for (int o : graph[n]) {
        if (visited[o] != PROCESSED) {
            bool res = dfs(graph, o, visited);
            if (!res) {
                return false;
            }
        }
    }

    visited[n] = PROCESSED;
    return true;
}

bool dfs_loop(vector<vector<int>> graph, vector<int> visited) {
    for (int i = 0; i < graph.size(); i++) {
        if (visited[i] == NOT_VISITED) {
            bool res = dfs(graph, i, visited);
            if (!res) {
                return false;
            }
        }
    }

    return true;
}


bool CourseScheduleSolution::canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);

    for (int i = 0; i < prerequisites.size(); i++) {
        pair<int, int> edge = prerequisites[i];
        graph[edge.second].push_back(edge.first);
    }

    vector<int> visited(numCourses, NOT_VISITED);
    return dfs_loop(graph, visited);
}