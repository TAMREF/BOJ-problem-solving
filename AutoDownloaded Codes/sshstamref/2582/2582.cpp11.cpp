#include <stdio.h>
#include <string.h>  // for memcpy()/memset()
//#include <algorithm>  // for min()
//using namespace std;

inline int min(int x, int y) { return (x<y)? x:y; } // for slight speed-up
inline int max(int x, int y) { return (x>y)? x:y; } 

#define MAX_N 32

class BitVector {  // 32-bit로 가정 (일반적 경우는 08_h1_score.cpp처럼)
  private:
    unsigned int data;  // int를 쓰면 31번째 bit 연산이 엉뚱하게 됨
    static int num_on_(unsigned int v) {
        // http://namocom.tistory.com/377
        // http://stackoverflow.com/questions/109023
        //       /how-to-count-the-number-of-set-bits-in-a-32-bit-integer
        v = v - ((v >> 1) & 0x55555555);
        v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
        return (((v + (v >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
        // return __builtin_popcount(v); // 실험시 50% 가량 느림
    }
    static int num_on_table[65536]; // 0부터 2^{16}-1 까지 미리 계산
    static unsigned int mask_table_left[32]; // 0부터 i비트를 1로 한 값을 미리 계산
    static unsigned int mask_table_right[32]; // i부터 N-1비트까지
  public:
    static void init_static_var(int N) {
        for (unsigned int v=0; v<65536; v++) num_on_table[v] = num_on_(v);
        for (int i=0; i<N-1; i++) mask_table_left[i] = (1 << (i+1)) - 1;
        mask_table_left[N-1] = 0;
        for (int i=0; i<N; i++) mask_table_left[N-1] |= (1 << i);
        mask_table_right[0] = mask_table_left[N-1];
        for (int i=1; i<N; i++) 
            mask_table_right[i] = (~mask_table_left[i-1]) & mask_table_left[N-1];
    }
    BitVector() { /* data = 0; */ }  // Coin에서 초기화
    inline bool on(int i) { data |= (1 << i); }
    // inline bool off(int i) { data &= ~(1 << i); }
    // inline bool bit(int i) { return (data & (1 << i)) > 0; }
    inline void flip(int i) { data ^= (1 << i); }
    // inline void flip(void) { data ^= bit_mask_N; }
    inline int num_on(void) {
        return num_on_table[data >> 16] + num_on_table[data & 0xffff];
    }
    inline int num_on_left(int i) {  // 0부터 i비트 까지만 고려
        unsigned int d = data & mask_table_left[i];
        return num_on_table[d >> 16] + num_on_table[d & 0xffff];
    }
    inline int num_on_right(int i) {  // i부터 N-1비트 까지만 고려
        unsigned int d = data & mask_table_right[i];
        return num_on_table[d >> 16] + num_on_table[d & 0xffff];
    }
};
// static member of class Point
int BitVector::num_on_table[]; 
unsigned int BitVector::mask_table_left[];
unsigned int BitVector::mask_table_right[];

int N;

struct Coin {
    BitVector T[MAX_N]; // (row,col)의 동전이 tail이면 T[row]의 col-bit가 1
    void operator=(const Coin &C) { memcpy(this, &C, sizeof(Coin)); }
    Coin(const Coin &C) { operator=(C); }
    Coin() { memset(this, 0, sizeof(Coin)); }
    inline void flip_col(int j) { for (int i=0; i<N; i++) T[i].flip(j); }
    inline int count_tail(void) {
        int count = 0;
        for (int i=0; i<N; i++) {
            int c = T[i].num_on();
            count += min(c, N-c);
        }
        return count;
    }
    inline int count_tail_left(int col) { // 0부터 col열까지만 고려
        int count = 0;
        for (int i=0; i<N; i++) {
            int c = T[i].num_on_left(col);
            count += min(c, col+1-c);
        }
        return count;
    }
    inline int count_tail_right(int col) { // col부터 N-1열까지만 고려
        int count = 0;
        for (int i=0; i<N; i++) {
            int c = T[i].num_on_right(col);
            count += min(c, N-col-c);
        }
        return count;
    }
};
int min_tail;
int min_tail_col[MAX_N]; // i부터 N-1 열만 고려했을 때 최소값
int col_prune;
long long num_pruned = 0;

void solve_right(Coin &C, int col) // min_tail_col을 계산
{
    if (col <= col_prune) return;
    min_tail_col[col] = min(min_tail_col[col], C.count_tail_right(col));
    solve_right(C, col-1);

    Coin D(C);
    D.flip_col(col);
    min_tail_col[col] = min(min_tail_col[col], D.count_tail_right(col));
    solve_right(D, col-1);
}

void solve_left(Coin &C, int col)
{
    if (col == N-1) {
        min_tail = min(min_tail, C.count_tail());
    } else {
        bool try_prune = (col >= col_prune);
        if (try_prune) {
            int n_tail = C.count_tail_left(col) + min_tail_col[col+1];
            if (n_tail > min_tail) return;
            solve_left(C, col+1);
            if (n_tail > min_tail) return;
        } else {
            solve_left(C, col+1);
        }
        Coin D(C);
        D.flip_col(col);
        solve_left(D, col+1);
    }
}

void solve(Coin &C)
{
    col_prune = max(0, N/3+1);
    min_tail = MAX_N*MAX_N;
    for (int i=0; i<N; i++) min_tail_col[i] = MAX_N*MAX_N;
    solve_right(C, N-1);
    solve_left(C, 0);
}

int main(void)
{
    scanf("%d", &N);
    BitVector::init_static_var(N);

    char s[N+1];
    Coin C;
    for (int i=0; i<N; i++) {
        scanf("%s", s);
        for (int j=0; j<N; j++) if (s[j] == 'T') C.T[i].on(j);
    }

    solve(C);
    printf("%d\n", min_tail);
}
