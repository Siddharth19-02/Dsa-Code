/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool find(vector<vector<int>>& grid,int rowStart,int rowEnd,int columnStart,int columnEnd)
    {
        for(int i = rowStart;i<rowEnd;i++)
        {
            for(int j = columnStart;j<columnEnd;j++)
            {
                if(grid[i][j]!=grid[rowStart][columnStart])
                    return false;
            }
        }
        return true;
    }
    
    Node* ConstructQuadTree(vector<vector<int>>& grid,int rowStart,int rowEnd,int columnStart,int columnEnd)
    {   
       Node* currNode = new Node();
       
        if(find(grid,rowStart,rowEnd,columnStart,columnEnd))
        {
            currNode->isLeaf = true;
            currNode->val = grid[rowStart][columnStart];
            return currNode;
        }
        
        int column = (columnEnd+columnStart)/2;
        int row = (rowEnd+rowStart)/2;
        
        currNode->topLeft = ConstructQuadTree(grid,rowStart,row,columnStart,column);
        currNode->topRight = ConstructQuadTree(grid,rowStart,row,column,columnEnd);
        currNode->bottomLeft = ConstructQuadTree(grid,row,rowEnd,columnStart,column);
        currNode->bottomRight = ConstructQuadTree(grid,row,rowEnd,column,columnEnd);
        
        return currNode;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        return ConstructQuadTree(grid,0,n,0,n);
    }
};

/*
this approach wont work as 
12 16
now if we go by topLeft it would be -> 12 8 , which started giving wrong inputs , so doing mid approach
int column = (columnEnd-columnStart);
int row = (rowEnd - rowStart);
currNode->topLeft = ConstructQuadTree(grid,rowStart,rowEnd/2,columnStart,columnEnd/2);
currNode->topRight = ConstructQuadTree(grid,rowStart+row/2,rowEnd,columnStart,columnEnd/2);
currNode->bottomLeft = ConstructQuadTree(grid,rowStart,rowEnd/2,columnStart+column/2,columnEnd);
currNode->bottomRight = ConstructQuadTree(grid,rowStart+row/2,rowEnd,columnStart+column/2,columnEnd);
*/
