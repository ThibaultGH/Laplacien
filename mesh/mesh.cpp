#include <iostream>
#include <fstream>
#include <cstring>
#include "mesh.hpp"

using namespace std;

mesh::mesh(char* filename){

  // Construct a flux to read the mesh file in :
  ifstream my_file(filename);
  
  // Some local variables :
  string line_my_file;
  string char_line;
  string temp_str;
  int count_spaces = 0;
  int line_size;
  char space = ' ';
  int* save_spaces_pos;
  bool found_nb_nodes = false;
  bool found_nb_elements = false;

  save_spaces_pos = (int *) malloc(sizeof(int)*50);

  // Start reading the mesh file
  if (my_file.is_open()) {
    // my_file >> nb_nodes;

    while (getline(my_file,line_my_file)) {

      /*
	This while loop works this way :
	     _ if a line "$Nodes" or "$Elements" is found, the next line gets us the number of nodes and elements respectively.
	     _ Once we got them, we will read the lines of the file exactly this number of times.
	     _ For the nodes : 
	           _ The first number we encounter is the number of the nodes that we discard, the next three are the coordinates that we but into an array nodes[nb_nodes*3].
	       For the elements :
	           _ The three integer number we get are the number of the nodes forming a triangle, starting from 1 we need to do -1 to respect indexation in C++ starting at 0.
       */
      
      if (found_nb_nodes) {
	nb_nodes = stoi(line_my_file);
	found_nb_nodes = false;

	nodes = (float* ) malloc(sizeof(float)*nb_nodes*3);

	for (int i0 = 0; i0 < nb_nodes; ++i0) {
	  getline(my_file,line_my_file);

	  for (int i1 = 0; i1 < line_my_file.size(); ++i1) {

	    if (line_my_file[i1] == space) { // if (line_myfile[i1] in "0123456789.") do

	      // cout << char_line << endl;
	      if (count_spaces == 0) {
		++count_spaces;
		char_line.clear();
	      }
	      else {
		nodes[i0*3+count_spaces-1] = stof(char_line);
		
		// cout << nodes[i0*3+count_spaces-1] << endl;

		++count_spaces;
	      
		char_line.clear();
	      
	      }
	    }
	    else {
	      temp_str.clear();
	      temp_str += line_my_file[i1];
	      char_line.append(temp_str);
	    }	  
	  }
	  count_spaces = 0;
	}
      }
      else if (found_nb_elements) { // We will enter once here after we've crossed the expression "$Elements" and load all the elements in the array elements.
	nb_elements = stoi(line_my_file);
	found_nb_elements = false;

	elements = (int* ) malloc(sizeof(int)*nb_elements*3);
	
	// for (int i3 = 0; i3 < nb_elements; ++i3) {
	//   getline(my_file,line_my_file);

	//   line_size = line_my_file.size();
	  
	//   // cout << line_my_file[line_size-1]<< " " << line_my_file[line_size-3] << endl;

	//   for (int i4 = line_size-1; i4 > -1; --i4) {

	//     if (line_my_file[i4] == space) {

	//       cout << save_spaces_pos << endl;

	//       // save_spaces_pos+count_spaces = i4;
	//       // ++count_spaces;
	      
	//     }
	//   }

	//   for (int i5 = 0; i5 < 3; ++i5) {
	//     for (int i6 = *(save_spaces_pos+3-i5); i6 < *(save_spaces_pos+3-i5-1); ++i6) {
	//       temp_str.clear();
	//       temp_str =+ line_my_file[i6];
	//       char_line.append(temp_str);
	//     }

	//   }

	//   count_spaces = 0;

	// }

      }

      
      if (line_my_file == "$Nodes") {
	found_nb_nodes = true;
      }
      else if (line_my_file == "$Elements"){
	found_nb_elements = true;
      }
      
    } 
  }
  else {
    cout << "ERROR : file " << filename << " NOT open !" << endl;
  }

  // deallocate
  delete[] save_spaces_pos;

  
}

mesh::~mesh(){

  // cout << "~mesh() called !" << endl;

  // delete[] corners;
  // delete[] border_edges;
  
  delete[] nodes;
  delete[] elements;


}
