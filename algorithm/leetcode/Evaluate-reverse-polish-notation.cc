class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int num1, num2;
        for(auto x : tokens) {
            if(x.size() == 1 && !(x[0] >= '0' && x[0] <= '9')){
                switch(x[0]) {
                    case '+': num2 = s.top(); s.pop();
                              num1 = s.top(); s.pop();
                              s.push(num1 + num2);
                              break;
                    case '-': num2 = s.top(); s.pop();
                              num1 = s.top(); s.pop();
                              s.push(num1 - num2);
                              break;    
                    case '*': num2 = s.top(); s.pop();
                              num1 = s.top(); s.pop();
                              s.push(num1 * num2);
                              break; 
                    case '/': num2 = s.top(); s.pop();
                              num1 = s.top(); s.pop();
                              s.push(num1 / num2);
                              break; 
                }
            }
            else {
                s.push(atoi(x.c_str()));
            }
        }
        return s.top();
    }
};
