#ifndef _MESH_H_
#define _MESH_H_
#include "Element.hpp"
class Mesh
{
private:
    int Ne;
    int n_nodes;
    int gradInterp;
    int n_loc_basis;
    int n_global_basis;
    int n_basis_bc; //Number of basis after aply the BC
    Element *element;
    std::string meshtype;
public:
    Mesh();
    Mesh(int _Ne, int _gradInterp, std::string _meshtype);
    ~Mesh();
    void createMesh(int _Ne, int _gradInterp, std::string _meshtype);
    void displayGrid();
};
#endif 