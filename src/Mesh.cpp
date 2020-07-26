#include <iostream>
#include "Mesh.hpp"


Mesh::Mesh()
{
    Ne = 0;
    n_nodes = 0;
    gradInterp = 0;
    n_loc_basis = 0;
    n_global_basis = 0;
    n_basis_bc = 0; //Number of basis after aply the BC
    Element *element;
    std::string meshtype;
    std::cout<<"Default values"<<std::endl;
}
Mesh::Mesh(int _Ne, int _gradInterp, std::string _meshtype)
    :Ne{_Ne},gradInterp{_gradInterp},meshtype{_meshtype}{
        element = nullptr;
        element = new Element[Ne];
        n_nodes = Ne*gradInterp + 1;
        n_global_basis = n_nodes;
        n_basis_bc = n_nodes-2;
    }
Mesh::~Mesh(){
    delete []element;
}
//Methods
void Mesh::createMesh(int _Ne, int _gradInterp, std::string _meshtype)
{
    Ne = _Ne;
    gradInterp = _gradInterp;
    int _polyn = _gradInterp + 1;
    std::cout<<"Creating a Mesh"<<std::endl;

    element = nullptr;
    element = new Element[_Ne];
    Node *node{nullptr};

    for(int i=0; i<_Ne; i++)
    {
        element[i].allocateNodes(_polyn);
        for(int j=0; j<_polyn; j++)
        {
            element[i].node[j].setNode(i*2.0);
            //std::cout<<std::fixed<<"Element: "<<i<<" Node: "<<j<<" Value: "<<element[i].node[j].getNode()<<std::endl;
        }
    }

}
void Mesh::displayGrid()
{
    std::cout<<"Ne: "<<Ne<<std::endl;
    for(int i=0; i<Ne; i++)
    {
        for(int j=0; j<gradInterp+1; j++)
        {
            std::cout<<std::fixed<<"Element: "<<i<<" Node: "<<j<<" Value: "<<element[i].node[j].getNode()<<std::endl;
        }
    }
}
