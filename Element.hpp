#ifndef _ELEMENT_H_
#define _ELEMENT_H_
#include "Node.hpp"
class Element
{
    public:
        Node *node;
        int numNodes;
    public:
        Element();
        Element(int order);
        Element(const Element &source);
        ~Element();
        void allocateNodes(int order);
};
#endif