/**
 * @file parse-log.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-12
 */
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct Log {
    int begin, end;
    int depth;
    Log(int depth_=0, int b=0, int e=0)
        :depth(depth_), begin(b), end(e) {}
};

struct Line {
    string name;
    bool enter;
    int time;
    Line(string str="", bool e=true, int t=0):
        name(str), enter(e), time(t) {}
};

vector<Line> parseFile(const string &file_name);

void Print(const vector<Line> &lines)
{
    vector<string> names;
    unordered_map<int, Log> hash;
    stack<int> s;
    int depth = 0, index = 0;
    for(auto line : lines) {
        if(line.enter) {
            s.push(names.size());
            hash[names.size()] = Log(depth, line.time);
            names.push_back(line.name);
            ++depth;
        }
        else {
            index = s.top(); s.pop();
            hash[index].end = line.time;
            --depth;
        }
    }

    for(int i=0; i<names.size(); ++i) {
        for(int j=0; j<hash[i].depth; ++j)
            cout << "  ";
        cout << names[i] << " " << hash[i].end - hash[i].begin << endl;
    }
}

int main(void)
{
    vector<Line> lines{{"main", true, 0},{"func", true, 1}, {"func", false, 2}, 
        {"dfs", true, 4}, {"dfs", true, 5},{"dfs", true, 6}, 
        {"dfs", false, 7},{"dfs", false, 8}, {"dfs", false, 9},
        {"abs", true, 9},{"abs", false, 10},
        {"main", false, 15},
    };
    Print(lines);
    return 0;
}
