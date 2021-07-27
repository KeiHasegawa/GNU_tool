struct option
{
  const char *name;
  int has_arg;
  int *flag;
  int val;
};

extern int getopt_long_only (int argc, char *const *argv,
			     const char *shortopts,
		             const struct option *longopts, int *longind);

struct option my_opt[] = {
  {"hoge", 0, 0, 0 }
};


int main(int argc, char** argv)
{
  int n;
  getopt_long_only(argc, argv, "abc", &my_opt[0], &n);
  return 0;
}
