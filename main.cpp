#include <iostream>
#include "shared_ptr.h"
class Node {
public:
    int y;
    int x;
    Node():x(0),y(0){}
    Node(int a,int b):x(a),y(b) {}
};
int main() {
    shared_ptr<Node> p = shared_ptr<Node>(new Node(1,2));
    shared_ptr<Node> p1 =  shared_ptr<Node>(new Node(3,4));
    printf("p1 = (%d,%d)\n",p1.get()->x,p1.get()->y);
    p1 = p;
    shared_ptr<Node> p2 = shared_ptr<Node>(p1);
    printf("p = (%d,%d)\n",p.get()->x,p.get()->y);
    printf("p1 = (%d,%d)\n",p1.get()->x,p1.get()->y);
    printf("p2 = (%d,%d)\n",p2.get()->x,p2.get()->y);
    return 0;
}