#include <string>
#include <iostream>

inline void output_prompt()
{
  using namespace std;
  cout << '\n' << char(032) << char(032) << "post-";
  cout << "prompt";
  cout << '\n';
  cout << '\n' << char(032) << char(032) << "pre-prompt" << '\n';
  cout << "(dummy-gdb) ";
  cout << '\n' << char(032) << char(032) << "prompt" << '\n';
}

inline void bmain()
{
  using namespace std;
  cout << "Breakpoint 1 at 0x8049145: file a.c, line 3." << '\n';
}

inline void run()
{
  using namespace std;
  cout << '\n' << char(032) << char(032);
  cout << "breakpoint 1" << '\n';
  cout << '\n';
  cout << "Breakpoint 1,";
  cout << '\n' << char(032) << char(032) << "frame-begin 0 0x8049145" << '\n';
  cout << "main () at a.c:3" << '\n';
  cout << '\n' << char(032) << char(032);
#ifdef __CYGWIN__
  cout << "source d:/home/khasegawa/lang/53_GNU_tool/emacs/a.c:3:13:beg:0x8049145" << '\n';  
#else  
  cout << "source /home/khasegawa/lang/53_GNU_tool/emacs/a.c:3:13:beg:0x8049145" << '\n';
#endif  
  cout << '\n' << char(032) << char(032) << "stopped" << '\n';
}

int main()
{
  using namespace std;
  while (1) {
    output_prompt();
    string command;
    getline(cin, command);
    if (command == "quit")
      return 0;
    if (command == "b main")
      bmain();
    else if (command == "run")
      run();
    else if (!command.empty())
      cout << command << '\n';
  }
  return 0;
}
