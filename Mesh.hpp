#ifndef _MESH_H_
#define _MESH_H_
#include "Element.hpp"
class Mesh
{
private:
    int Ne;
    int polyn;
    Element *element;
    std::string meshtype;
public:
    Mesh();
    Mesh(std::string _meshtype,int Ne_in, int _polyn);
    ~Mesh();
    void createMesh(std::string _meshtype, int _Ne, int _polyn);
    void displayGrid();
};
#endif 