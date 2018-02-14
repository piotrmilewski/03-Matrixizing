#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
  
  
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
          int x0, int y0, int z0, int x1, int y1, int z1
Returns: 
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points, 
	       double x0, double y0, double z0, 
	       double x1, double y1, double z1) {
}

/*======== void draw_lines() ==========
Inputs:   struct matrix * points
         screen s
         color c 
Returns: 
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines( struct matrix * points, screen s, color c) {
}

//helper for draw_line
//inverts coordinates if x's are in the wrong order
void flip_line(int *x0, int *y0, int *x1, int *y1){
  int xtmp = *x0;
  int ytmp = *y0;
  *x0 = *x1;
  *y0 = *y1;
  *x1 = xtmp;
  *y1 = ytmp;
}

//octant 1
void draw_octant1(int x0, int y0, int x1, int y1, screen s, color c, int a, int b){
  int d = (2 * a) + b;
  while (x0 <= x1){
    plot(s, c, x0, y0);
    if (d > 0){
      y0++;
      d += (2 * b);
    }
    x0++;
    d += (2 * a);
  }
}

//octant 2
void draw_octant2(int x0, int y0, int x1, int y1, screen s, color c, int a, int b){
  int d = a + (2 * b);
  while (y0 <= y1){
    plot(s, c, x0, y0);
    if (d < 0){
      x0++;
      d += (2 * a);
    }
    y0++;
    d += (2 * b);
  }
}

//octant 7
void draw_octant7(int x0, int y0, int x1, int y1, screen s, color c, int a, int b){
  int d = a - (2 * b);
  while (y0 <= y1){
    plot(s, c, x0, y0);
    if (d > 0){
      x0++;
      d += (2 * a);
    }
    y0--;
    d -= (2 * b);
  }
}

//octant 8
void draw_octant8(int x0, int y0, int x1, int y1, screen s, color c, int a, int b){
  int d = (2 * a) - b;
  while (x0 <= x1){
    plot(s, c, x0, y0);
    if (d < 0){
      y0--;
      d -= (2 * b);
    }
    x0++;
    d += (2 * a);
  }
}

//Line algorithm
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //ensure line is drawn from left to right
  if (x0 > x1)
    flip_line(&x0, &y0, &x1, &y1);
  //set A, -B, and slope
  int a = y1 - y0; //change in y
  int b = -(x1 - x0); //negated change in x
  float m = ((float) a)/(-b); //slope
  //execute proper octant function
  if (m <= 1 && m > 0)
    draw_octant1(x0, y0, x1, y1, s, c, a, b);
  else if (m > 1)
    draw_octant2(x0, y0, x1, y1, s, c, a, b);
  else if (m < -1)
    draw_octant7(x0, y0, x1, y1, s, c, a, b);
  else
    draw_octant8(x0, y0, x1, y1, s, c, a, b);
}

/*
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  int x, y, d, A, B;
  //swap points if going right -> left
  int xt, yt;
  if (x0 > x1) {
    xt = x0;
    yt = y0;
    x0 = x1;
    y0 = y1;
    x1 = xt;
    y1 = yt;
  }

  x = x0;
  y = y0;
  A = 2 * (y1 - y0);
  B = -2 * (x1 - x0);

  //octant 1
  if ( abs(x1 - x0) >= abs(y1 - y0) ) {

    //octant 1
    if ( A > 0 ) {
      d = A + B/2; //not really division since B = 2B

      while ( x < x1 ) {
        plot( s, c, x, y );
        if ( d > 0 ) {
          y+= 1;
          d+= B;
        }
        x++;
        d+= A;
      } //end octant 1 while
      plot( s, c, x1, y1 );
    } //end octant 1
  }

} //end draw_line
*/
