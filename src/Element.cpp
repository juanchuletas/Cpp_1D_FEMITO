#include <iostream>
#include "Element.hpp"

Element::Element()
{
    node = nullptr;
    std::cout<<"Calling element default constructor"<<std::endl;
}
Element::Element(int order)
{
    numNodes = order+1;
    node = nullptr;
    node = new Node[order+1];
    std::cout<<"Calling element non constructor"<<std::endl;
}
//Copy Constructor
Element::Element(const Element &source)
{
    std::cout<<"Calling Copy Construcor"<<std::endl;
    node = new Node[numNodes];
    *node = *source.node;

}
Element::~Element()
{
    std::cout<<"calling destructor"<<std::endl;
    delete []node;
}
void Element::allocateNodes(int poly)
{
    numNodes = poly;
    node = new Node[numNodes];
}