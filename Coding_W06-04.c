#include <stdio.h>

int main() {

    // ประกาศตัวแปร กำหนดค่าเริ่มต้น
    double x = 100.0;
    int y = 7, z = 3, a = 2, quantity = 5;
    double total = 500.0, price = 100.0;
    double discount = 20.0, rate = 5.0;
    double score = 85.0, penalty = 2.0;
    int mistake = 3;

    // Expression ที่ 1: x = x - 4.0;
    printf(" 1.x = x - 4.0; \n");
    double x_full_1 = x; // สร้างตัวแแปรสำเนาสำหรับแบบเต็ม
    double x_short_1 = x; // สร้างตัวแแปรสำเนาสำหรับแบบย่อ

    // Full
    x_full_1 = x_full_1 - 4.0;
    printf("   Full (x = x - 4.0;): x = %.2f\n", x_full_1);
    // Short
    x_short_1 -= 4.0;
    printf("   Short (x -= 4.0;):    x = %.2f\n", x_short_1);

    if (x_full_1 == x_short_1) {
        printf("   Result : True\n\n");
    } else {
        printf("   Result : False\n\n");
    }
    // Expression ที่ 2: x = 6.5 * x;
    printf(" 2.x = 6.5 * x; \n");
    double x_full_2 = x; // ใช้ค่า x ล่าสุดจากการคำนวณก่อนหน้า
    double x_short_2 = x;

    // Full
    x_full_2 = 6.5 * x_full_2;
    printf("   Full (x = 6.5 * x;): x = %.2f\n", x_full_2);
    // Short
    x_short_2 *= 6.5; // หรือ x *= 6.5;
    printf("   Short (x *= 6.5;):    x = %.2f\n", x_short_2);

    if (x_full_2 == x_short_2) {
        printf("   Result : True\n\n");
    } else {
        printf("   Result : False\n\n");
    }

    // Expression ที่ 3: x = x %% (y + z * a);
    // ตัวแปร x ในที่นี้ต้องเป็นจำนวนเต็ม เนื่องจากใช้ modulo operator (%)
    printf(" 3.x = x %% (y + z * a); \n");
    int x_int_full_3 = (int)x; // แปลง x เป็น int เพื่อใช้กับ %
    int x_int_short_3 = (int)x;
    int divisor_3 = y + z * a; // คำนวณส่วนหาร (7 + 3 * 2) = (7 + 6) = 13

    // Full
    x_int_full_3 = x_int_full_3 % divisor_3;
    printf("   Full (x = x %% (y + z * a);): x = %d (เมื่อ x เริ่มต้นเป็น %d)\n", x_int_full_3, (int)x);
    // Short
    x_int_short_3 %= divisor_3;
    printf("   Short (x %%= (y + z * a);):    x = %d\n", x_int_short_3);

    if (x_int_full_3 == x_int_short_3) {
        printf("   Result : True\n\n");
    } else {
        printf("   Result : False\n\n");
    }

    // Expression ที่ 4: x = x / (2.0 * x);
    printf(" 4.x = x / (2.0 * x); \n");
    double x_full_4 = x; // ใช้ค่า x ล่าสุด
    double x_short_4 = x;
    double divisor_4 = 2.0 * x; // คำนวณตัวหาร: 2.0 * (ค่า x ล่าสุด)
    
    // ตรวจสอบเพื่อป้องกันการหารด้วยศูนย์
    if (divisor_4 == 0) {
        printf("   ไม่สามารถหารด้วยศูนย์ได้ใน Expression นี้\n\n");
    } else {
        // Full
        x_full_4 = x_full_4 / divisor_4;
        printf("   Full (x = x / (2.0 * x);): x = %.4f\n", x_full_4);
        // Short
        x_short_4 /= divisor_4; // หรือ x /= (2.0 * x);
        printf("   Short (x /= (2.0 * x);):    x = %.4f\n", x_short_4);

        // เปรียบเทียบผลลัพธ์ อาจมีปัญหาเรื่อง floating point precision
        // จึงควรใช้การเปรียบเทียบความแตกต่างน้อยกว่าค่า epsilon
        if (x_full_4 == x_short_4) {
            printf("   Result : True\n\n");
        } else {
            printf("   Result : False\n\n");
        }
    }


    // Expression ที่ 5: total = total + (price * quantity - discount);
    printf(" 5.total = total + (price * quantity - discount); \n");
    double total_full_5 = total;
    double total_short_5 = total;
    double value_to_add_5 = (price * quantity - discount); // (100 * 5 - 20) = (500 - 20) = 480

    // Full
    total_full_5 = total_full_5 + value_to_add_5;
    printf("   Full (total = total + (...);): total = %.2f\n", total_full_5);
    // Short
    total_short_5 += value_to_add_5;
    printf("   Short (total += (...);):       total = %.2f\n", total_short_5);

    if (total_full_5 == total_short_5) {
        printf("   Result : True\n\n");
    } else {
        printf("   Result : False\n\n");
    }

    // Expression ที่ 6: x = x * (1 + rate / 100);
    printf(" 6.x = x * (1 + rate / 100); \n");
    double x_full_6 = x;
    double x_short_6 = x;
    double factor_6 = (1 + rate / 100.0); // (1 + 5.0 / 100.0) = (1 + 0.05) = 1.05

    // Full
    x_full_6 = x_full_6 * factor_6;
    printf("   Full (x = x * (...);): x = %.2f\n", x_full_6);

    // Short
    x_short_6 *= factor_6;
    printf("   Short (x *= (...);):    x = %.2f\n", x_short_6);

    if (x_full_6 == x_short_6) {
        printf("   Result : True\n\n");
    } else {
        printf("   Result : False\n\n");
    }

    // Expression ที่ 7: score = score - (penalty * (mistake + 1));
    printf(" 7.score = score - (penalty * (mistake + 1)); \n");
    double score_full_7 = score;
    double score_short_7 = score;
    double deduction_7 = (penalty * (mistake + 1)); // (2.0 * (3 + 1)) = (2.0 * 4) = 8.0

    // Full
    score_full_7 = score_full_7 - deduction_7;
    printf("   Full (score = score - (...);): score = %.2f\n", score_full_7);

    // Short
    score_short_7 -= deduction_7;
    printf("   Short (score -= (...);):       score = %.2f\n", score_short_7);

    if (score_full_7 == score_short_7) {
        printf("   Result : True\n\n");
    } else {
        printf("   Result : False\n\n");
    }

    return 0; // จบโปรแกรม
}