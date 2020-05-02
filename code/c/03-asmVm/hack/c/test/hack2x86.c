int16_t D = 0, A = 0, PC = 0, IR = 0;

#define FETCH IR = im[PC]
#define IA    A = IR
#define IC ()


  a = (I & 0x1000) >> 12;
  c = (I & 0x0FC0) >>  6;
  d = (I & 0x0038) >>  3;
  j = (I & 0x0007) >>  0;
