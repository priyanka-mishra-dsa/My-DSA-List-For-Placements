class Solution {
public:
    Node* cloneGraph(Node* node) {
        //edge case
        if(node==NULL)
        return NULL;
        //solve using bfs
        //for bfs we need queue and visited arr(unordered_map)
        unordered_map<Node*,Node*>m;
        queue<Node*>q;
        //clone the node
        Node*cloneNode=new Node(node->val);
        //mark as visited
        m[node]=cloneNode;
        //push into queue
        q.push(node);
        while(!q.empty())
        {
            Node* currNode=q.front();
            q.pop();
            //clone neig node of current node
            for(int i=0;i<currNode->neighbors.size();i++)
            {
                Node* neig=currNode->neighbors[i];
                //clone neig node
                Node* neigClone=new Node(neig->val);
                //check visited or not
                if(m.count(neig)==0)
                {
                    //mark as visited
                    m[neig]=neigClone;
                    //push into queue
                    q.push(neig);
                }
                 //connect clone nodes together
                m[currNode]->neighbors.push_back(m[neig]);          
            }
        }
        //return first node of cloned graph
        return m[node];
    }
};
