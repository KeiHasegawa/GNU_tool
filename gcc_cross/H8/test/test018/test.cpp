#include <vector>

extern "C" int printf(const char*, ...);

int main()
{
  using namespace std;
  vector<int> vi = { 1, 2, 3, 4, 5 };
  for (auto i : vi)
    printf("%d\n", i);
  return 0;
}
