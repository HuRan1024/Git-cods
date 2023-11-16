//
// Created by reprise on 2023/10/22.
//
#include <stdio.h>
#include <math.h>

int main() {
    int xa, xb, xc, ya, yb, yc;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    if (xa != xb && ya != yb) {
        printf("%d\n", abs(xa - xb) + abs(ya - yb));    //打印路程
        if ((xc != xa && yc != yb) ||
            (xc == xa && ((yc > ya && yc > yb) || (yc < ya && yc < yb))) ||
            (yc == yb && ((xc > xa && xc > xb) || (xc < xa && xc < xb)))) {
            if (yb > ya) {
                for (int i = 0; i < yb - ya; i++) {
                    printf("U");
                }
            } else if (yb < ya) {
                for (int i = 0; i < ya - yb; i++) {
                    printf("D");
                }
            }
            if (xb > xa) {
                for (int i = 0; i < xb - xa; i++) {
                    printf("R");
                }
            } else {
                for (int i = 0; i < xa - xb; i++) {
                    printf("L");
                }
            }
        } else {
            if (xb > xa) {
                for (int i = 0; i < xb - xa; i++) {
                    printf("R");
                }
            } else {
                for (int i = 0; i < xa - xb; i++) {
                    printf("L");
                }
            }
            if (yb > ya) {
                for (int i = 0; i < yb - ya; i++) {
                    printf("U");
                }
            } else if (yb < ya) {
                for (int i = 0; i < ya - yb; i++) {
                    printf("D");
                }
            }
        }
    } else if (xa == xb) {
        if (xc != xa || (yc > ya && yc > yb) || (yc < yb && yc < ya)) {          //判断c是否挡路，即是否在同一直线上并且在起终点之间。
            printf("%d\n", abs(ya - yb));
            if (yb > ya) {
                for (int i = 0; i < yb - ya; i++) {
                    printf("U");
                }
            } else if (yb < ya) {
                for (int i = 0; i < ya - yb; i++) {
                    printf("D");
                }
            }
        } else {
            printf("%d\n", abs(ya - yb) + 2);
            if (yb > ya) {
                printf("R");
                for (int i = 0; i < yb - ya; i++) {
                    printf("U");
                }
                printf("L");
                /*for (int i = yc - ya + 1; i <= yb - yc; i++) {
                    printf("U");
                }*/
            } else {
                printf("R");
                for (int i = 0; i < ya - yb; i++) {
                    printf("D");
                }
                printf("L");
                /*for (int i = ya - yc + 1; i <= yc - yb; i++) {
                    printf("D");
                }*/
            }
        }
    } else {
        if (yc != ya || (xc > xa && xc > xb) || (xc < xb && xc < xa)) {          //判断c是否挡路，即是否在同一直线上并且在起终点之间。
            printf("%d\n", abs(xa - xb));
            if (xb > xa) {
                for (int i = 0; i < xb - xa; i++) {
                    printf("R");
                }
            } else if (xb < xa) {
                for (int i = 0; i < xa - xb; i++) {
                    printf("L");
                }
            }
        } else {
            printf("%d\n", abs(xa - xb) + 2);
            if (xb > xa) {
                printf("U");
                for (int i = 0; i < xb - xa; i++) {
                    printf("R");
                }
                printf("D");
                /*for (int i = xc - xa + 1; i <= xb - xc; i++) {
                    printf("R");
                }*/
            } else {
                printf("U");
                for (int i = 0; i < xa - xb; i++) {
                    printf("L");
                }
                printf("D");
                /*for (int i = xa - xc + 1; i <= xc - xb; i++) {
                    printf("D");
                }*/
            }
        }
    }
    return 0;
}