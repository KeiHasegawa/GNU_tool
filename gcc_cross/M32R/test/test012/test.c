int main()
{
  asm("nop\ntrap #0x1");
  return 0;
}
