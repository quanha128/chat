#include <stdio.h>
#define REG_PIDATA (*((volatile uint32_t*)0x400C0800))
#define REG_PIIE (*((volatile uint32_t*)0x400C0838))

int main() {
    REG_PIIE |= (1 << 4);
    int status = (REG_PIDATA & 0x10) >> 4;
    printf("%s\n", (status==1)?"[H]":"[L]");
    return 0;
}