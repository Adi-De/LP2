#include<bits/stdc++.h>
using namespace std;

int main(){
    
    map<string,string> mp = {
        {"", "Sorry, I don't know the answer"},
        {"bye", "Bye have a nice time"},
        {"array", "An array is a data structure consisting of a collection of elements, each identified by at least one array index or key."},
        {"arrayresized", "In some programming languages, arrays can be resized dynamically, while in others, such as C, the size is fixed."},
        {"arraytimecomplexity", "The time complexity for accessing an element in an array is O(1), as it can be accessed directly using its index."},
        {"linkedlist", "A linked list is a fundamental data structure in computer science. It consists of nodes where each node contains data and a reference (link) to the next node in the sequence. This allows for dynamic memory allocation and efficient insertion and deletion operations compared to arrays."},
        {"arraylinkedlist", "An array is a static data structure, while a linked list is a dynamic data structure. Arrays have a fixed size, and elements are stored consecutively in memory, while linked lists can grow and do not require contiguous memory allocation."},
        {"typeslinkedlist", "A linked list is a linear data structure consisting of a sequence of elements, where each element points to the next one, forming a chain. and its types are Singly linked list, doubly linked list, and circular linked list."},
        {"looplinkedlist", "A cycle, also known as a loop, in a singly-linked list occurs when a node in the list points back to a previous node, creating a circular path. This means that if you start traversing the list from any node, you will eventually come back to the same node, forming an infinite loop."},
        {"cyclelinkedlist", "A cycle, also known as a loop, in a singly-linked list occurs when a node in the list points back to a previous node, creating a circular path. This means that if you start traversing the list from any node, you will eventually come back to the same node, forming an infinite loop."},
        {"stack", "A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle."},
        {"stackoperations", "The common operations on a stack are push (insert an element), pop (remove the top element), and peek (view the top element)."},
        {"queue", "A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle, where elements are added at the rear (enqueue) and removed from the front (dequeue)."}
    };
    
    cout<<"Welcome To Our Elementry Chatbot:"<<endl;
    
    string input;
    while(true){
        cout<<"Enter The text:";
        getline(cin,input);
        
        transform(input.begin(),input.end(),input.begin(),::tolower);
        
        string ans="";
        bool found=false;
        for(int i=0;i<input.length();++i){
            string p="";
            while(i<input.length() && input[i]!=' '){
                p+=input[i];
                ++i;
            }
            
            if(mp.find(p)!=mp.end()){
                ans+=p;
                found=true;
            }
        }
        
        if (found) {
            cout << mp[ans] << endl;
        } else {
            cout << mp[""] << endl; // Default response
        }

        if (input == "bye") {
            cout << mp["bye"] << endl;
            break;
        }
    }
    
    return 0;
}