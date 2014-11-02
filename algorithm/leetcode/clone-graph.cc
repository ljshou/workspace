/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> node_map;
        queue<UndirectedGraphNode*> q;
        UndirectedGraphNode *cur(nullptr), *new_node(nullptr);
        
        new_node = new UndirectedGraphNode(node->label);
        node_map[node] = new_node;
        q.push(node);
        
        
        while(!q.empty()) {
            cur = q.front(); q.pop();
            for(auto x: cur->neighbors) {
                if(node_map.find(x) != node_map.end()) {
                    //visited
                    node_map[cur]->neighbors.push_back(node_map[x]);
                }
                else {
                    //not visited
                    new_node =new UndirectedGraphNode(x->label);
                    node_map[x] = new_node;
                    node_map[cur]->neighbors.push_back(node_map[x]);
                    q.push(x);
                }
            }
        }
        return node_map[node];
    }
};
