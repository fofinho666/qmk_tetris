#ifndef XORSHIFT_H
#define XORSHIFT_H

// 8-bit version of Xorshift
// Source at https://blog.goo.ne.jp/sim00/e/33b576696be51efbb3eab4b5c61ffb87

struct Xorshift {
  uint8_t x, y, z, t;
};
typedef struct Xorshift Xorshift;

void xorshift_init(Xorshift* p, uint8_t x, uint8_t y, uint8_t z, uint8_t t);
uint8_t xorshift_next(Xorshift* p);

#endif // XORSHIFT_H
