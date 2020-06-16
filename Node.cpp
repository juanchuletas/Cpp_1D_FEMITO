#include<iostream>
#include "Node.hpp"

Node::Node()
{std::cout<<"Calling node def constructor"<<std::endl;
    x = 0.0;
}
Node::Node(double x_in)
    :x{x_in}{
        std::cout<<"Calling node constructor"<<std::endl;

    }
Node::Node(const Node &source)
    :x{source.x}{
        std::cout<<"shallow copy "<<std::endl;
    }
Node::~Node(){
    std::cout<<"Calling node destructor"<<std::endl;
}
void Node::setNode(double x_value){
    x = x_value;
}
double Node::getNode(){
   return x; 
}