#include <iostream>

using namespace std;

int main() {
  int start_row, end_row, start_column,
      end_column;  // Declare each variable on each line. Saw this strat on
                   // StackOverFlow and wanted to try

  cin >> start_column >> end_column >> start_row >>
      end_row;  // Input rows and column

  for (int i{start_row}; i <= end_row; i++) {  // for each number between the starting row and end row
    for (int j{start_column}; j <= end_column; j++) {  // for each number between starting comlumn and end column
      int multi{i * j};  // multiply the two numbers
      if (j == end_column) {
        cout << i << "*" << j << "=" << multi;  // if its the end in the row dont print the ,
      } else {
        cout << i << "*" << j << "=" << multi << ", ";  // else normal print
      }
    }
    cout << endl;  // newline after each column
  }

  return 0;
}