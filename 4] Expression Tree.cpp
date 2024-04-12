#include <iostream>
#include <stack>
using namespace std;

class Tnode{
    public:
    char data;
    Tnode* left;
    Tnode* right;

    Tnode(char val) :data(val),left(nullptr),right(nullptr) {}
};


class Operations{
    public :
    Tnode* tree_by_prefix(string string);
    Tnode* tree_by_postfix(string string);
    void rInorder(Tnode* root);
    void rPreorder(Tnode* root);
    void rPostorder(Tnode* root);
    void nrInorder(Tnode* root);
    void nrPreorder(Tnode* root);
    void nrPostorder(Tnode* root);
    bool is_oprator(char c);
};

    bool Operations :: is_oprator(char c){
        return (c=='+' || c=='-' || c=='*' || c=='/');
    }

    Tnode* Operations :: tree_by_prefix(string string){
        stack <Tnode*> st;

        for(int i=string.size()-1;i>=0;i--){
            char x = string[i];

            Tnode* n = new Tnode(x);
            if(!is_oprator(x)){
                st.push(n);
            }
            else{
                n->left = st.top();
                st.pop();
                n->right = st.top();
                st.pop();
                st.push(n);
            }
        }
        return st.top();
    }

    Tnode* Operations :: tree_by_postfix(string string){
        stack <Tnode*> st;
        
        for(int i=0;i<string.size();i++){
            char x = string[i];

            Tnode* n = new Tnode(x);
            if(!is_oprator(x)){
                st.push(n);
            }
            else{
                n->right=st.top();
                st.pop();
                n->left = st.top();
                st.pop();
                st.push(n);
            }
        }
        return st.top();
    }

    void Operations :: rInorder(Tnode* root){
        if(root == nullptr){
            return;
        }
        else{
            rInorder(root->left);
            cout<<root->data<<" ";
            rInorder(root->right);

        }
    }

    void Operations:: rPreorder(Tnode* root){
        if(root == nullptr){
            return;
        }
        else{
            cout<<root->data<<" ";
            rPreorder(root->left);
            rPreorder(root->right);
        }
    }

    void Operations ::rPostorder(Tnode* root){
        if(root == nullptr){
            return;
        }
        else{
            rPostorder(root->left);
            rPostorder(root->right);
            cout<<root->data<<" ";
        }
    }

    void Operations :: nrInorder(Tnode* root){
        stack<Tnode*> st;
        Tnode* current = root;

        while (current || !st.empty()) {
            while (current) {
                st.push(current);
                current = current->left;
        }

        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
    }

    void Operations :: nrPostorder(Tnode* root){
         if (!root) return;
        stack<Tnode*> st;
        stack<Tnode*> output;
        st.push(root);

        while (!st.empty()) {
            Tnode* current = st.top();
            st.pop();
            output.push(current);
            if (current->left) st.push(current->left);
            if (current->right) st.push(current->right);
        }

        while (!output.empty()) {
            cout << output.top()->data << " ";
            output.pop();
        }
    }

    void Operations :: nrPreorder(Tnode* root){
        if (!root) return;
        stack<Tnode*> st;
        st.push(root);

        while (!st.empty()) {
            Tnode* current = st.top();
            st.pop();
            cout << current->data << " ";
            if (current->right) st.push(current->right);
            if (current->left) st .push(current->left);
        }
    }



int main(){

    Operations op;

    cout<<"Select your operations "<<"\n1.Binary trre from postfix expression"<<"\n2.Binary tree from prefix expression"<<"\n3.Exit"<<endl;
    int choice;
    cin>>choice;

    Tnode* root = nullptr;

    switch(choice)
    {
        case 1:
            {
            string prefix;
            cout<<"Enter prefix expression"<<endl;
            cin>>prefix;
            root = op.tree_by_prefix(prefix);
            break;
            }

        case 2:
            {
            string postfix;
            cout<<"Enter postfix expression"<<endl;
            cin>>postfix;
            root= op.tree_by_postfix(postfix);
            break;
            }
    }

    int opr;
    

    do{
        if(root!=nullptr){
            cout << "Which operation do you want to perform? \n1. In-order recursive \n2. Pre-order recursive \n3. Post-order recursive \n4. In-order non-recursive \n5. Pre-order non-recursive \n6. Post-order non-recursive \n7.exit" << endl;
            cin>>opr;
            switch (opr)
            {
            case 1:
                cout<<"In-order recurcive"<<endl;
                op.rInorder(root);
                cout<<endl;
                break;
            case 2:
                cout<<"Pre-order recursive"<<endl;
                op.rPreorder(root);
                cout<<endl;
                break;
            case 3:
                cout<<"Post-order recursive"<<endl;
                op.rPostorder(root);
                cout<<endl;
                break;
            case 4:
                cout<<"In-order non-recursive"<<endl;
                op.nrInorder(root);
                cout<<endl;
                break;
            case 5:
                cout<<"Pre-order non-recursive"<<endl;
                op.nrPreorder(root);
                cout<<endl;
                break;
            case 6:
                cout<<"Post-order non-recursive"<<endl;
                op.nrPostorder(root);
                cout<<endl;
                break;
           
            }
            
        }
    }
    while(opr!=7);

return 0;
}