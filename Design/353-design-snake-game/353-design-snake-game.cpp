class SnakeGame {
    unordered_map<int,int>board;
    vector<vector<int>> food;
    queue< pair<int,int> >q;
    int x;
    int y;
    int height;
    int width;
    int foodCount;
    bool gameOver;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {

        this->food = food;
        x = 0;
        y = 0;
        this->height = height;
        this->width = width;
        foodCount = 0;
        gameOver = false;

        q.push({x,y});
        board[x*10000 + y] = -1;
    }

    void setDirection(string &direction)
    {
        if(direction == "R")
        {
            y += 1;
        }
        else if(direction == "L")
        {
            y -= 1;
        }
        else if(direction == "U")
        {
            x -= 1;
        }
        else
        {
            x += 1;
        }
    }
    
    int move(string direction) {

        if(gameOver)
            return -1;
        
        setDirection(direction);

        if(x<0 or y<0 or x>=height or y>=width)
        {
            gameOver = true;
            return -1;
        }

        if(q.size() >foodCount)
        {
            pair<int,int> curr = q.front();
            q.pop();

            board[curr.first*10000+curr.second] = 0;
        }

        if(board[x*10000 + y] == -1)
        {
            gameOver = true;
            return -1;
        }

        if(foodCount<food.size() and x == food[foodCount][0] and y == food[foodCount][1])
        {
            foodCount += 1;
        }

        q.push({x,y});
        board[x*10000 + y] = -1;

        return foodCount;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */


//  [[3,3,[[2,0],[0,0],[0,2],[1,1]]],["D"],["D"],["R"],["U"],["U"],["L"],["D"],["R"],["R"],["U"],["L"],["D"]]

//   [[3,3,[,[0,2],[1,1]]],,,,,,,,,,,,["D"]]
