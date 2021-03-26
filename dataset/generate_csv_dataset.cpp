#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

using namespace std;

// абсолютный путь до набора данных (константа времени компиляции)
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main(int argc, char** argv) {

  // можете передать путь до входного/выходного файла в качестве аргумента (т.е. не обязательно использовать kDatasetPath)
  for (int index = 0; index < argc; index++) {
    cout << "Arg: " << argv[index] << '\n';
  }

  const auto path = string{kDatasetPath};  // конвертация string_view в string
  cout << "Dataset path: " << path << endl;

  // чтения набора данных (пример)
  auto input_stream = ifstream{path + "/dataset-example.csv"};

  if (input_stream) {
    int line_number = 0;

    // построчное чтение
    for (string line; getline(input_stream, line); /* ... */) {
      stringstream ss{line};  // оборачиваем строку в объект "поток"

      for (string token; getline(ss, token, ','); /* ... */) {
        cout << "Token: [" << token << "] at line " << line_number << '\n';
      }

      cout << line << '\n';
      line_number++;
    }
  }

  // генерация набора данных (пример)
  auto output_stream = ofstream{path + "/dataset-generated.csv", ios::ios_base::app};

  const auto seed = chrono::system_clock::now().time_since_epoch().count();
  auto engine = mt19937{seed};  // без seed`а генератор будет выдавать одни не случайные значения
  auto dist = uniform_int_distribution(0, 10);

  if (output_stream) {
    for (int counter = 0; counter < 10; counter++) {
      output_stream << dist(engine) << ',';
    }
    output_stream << dist(engine) << '\n';
  }

  return 0;
}