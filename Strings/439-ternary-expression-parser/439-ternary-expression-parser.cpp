class Solution {
public:
    char parseTernary(string &expression , int &index)
    {
        char ans = expression[index];
        index += 2;

        char quotientValue = expression[index];
        index++;

        if(expression[index] == '?')
        {
            index--;
            quotientValue = parseTernary(expression, index);
            index++;
        }

        index++;
        char indentValue = expression[index];

        if(index+1<expression.size() and expression[index+1] == '?')
        {
            indentValue = parseTernary(expression, index);
        }

        return (ans == 'T')?quotientValue:indentValue;

    }

    string parseTernary(string expression) {
        int index = 0;
        string res = "";

        res = parseTernary(expression, index);

        return res;
    }
};
