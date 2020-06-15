class SubrectangleQueries {
private:
    vector<vector<int>> rectangle;
    vector<vector<int>> histories;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle_) {
        rectangle = rectangle_;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        histories.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {
        for (int i = histories.size() - 1; i >= 0; --i) {
            if (histories[i][0] <= row && row <= histories[i][2] &&
                histories[i][1] <= col && col <= histories[i][3]) {
                return histories[i][4];
            }
        }
        return rectangle[row][col];
    }
};




/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */