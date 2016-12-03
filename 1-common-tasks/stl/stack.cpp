//Using the STL stack
#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> st;

    //push some elements
    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);

    cout<<"The stack is "<<(st.empty() == true ? "" : " not ")<<"empty"<<endl;
    cout<<"Stack has size "<<st.size()<<endl;

    cout<<"The top of the stack has a value of "<<st.top()<<endl;
   
    //pop an element.
    st.pop();
    cout<<"The top of the stack is now "<<st.top()<<endl;

    //empty the stack
    while(!st.empty())
        st.pop();

    return 0;
}
