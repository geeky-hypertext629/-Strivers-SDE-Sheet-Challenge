bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;
    int i;
    for(i=0;i<expression.size();i++)
    {
        if(expression[i]=='{' || expression[i]=='(' || expression[i]=='[')
        s.push(expression[i]);
        else if(expression[i]==')')
        {
            if(s.empty())
            return false;
            else if(s.top()!='(')
            return false;
            s.pop();
        }
        else if(expression[i]=='}')
        {
            if(s.empty())
            return false;
            else if(s.top()!='{')
            return false;
            s.pop();
        }
        else if(expression[i]==']')
        {
            if(s.empty())
            return false;
            else if(s.top()!='[')
            return false;
            s.pop();
        }

    }
    if(s.empty())
    return true;
    return false;
}