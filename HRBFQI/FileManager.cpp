// FileManager.cpp: FileManager
//
//////////////////////////////////////////////////////////////////////
#include "FileManager.h"

#include "PolygonalMesh.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
char CAP(char c){
  if (c >= 'a' && c < 'z')
    return c + ('A' - 'a');
  else
    return c;
}
FileManager::FileManager()
{

}

FileManager::~FileManager()
{

}

// void FileManager::setFile(std::ifstream& file, std::string file_name, std::string file_ext)
// {
// 	this->file =  file;
// 	this->file_name = file_name;
// 	this->file_ext = file_ext;
// }

void FileManager::save(PolygonalMesh *mesh, float oriCt[3], float scale)
{

	// this->saveWaveFront(mesh,oriCt,scale);
}
void FileManager::saveWaveFront(std::ofstream& file, PolygonalMesh *mesh, float oriCt[3], float scale)
{
	float (*vertex)[3] = mesh->vertex;
	int (**face) = mesh->face;
	int vertex_N = mesh->vertex_N;
	int face_N = mesh->face_N;

	int i;
	for(i=0; i<vertex_N; i++){
        file << "v ";
        file << vertex[i][0]/scale+oriCt[0] << " "
             << vertex[i][1]/scale+oriCt[1] << " "
             << vertex[i][2]/scale+oriCt[2]
             << "\n";
	}

	for(i=0; i<face_N; i++){
		file << "f ";
        file << face[i][0]+1 << " "
             << face[i][1]+1 << " "
             << face[i][2]+1
             << "\n";
	}
}
void FileManager::open(std::ifstream& file, PointSet *ps)
{
	//read cloud data file and perform trianlization.
    std::string line;
    if (file.is_open()){
        int point_N;
        // std::cout << "getting nr of points" << '\n';
        getline(file, line);
        std::istringstream iss(line);
        iss >> point_N;
        // std::cout << "got nr of points " << point_N  << '\n';
    	ps->setPointSize(point_N);
    	float x, y, z;




    	int i;

    	for(i=0; i<point_N; i++){
    		// fscanf(file, "%f %f %f", &x, &y, &z);
            getline(file, line);
            std::istringstream iss_point(line);
            iss_point >> x >> y >> z;
    		ps->setPoint(i, x, y, z);
            // std::cout << "set point " << i << " " << x << " " << y << " " << z << '\n';
    	}
    	for(i=0; i<point_N; i++){
            getline(file, line);
            std::istringstream iss_normal(line);
            iss_normal >> x >> y >> z;
    		ps->setNormal(i, -x, -y, -z);
            // std::cout << "set normal " << i << " " << x << " " << y << " " << z << '\n';
    	}
    }



}
