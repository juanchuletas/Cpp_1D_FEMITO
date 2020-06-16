#include <iostream>
#include "Mesh.hpp"


Mesh::Mesh()
{
    Ne = 0.0;
    element = nullptr;
    polyn= 0.0;
    meshtype = "NONE";
    std::cout<<"Default values"<<std::endl;
}
Mesh::Mesh(std::string _meshtype, int Ne_in, int _polyn)
    :meshtype{_meshtype},Ne{Ne_in},polyn{_polyn}{
        element = nullptr;
        element = new Element[Ne];
    }
Mesh::~Mesh(){
    delete []element;
}
//Methods
void Mesh::createMesh(std::string _meshtype, int _Ne, int _polyn)
{
    Ne = _Ne;
    polyn = _polyn;
    std::cout<<"Creating a Mesh"<<std::endl;

    element = nullptr;
    element = new Element[_Ne];
    Node *node{nullptr};

    for(int i=0; i<_Ne; i++)
    {
        element[i].allocateNodes(_polyn);
        for(int j=0; j<_polyn; j++)
        {
            element[i].node[j].setNode(10.00);
            //std::cout<<std::fixed<<"Element: "<<i<<" Node: "<<j<<" Value: "<<element[i].node[j].getNode()<<std::endl;
        }
    }

}
void Mesh::displayGrid()
{
    std::cout<<"Ne: "<<Ne<<std::endl;
    for(int i=0; i<Ne; i++)
    {
        for(int j=0; j<polyn; j++)
        {
            std::cout<<std::fixed<<"Element: "<<i<<" Node: "<<j<<" Value: "<<element[i].node[j].getNode()<<std::endl;
        }
    }
}