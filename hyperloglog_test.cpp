#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
int getFirstOne(int i) {
  int cnt = 0;
  for (;;) {
    if (i % 2)
      break;
    i >>= 1;
    cnt++;
  }
  return cnt;
}
void test1() {

  srand(time(NULL));

  double sum, sum2, arv, arv2;
  int row = 10;

  for (size_t j = 0; j < row; j++) {
    int max_pos = 0;
    for (size_t i = 0; i < 1000000; i++) {
      int r = rand();
      int pos = getFirstOne(r);
      max_pos = max(max_pos, pos);
    }
    sum += pow(2, max_pos);
    sum2 += 1.0 / (double)pow(2, max_pos);
    // std::cout << max_pos << " " << pow(2, max_pos) << std::endl;
  }
  arv = sum / row;
  arv2 = (double)row / sum2;
  std::cout << arv << std::endl;
  std::cout << arv2 << std::endl;
}
uint64_t MurmurHash64A(const void *key, int len, unsigned int seed) {
  const uint64_t m = 0xc6a4a7935bd1e995;
  const int r = 47;
  uint64_t h = seed ^ (len * m);
  const uint8_t *data = (const uint8_t *)key;
  const uint8_t *end = data + (len - (len & 7));

  while (data != end) {
    uint64_t k;

#if (BYTE_ORDER == LITTLE_ENDIAN)
#ifdef USE_ALIGNED_ACCESS
    memcpy(&k, data, sizeof(uint64_t));
#else
    k = *((uint64_t *)data);
#endif
#else
    k = (uint64_t)data[0];
    k |= (uint64_t)data[1] << 8;
    k |= (uint64_t)data[2] << 16;
    k |= (uint64_t)data[3] << 24;
    k |= (uint64_t)data[4] << 32;
    k |= (uint64_t)data[5] << 40;
    k |= (uint64_t)data[6] << 48;
    k |= (uint64_t)data[7] << 56;
#endif

    k *= m;
    k ^= k >> r;
    k *= m;
    h ^= k;
    h *= m;
    data += 8;
  }

  switch (len & 7) {
  case 7:
    h ^= (uint64_t)data[6] << 48; /* fall-thru */
  case 6:
    h ^= (uint64_t)data[5] << 40; /* fall-thru */
  case 5:
    h ^= (uint64_t)data[4] << 32; /* fall-thru */
  case 4:
    h ^= (uint64_t)data[3] << 24; /* fall-thru */
  case 3:
    h ^= (uint64_t)data[2] << 16; /* fall-thru */
  case 2:
    h ^= (uint64_t)data[1] << 8; /* fall-thru */
  case 1:
    h ^= (uint64_t)data[0];
    h *= m; /* fall-thru */
  };

  h ^= h >> r;
  h *= m;
  h ^= h >> r;
  return h;
}

int hllPatLen(unsigned char *ele, size_t elesize, long *regp) {
  uint64_t hash, bit, index;
  int count;

  /* 首先算出一个项的哈希值 */
  hash = MurmurHash64A(ele, elesize, 0xadc83b19ULL);
  /* 然后后面14位算出坐标桶坐标 */
  index = hash & ((1 << 14) - 1); /* Register index. */ /* 计算坐标 */
  hash >>= 14; /* Remove bits used to address the register. */ /* 将后14位去除 */
  /* 然后计算这剩下五十位的后置0的数量，这里是为了保证哈希值不为0吧盲猜*/
  hash |= ((uint64_t)1 << (64 - 14)); /* Make sure the loop terminates
                                       and count will be <= Q+1. */
  bit = 1;
  count = 1; /* Initialized to 1 since we count the "00000...1" pattern. */
  /* 计算0的数量 */
  while ((hash & bit) == 0) {
    count++;
    bit <<= 1;
  }
  *regp = (int)index;
  return count;
}

void test2() {
  long reg;
  char s[] = "abc";
  int zerolen = hllPatLen((unsigned char *)s, 3, &reg);
  std::cout << zerolen << " " << reg << std::endl;
}

int main(int argc, char const *argv[]) {
  test2();
  return 0;
}
