/*Mohit Ranjit More
  Roll No-3014
  Batch-S3*/
#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    char data;
    Node* next;
};

class StackList{
public:
    Node* TOP=NULL;

    void push(char b){
        Node* ptr=new Node;
        ptr->data=b;
        ptr->next=TOP;
        TOP=ptr;
    }

    char pop(){
        if(TOP==NULL){
            cout<<"STACK IS UNDERFLOW"<<endl;    
        }else{
            Node* ptr;
            ptr=TOP;
            TOP=ptr->next;
            char temp=ptr->data;
            delete ptr;
            return temp;
        }
    }

    void Display(){
        if(TOP==NULL){
            cout<<" THE STACK IS UNDERFLOW."<<endl;    
        }else{
            Node* ptr;
            ptr=TOP;
            cout<<"THE STACK IS:"<<endl;
            while(ptr !=NULL){
                cout<<ptr->data<<"->";
                ptr=ptr->next;
            }
        }
    }
};

class Expression{
    public:
    string infix;
    string postfix = "";
    string prefix="";
    StackList st;

public:

    int priority(char c){
        if(c=='^'){
		    return 3;
	    }else if(c== '*'|| c=='/'){
		    return 2;
	    }else if(c== '+'|| c=='-'){
		    return 1;	
	    }else{
		    return -1;
	}
}

bool Operator(char c){
    if (c =='+'  || c == '-'  || c =='*'  || c =='/'){
        return true;
    }else{
        return false;
    }
}

void InfixToPostfix(string s)
{


    for(int i=0;i<s.length();i++){
		if((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z')){
			postfix +=s[i];

		}else if(s[i]=='('){
			st.push(s[i]);
		}else if(s[i]==')'){	
			while(st.TOP->data !='(' && st.TOP !=NULL){
				postfix +=st.pop();
				
			}
			if(st.TOP->data =='('){
                st.pop();
            }
		}else if(Operator(s[i])){
            if(st.TOP == NULL){
                st.push(s[i]);
            } else {
                if(priority(s[i]) > priority(st.TOP->data)){
                    st.push(s[i]);
                }else{
                    while(priority(s[i]) <= priority(st.TOP->data)){
                        postfix +=st.pop();

                    }
                    st.push(s[i]);
                }
            }
        }
    }
    while (st.TOP !=NULL){
         postfix +=st.pop();
    }
    cout<<"\n";
    cout<<"Postfix Expression is:" <<postfix << endl;
    cout<<"\n";
}

string reverseString(string str)
{
    int n=str.length();
    for(int i = 0; i <n / 2; i++){
        swap(str[i],str[n - i - 1]);
    }
    return str;
}

void InfixToPrefix(string s)
{
    string s_1=reverseString(s);
    string temp_prefix="";
    for(int i=0;i<s_1.length();i++)
    {
        if(s_1[i]=='(')
        {
            s_1[i]=')';
        }
        else if(s_1[i]==')')
        {
            s_1[i]='(';
        }
    }

    for(int i=0;i<s_1.length();i++)
    {
       if(s_1[i]>='a'&& s_1[i]<='z' || s_1[i]>='A'&& s_1[i]<='Z')
       {
        temp_prefix+=s_1[i];
       }

       else if(s_1[i]=='(')
       {
        st.push(s_1[i]);
       }

       else if(s_1[i]==')')
       {
            while(st.TOP->data != '(' && st.TOP!=NULL)
            {
                temp_prefix+=st.pop();
            }
            if(st.TOP->data=='(')
            {
                st.pop();
            }
       }

       else if(Operator(s_1[i]))
       {
            if(st.TOP==NULL)
            {
                st.push(s_1[i]);
            }

            else{
                if(priority(s_1[i]) > priority(st.TOP->data))
                {
                    st.push(s_1[i]);
                }

                else if(priority(s_1[i])==priority(st.TOP->data) && s_1[i]=='^')
                {
                    while(priority(s_1[i])==priority(st.TOP->data) && s_1[i]!='^')
                    {
                        temp_prefix+=st.pop();
                    }
                    st.push(s_1[i]);

                }
                else if(priority(s_1[i])==priority(st.TOP->data))
                {
                    st.push(s_1[i]);
                }
                else{
                    while(st.TOP!=NULL && priority(s_1[i]) < priority(st.TOP->data))
                    {
                        temp_prefix+=st.pop();
                    }
                    st.push(s_1[i]);
                }
            }        
       }
    }
    while(st.TOP!=NULL)
    {
        temp_prefix+=st.pop();
    }
    //cout<<" Before reverse Expression is:"<<temp_prefix<<endl;
    prefix=reverseString(temp_prefix);
    cout<<"\n";
    cout<<"Prefix Expression is:" <<prefix << endl;
    cout<<"\n";
}

bool isAlpha(char d)
{
    if(d>='a' && d<='z' || d>='A' && d<='Z')
    {
        return true;
    }

    else{
        return false;
    }
}

bool isNumber(char d)
{
    if(d >= '0' && d <= '9')
    {
        return true;
    }
        return false;     
}

bool its_operand(char d)
{
    return isAlpha(d) || isNumber(d);
}

int postfixEvaluation(string postfix)
{
    for(int i=0; i<postfix.length();i++)
    {
        if(its_operand(postfix[i]))
        {
            cout<< "ENTER THE VALUE OF" << postfix[i] << ":";
            int value;
            cin >> value;
            st.push(value);

        }

        else
        {
            int num1 = st.pop();
            int num2 = st.pop();

            switch(postfix[i])
            {
                case '*':
                st.push(num2*num1);
                break;

                case '/':
                st.push(num2/num1);
                break;

                case '+':
                st.push(num2+num1);
                break;

                case '-':
                st.push(num2-num1);
                break;
            } 
        }
        
    }
    int temp=st.pop();
    cout<<" THE SOLUTION OF THE POSTFIX EXPRESSION IS:"<<temp<<endl;
    return temp;

}
int prefixEvaluation(string prefix)
{
    for(int i= prefix.size() - 1; i >=0; i--){
    if(its_operand(prefix[i])){
        cout<< "ENTER THE VALUE OF" << prefix[i] << ":";
        int value;
        cin >> value;
        st.push(value);
    }else{
        int num1 = st.pop();
        int num2 = st.pop();
        switch(prefix[i]){
            case '*':
                st.push(num1 * num2);
                break;
            case '/':
                st.push(num1 / num2);
                break;
            case '+':
                st.push(num1 + num2);
                break;
            case '-':
                st.push(num1 - num2);
                break;
             
        }
    }    
    
}
int temp=st.pop();
cout<<" THE SOLUTION OF THE PREFIX EXPRESSION IS:"<<temp<<endl;
return temp;
}
};

int main()
{
    Expression s1;
    string s;
    int choice;
    cout<<"ENTER THE INFIX EXPRESSION:";
    cin>>s;
    cout<<"\n";
 while(choice!=0)
 {
    cout<<"--------------------------------";
    cout<<"\n1: CONVERT INFIX TO POSTFIX\n2: EVALUATE POSTFIX EXPRESSION\n3: CONVERT INFIX TO PREFIX\n4: EVALUATE PREFIX EXPRESSION"<<endl;
    cout<<"--------------------------------";
    cout<<"\nENTER THE CHOICE AS PER MENTIONED ABOVE:";
    cin>>choice;
    cout<<"\n";
    switch(choice)
    {
        case 1:
            s1.InfixToPostfix(s);
            break;

        case 2:
            s1.postfixEvaluation(s1.postfix);
            break;

        case 3:
            s1.InfixToPrefix(s);
            break;

        case 4:
            s1.prefixEvaluation(s1.prefix);
            break;
        default:
            cout<<"Invalid choice!!"<<endl;             
    }
 }  
 return 0; 
}