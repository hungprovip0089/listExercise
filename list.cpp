#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Node{
public:
    string firstName;
    string lastName;
    string phone;
    Node *next;
    Node(): next(nullptr) {};
    ~Node(){
        delete next;
    }
    Node(string firstName, string lastName, string phone, Node* next_node= NULL){
        this->firstName.append(firstName);
        this->lastName.append(lastName);
        this->phone.append(phone);
        this->next = next_node;
    }
    friend ostream & operator << (ostream &out, const Node &node);
};
ostream & operator << (ostream &out, const Node &node){
    out<< node.firstName << " ";
    out<< node.lastName << " ";
    out<< node.phone;
    return out;
}

class PhoneList{
private:
    Node* head;
    Node* tail;
public:
    PhoneList(){
        head = nullptr;
        tail = nullptr;
    }
    ~PhoneList(){
        delete head;
        delete tail;
    }
    void append(string firstName, string lastName, string phone){
        if(head == NULL){
            Node* newNode = new Node(firstName, lastName, phone);
            head = newNode;
            tail = newNode;
        }
        else{
            Node* newNode = new Node(firstName, lastName, phone);
            tail->next = newNode;
            tail = newNode;
        }
    }
    bool remove(string removePhone){
        Node* pre = NULL;
        Node* cur = head;
        while(cur){
            if(cur->phone==removePhone) {
                if(cur==head){
                    head = cur->next;
                    cur->next = nullptr;
                    delete cur;
                    return true;
                }
                else if(cur==tail){
                    tail = pre;
                    pre->next = nullptr;  
                    delete cur;
                    return true;                
                }
                else {
                  pre->next = cur->next;
                  cur->next = nullptr;
                  delete cur;
                  return true;
                }
            }
            pre = cur;
            cur = cur->next;
        }
        return false;
    }
    void display(){
        Node *cur = head;
        if(cur == nullptr) {
            cout << "Phone list is empty" << '\n';
            return;
        }
        while(cur){
            cout << *cur ;
            cout << '\n';
            cur = cur->next;
        }
    }

};



int main(){
  string str("");
  if(str.compare("A") ) cout << "a > A";
  return 0;
}