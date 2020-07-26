#ifndef _NODE_H_
#define _NODE_H_
class Node
{
    private: 
        double x;
    public:
        //Constructures
        Node();
        Node(double x_in);
        Node(const Node &source);
        ~Node();
        //Setters and getters
        void setNode(double x_val);
        double getNode();

};
#endif