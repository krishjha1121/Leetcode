class Spreadsheet {
private:
    vector<vector<int>> sheet;
    
    int evaluate(const string &s) {
        if (isdigit(s[0]))
            return stoi(s);
        int col = s[0] - 'A' + 1;
        int row = stoi(s.substr(1));
        return sheet[row][col];
    }

public:
    Spreadsheet(int rows) {
        sheet = vector<vector<int>>(rows + 1, vector<int>(27, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A' + 1;
        int row = stoi(cell.substr(1));
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A' + 1;
        int row = stoi(cell.substr(1));
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        string exp = formula.substr(1);
        size_t plusPos = exp.find('+');
        string part1 = exp.substr(0, plusPos);
        string part2 = exp.substr(plusPos + 1);
        return evaluate(part1) + evaluate(part2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */