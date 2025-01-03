class SQL {
    unordered_map<string, int>nameToColumnMap;
    unordered_map<string, unordered_map<int,string> >nameToIndexRowsMap;
    unordered_map<string,int>currIndexForTableMap;
public:
    SQL(vector<string>& names, vector<int>& columns) {
        for(int i=0;i<names.size();i++)
        {
            vector<string>temp;
            nameToColumnMap[names[i] ] = columns[i];
            nameToIndexRowsMap[names[i] ][-1] = "";
            currIndexForTableMap[names[i] ] = 1;
        }
    }
    
    bool ins(string name, vector<string> row) {

        if(nameToColumnMap.find(name) == nameToColumnMap.end() )
            return false;

        if(nameToColumnMap[name] != row.size() )
            return false;

        int index = currIndexForTableMap[name];
        currIndexForTableMap[name]++;

        string currRow = to_string(index);
        for(int i=0;i<row.size();i++)
        {
            currRow += ",";
            currRow += row[i];
        }

        nameToIndexRowsMap[name][index] = currRow;

        return true;
    }
    
    void rmv(string name, int rowId) {
        if(nameToColumnMap.find(name) == nameToColumnMap.end() )
            return;

        if(rowId<=0)
            return;

        auto &x = nameToIndexRowsMap[name];
        if(x.find(rowId) == x.end())
            return;

        x.erase(rowId);
    }
    
    string sel(string name, int rowId, int columnId) {
        //If name is not a valid table, or the cell (rowId, columnId) is invalid, returns "<null>"
        if(nameToColumnMap.find(name) == nameToColumnMap.end() 
            || nameToColumnMap[name]<columnId 
            || nameToIndexRowsMap[name].find(rowId) == nameToIndexRowsMap[name].end()
            || columnId<=0 ||
            rowId<=0)
        {
            return "<null>";
        }

        string row = nameToIndexRowsMap[name][rowId];
        
        stringstream ss(row);
        char del = ',';

        int index = 0;
        string res;

        while (getline(ss, res, del))
        {
            if(index == columnId)
                return res;
            index++;
        }

        return "<null>";
    }
    
    vector<string> exp(string name) {
        if(nameToColumnMap.find(name) == nameToColumnMap.end())
        {
            return {};
        }
        vector<string> result;

        auto x = nameToIndexRowsMap[name];
        for( auto entry : x)
        {
            if(entry.first<=0)
                continue;
            result.push_back(entry.second);
        }
        
        return result;
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */
