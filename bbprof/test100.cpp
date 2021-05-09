#include <string>
#include <cstdio>

namespace cmdline {
  using namespace std;
  void setup(int argc, char** argv)
  {
  }
  string input;
}

FILE* c_compiler_in;

namespace c_compiler {
  using namespace std;
  namespace error {
    namespace cmdline {
      void open(string fn)
      {
      }
    }
  }
  struct file_t {
    file_t()
    {
    }
    file_t(string fn, int n)
    {
    }
  };
  namespace parse {
    file_t position;
  }
}

int main(int argc, char** argv)
{
  using namespace std;
  using namespace c_compiler;
  cmdline::setup(argc,argv);
  if ( !cmdline::input.empty() ){
    c_compiler_in = fopen(cmdline::input.c_str(),"r");
    if ( !c_compiler_in ){
      error::cmdline::open(cmdline::input);
      exit(1);
    }
    parse::position = file_t(cmdline::input,1);
  }
  return 0;
}
