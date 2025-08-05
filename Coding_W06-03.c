#include <stdio.h>

int main() { // จุดเริ่มต้นของโปรแกรม
    // ประกาศตัวแปร กำหนดค่าเริ่มต้น
    int x = 12,y = 7,z = 12;
    
    printf("x > y: %d\n", x > y); // 1 (true)
    printf("x < z: %d\n", x < z); // 0 (false)
    printf("x == z: %d\n", x == z); // 1 (true)
    printf("x != y: %d\n", x != y); // 1 (true)
    printf("!(2*5 >= y)||(5!=(5/3)) : %d\n", !(2*5 >= y) || (5 != (5/3))); // 1 (true)
    printf("!(x , y) : %d\n", !(x, y)); // 0 (false)
    printf("(x + y) > (z * 2) : %d\n", (x + y) > (z * 2)); // 0 (false)
    printf("(x %% 2 == 0)||(y %% 2 == 1) : %d\n", (x % 2 == 0) || (y % 2 == 1)); // 1 (true)
    printf("(x > y) && (z < y) : %d\n", (x > y) && (z < y)); // 0 (false)

    return 0; // จบโปรแกรม
}