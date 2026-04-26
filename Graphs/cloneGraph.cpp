class Solution {
public:
    Node* cloneGraph(Node* node) {
        //give only one node of graph
        //make clone of only that node of graph which have same value but different address
        //for making clone of neig node ,you need to travarse on given graph neig node using bfs/dfs
        //take a map to store visited node(jiska clone bana liya hai)
        if(node==NULL)
        return NULL;
        unordered_map<Node*,Node*>m;//original node,clone node
        Node*cloneNode=new Node(node->val);//clone of given node
        //after making clone mark as visited
        m[node]=cloneNode;
        queue<Node*>q;
        q.push(node);
        while(!q.empty())
        {
            Node*temp=q.front();
            q.pop();
            //visit its neig node
            for(int i=0;i<temp->neighbors.size();i++)
            {
                Node*neig=temp->neighbors[i];
                //if neig node is not clone(not visited)
                if(m.count(neig)==0)//not present in the map
                {
                    //clone (create node)
                    Node*cloneNeig=new Node(neig->val);
                    //mark as visited
                    m[neig]=cloneNeig;
                    //push in the queue(always push original node because we apply bfs on original node)
                    q.push(neig);
                }
                //make connection b/w cloneNode & cloneNeig node
                //m[temp]==cloneNode
                m[temp]->neighbors.push_back(m[neig]);
            }
        }
        //return starting node of clone graph
        //m[node]=cloneNode(return)
        return m[node];
    }
};
