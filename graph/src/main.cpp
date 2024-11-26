// Copyright <year> <You>
#include <iostream>
#include "MatrixGraph.hpp"

/**
 * @brief Start program execution.
 *
 * @return Status code to the operating system, 0 means success.
 */
int main() {
  MatrixGraph* graph = new MatrixGraph();
  graph->append_vertex('A');
  graph->append_vertex('B');
  graph->append_vertex('C');

  graph->delete_vertex(graph->first_vertex());

  graph->print_matrix();
  graph->print_elements();
}
