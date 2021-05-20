enum E1 {
  abc,
  def,
  hij
};

typedef enum {
  klm,
  nop
} E2;

int main()
{
  enum E1 x = def;
  E2 y = nop;
  return 0;
}
