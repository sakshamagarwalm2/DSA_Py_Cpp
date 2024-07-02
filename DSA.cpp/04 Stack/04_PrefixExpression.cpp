//Prefix Evaluations using Stack

#include<bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s){
    stack<int> st;
    
    for (int i =s.length()-1;i>=0; i--)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            st.push(s[i] - '0');
        }
        else{
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            
            switch(s[i]){
                case '+':
                    st.push(val1 + val2);
                    break;
                case '-':
                    st.push(val1 - val2);
                    break;
                case '*':
                    st.push(val1 * val2);
                    break;
                case '/':
                    st.push(val1 / val2);
                    break;
            }

        }
        
    }

    return st.top();
    
}

int main(){

    string prefixExpression = "-+7*45+20";
    int result = prefixEvaluation(prefixExpression);
    cout << "Result: " << result << endl;
return 0;
}