int main()
{
#if 1
  asm("nop\ntrap #0x1");
#else  
  asm(".long 0x10f17000");
#endif  
  return 0;
}
