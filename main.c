#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  //Matrix Tests
  printf("Matrix tests\n\n");
  struct matrix *mat1;
  struct matrix *mat2;

  mat1 = new_matrix(4,4);
  mat2 = new_matrix(4,2);

  //populate matrix 1
  add_edge(mat1, 2.093, 7.124, 120.094, 7.924, 13.124, 150.124);
  add_edge(mat1, 492.124, 44.444, 8.834, 985.983, 1.239, 198.198);

  //populate matrix 2
  add_edge(mat2, 98.192, 38.124, 9.984, 5.298, 5.298, 5.298);

  printf("Display matrix 1 then 2\n");
  print_matrix(mat1);
  printf("\n");
  print_matrix(mat2);

  printf("\n\nMultiply matrix 1 and 2\n");
  matrix_mult(mat1, mat2);
  print_matrix(mat2);

  printf("\n\nTurn matrix 1 into an identity matrix\n");
  ident(mat1);
  print_matrix(mat1);

  free_matrix(mat1);
  free_matrix(mat2);
  //End of Matrix Tests

  //Produce Image
  
  screen s;
  color c;
  c.red = 255;
  c.green = 0;
  c.blue = 0;

  clear_screen(s);
  
  struct matrix *edges;

  edges = new_matrix(4, 4);

  //top AN
  add_edge(edges, 230, 260, 0, 270, 260, 0);
  add_edge(edges, 230, 260, 0, 230, 325, 0);
  add_edge(edges, 230, 325, 0, 130, 200, 0);
  add_edge(edges, 130, 200, 0, 90, 200, 0);
  add_edge(edges, 90, 200, 0, 230, 375, 0);
  add_edge(edges, 230, 375, 0, 270, 375, 0);
  add_edge(edges, 270, 260, 0, 270, 375, 0);

  //bottom AN
  add_edge(edges, 230, 240, 0, 270, 240, 0);
  add_edge(edges, 270, 175, 0, 270, 240, 0);
  add_edge(edges, 270, 175, 0, 370, 300, 0);
  add_edge(edges, 370, 300, 0, 410, 300, 0);
  add_edge(edges, 410, 300, 0, 270, 125, 0);
  add_edge(edges, 270, 125, 0, 230, 125, 0);
  add_edge(edges, 230, 125, 0, 230, 240, 0);
  
  
  draw_lines(edges, s, c);
  //display(s);
  save_extension(s, "matrix.png");
  free_matrix( edges );
}
