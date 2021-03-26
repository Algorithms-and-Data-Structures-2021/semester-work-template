#include <iostream>
#include <fstream>
#include <string_view>

#include "data_structure.hpp"

using namespace std;
using namespace itis;

// DATASET_PATH - препроцессорное определение (параметр)
static constexpr char kDatasetPath[] = DATASET_PATH;

int main(int argc, char **argv) {

  cout << "Path to the 'dataset/' folder: " << kDatasetPath << endl;

  auto input_file = fstream{"<dataset>.csv"};

  return 0;
}
