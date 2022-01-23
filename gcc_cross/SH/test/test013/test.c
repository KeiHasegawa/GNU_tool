int main()
{
  asm("trapa	#0xc3");
  return 0;
}
