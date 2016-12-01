#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

typedef std::pair<double, double> Point;
typedef std::vector<Point> Polygon;
typedef std::pair<Point, Point> Line;

inline double sign(const Point p1, const Point p2, const Point p3)
{
    return (p1.first - p3.first) * (p2.second - p3.second) -
      (p2.first - p3.first) * (p1.second - p3.second);
}

// Return true of tri abc contains x.
bool triangle_contains(const double a, const double b, const double c,
                       const double x)
{
  bool b1 = sign(x, a, b) < 0;
  bool b2 = sign(x, b, c) < 0;
  bool b3 = sign(x, c, a) < 0;
  return ((b1 == b2) && (b2 == b3));
}

// O(n) function that checks if the point at index is the tip of an ear.
bool is_ear(const size_t index, const Polygon polygon)
{
  auto a = polygon[index];
  auto b = polygon[(index - 1) % polygon.size()];
  auto c = polygon[(index + 1) % polygon.size()];
  bool result = true;
  for (const auto& point : polygon)
    if (triangle_contains(a, b, c, point))
      result = false;
  return result;
}


// O(n^3) solution.
vector<Line> Triangulate(const Polygon polygon)
{
  size_t num_tris = 0;
  size_t n = polygon.size();
  vector<Line> new_edges;
  while (num_tris < n - 2)
  {
    size_t index = 0;
    while (!is_ear(index, polygon)) index++; // Find next ear to cut
    new_edges.push_back(pair(polygon[(index-1) % n], polygon[(index+1) % n]));
    num_tris++;
    polygon.erase(polygon.begin() + index); // Pop point form polygon.
  }
  return new_edges;
}

// O(n^2) solution.
void Triangulate(const Polygon polygon)
{
  size_t num_tris = 0;
  size_t n = polygon.size();
  unordered_map<Point, bool> ear_status;
  vector<Line> new_edges;

  // Init ear statuses.
  for (size_t index = 0; index < polygon.size(); index++)
    ear_status[a] = is_ear(index, polygon);

  while (num_tris < n - 2)
  {
    for (size_t i = 0; i < polygon.size(); i++)
    {
      const auto point = polygon[i];
      if (ear_status[point])
      {
        new_edges.push_back(pair(polygon[(i-1) % n],
                            polygon[(i+1) % n]));
        ear_status[polygon[(i-1) % n]] = ear_status((i-1) % n, polygon);
        ear_status[polygon[(i+1) % n]] = ear_status((i+1) % n, polygon);
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
  Polygon polygon = { {-67.07, 78.65}, {-39.33, 80.24}, {54.2, 63.59}, {39.67, 33.47},
                      {37.02, 60.94}, {-86.35471,74.6827}, };
  return 0;
}
