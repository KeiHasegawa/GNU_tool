int a[1024];

int main()
{
  while (1) {
    for (int i = 0 ; i != sizeof a/sizeof a[0] ; ++i)
      a[i] = i;
  }
  return 0;
}
