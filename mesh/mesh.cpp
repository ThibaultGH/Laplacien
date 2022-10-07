#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void read_mesh_file(int &nb_nodes, int &nb_elements, float* &nodes, int* elements, const char* filename){
  
  ifstream my_file(filename);
  string line_my_file;
  string char_line;
  string temp_str;
  int count_spaces = 0;
  char space = ' ';
  bool found_nb_nodes = false;
  bool found_nb_elements = false;
  
  if (my_file.is_open()) {
    // my_file >> nb_nodes;

    while (getline(my_file,line_my_file)) {


      
      if (found_nb_nodes) { // We will enter once here after we've crossed the expression "$Nodes" and load all the nodes in the array nodes.	
	nb_nodes = stoi(line_my_file);
	found_nb_nodes = false;

	nodes = (float* ) malloc(sizeof(float)*nb_nodes*3);

	for (int i0 = 0; i0 < nb_nodes; ++i0) {
	  getline(my_file,line_my_file);

	  for (int i1 = 2; i1 < line_my_file.size(); ++i1) {

	    if (line_my_file[i1] == space or line_my_file[i1] == '\n') {
	      	      
	      nodes[i0*3+count_spaces] = stof(char_line);

	      ++count_spaces;
	      
	      char_line.clear();
	    }
	    else {
	      temp_str.clear();
	      temp_str += line_my_file[i1];
	      char_line.append(temp_str);
	      count_spaces = 0;
	      
	    }
	    
	  
	  }
	  
	  // cout << endl;

	  // cout << line_my_file << endl;
	  
	  // line_nodes = strtok((char*) line_my_file," ");

	  // for (int i1 = 0; i1 < 3; ++i1) {
	  //   cout << line_my_file[i1+1] <<" ";
	    
	    // nodes[i0*nb_nodes+i1] = stoi(line_nodes[i1+1]);
	  // }
	  // cout << endl;

	  
	}

      }
      else if (found_nb_elements) { // We will enter once here after we've crossed the expression "$Elements" and load all the elements in the array elements.
	nb_elements = stoi(line_my_file);
	found_nb_elements = false;

	elements = (int* ) malloc(sizeof(int)*nb_elements*3);
	
	// for (int i0 = 0; i0 < nb_elements; ++i0) {
	//   getline(my_file,line_my_file);

	//   line_elements = strtok(line_my_file," ");

	//   for (int i1 = 0; i1 < 3; ++i1) {
	//     elements[i0*nb_elements+i1] = stoi(line_nodes[i1+1]);
	//   }

	  
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




}
