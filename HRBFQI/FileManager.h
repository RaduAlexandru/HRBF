// FileManager.h: FileManager
//
//////////////////////////////////////////////////////////////////////
#include "PolygonalMesh.h"
#include "PointSet.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>

class FileManager
{
public:
	void saveWaveFront(std::ofstream& file, PolygonalMesh *mesh, float oriCt[3], float scale = 1.0f);
	void save(PolygonalMesh *mesh, float oriCt[3], float scale = 1.0f);
	// void setFile(std::ifstream& file, std::string file_name, std::string file_ext);
	void open(std::ifstream& file, PointSet* ps);
	FileManager();
	virtual ~FileManager();

};
