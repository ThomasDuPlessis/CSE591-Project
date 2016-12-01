#include <stdbool.h>

typedef struct Point {
  int x;
  int y;
  bool ear_status;
} Point;

typedef Point[] Polygon;

typedef struct Line {
  Point from;
  Point to;
} Line;

// O(n) function that checks if the point at index is the tip of an ear.
bool is_ear(const int index, const Polygon polygon, int n)
{
  Point a = polygon[index];
  Point b = polygon[(index - 1) % n];
  Point c = polygon[(index + 1) % n];
  bool result = true;
  for (int i = 0; i < n; i++)
    if (triangle_contains(a, b, c, point))
      result = false;
  return result;
}

// O(n^2) solution.
Line* Triangulate(const Polygon polygon, int n)
{
  int num_tris = 0;
  Line[] new_edges = malloc(sizeof(Line) * (n - 2));
  int edges_index = 0;
  // Init ear statuses.
  for (int i = 0; i < n; i++) 
    polygon[i].ear_status = is_ear(i, polygon);

  while (num_tris < n - 2)
  {
    for (size_t i = 0; i < polygon.size(); i++)
    {
      const auto point = polygon[i];
      if (ear_status[point])
      {
        new_edges[edges_index++] = {
          .from = polygon[(index-1) % n];
          .to   = polygon[(index+1) % n];
        };
        polygon.erase(polygon.begin() + i);
        num_tris++;
        break;
      }
    }
  }
  return new_edges;
}


int main(int argc, char *argv[])
{
  return 0;
}
