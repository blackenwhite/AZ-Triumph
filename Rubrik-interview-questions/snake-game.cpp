// leetcode 353
class SnakeGame {
    int w,h;
    vector<vector<int>> food;
    int foodPos;
    deque<pair<int,int>> snake;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width;
        h = height;
        foodPos = 0;
        this->food = food;
        snake.push_front(make_pair(0,0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int i = snake.front().first;
        int j = snake.front().second;
        if(direction=="U") i--;
        else if(direction=="L")  j--;
        else if(direction=="R")  j++;
        else if(direction=="D")  i++;

        //hits boundary
        if(i<0||i>=h||j<0||j>=w) return -1;
        //bites it's body
        pair<int, int>temp = make_pair(i,j);
        if(find(snake.begin(), snake.end(), temp)!=snake.end()){
            //if it's the last place no collision 
            if(temp != snake.back()) return -1;
        }
        if(foodPos<food.size()&&i==food[foodPos][0]&&j==food[foodPos][1]){
            foodPos++;
        } else 
            snake.pop_back();
        snake.push_front(temp);
        return foodPos;
    }
};
