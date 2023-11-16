//
// Created by reprise on 2023/10/29.
//
#include <stdio.h>

int a[12][12], b[12][12];

int main() {
    int t, n, x;
    scanf("%d%d", &t, &x);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int flag1 = 0, flag2 = 0, flag4 = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &a[j][k]);
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int p = 1;
                b[j][k] = a[j][k];
                for (; p < x && k + p < n; p++) {
                    b[j][k] &= a[j][k + p];
                }
                if (b[j][k] & 1 && p == x) {
                    flag1 = 1;
                } else if (b[j][k] & 2 && p == x) {
                    flag2 = 1;
                } else if (b[j][k] & 4 && p == x) {
                    flag4 = 1;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int p = 1;
                b[k][j] = a[k][j];
                for (; p < x && k + p < n; p++) {
                    b[k][j] &= a[k + p][j];
                }
                if (b[k][j] & 1 && p == x) {
                    flag1 = 1;
                } else if (b[k][j] & 2 && p == x) {
                    flag2 = 1;
                } else if (b[k][j] & 4 && p == x) {
                    flag4 = 1;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int p = 0;
                b[j][k] = a[j][k];
                for (; p < x && (j + p) < n && (k + p) < n; p++) {
                    b[j][k] &= a[j + p][k + p];
                }
                if (b[j][k] & 1 && p == x) {
                    flag1 = 1;
                } else if (b[j][k] & 2 && p == x) {
                    flag2 = 1;
                } else if (b[j][k] & 4 && p == x) {
                    flag4 = 1;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int p = 0;
                b[j][k] = a[j][k];
                for (; p < x && (j - p) >= 0 && (k + p) < n; p++) {
                    b[j][k] &= a[j - p][k + p];
                }
                if (b[j][k] & 1 && p == x) {
                    flag1 = 1;
                } else if (b[j][k] & 2 && p == x) {
                    flag2 = 1;
                } else if (b[j][k] & 4 && p == x) {
                    flag4 = 1;
                }
            }
        }

        if (flag1 && !flag2 && !flag4) {
            printf("1\n");
        } else if (!flag1 && flag2 && !flag4) {
            printf("2\n");
        } else if (!flag1 && !flag2 && flag4) {
            printf("4\n");
        } else {
            printf("draw\n");
        }
    }

    return 0;
}

/*for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[j][k] == 1) {
                    int found = 1;
                    for (int p = 1; p < x; p++) {
                        if (a[j][k + p] != 1) {
                            found = 0;
                            break;
                        }
                    }
                    if (found) {
                        flag1 = 1;
                    }
                }
                if (a[j][k] == 2) {
                    int found = 1;
                    for (int p = 1; p < x; p++) {
                        if (a[j][k + p] != 2) {
                            found = 0;
                            break;
                        }
                    }
                    if (found) {
                        flag2 = 1;
                    }
                }
                if (a[j][k] == 4) {
                    int found = 1;
                    for (int p = 1; p < x; p++) {
                        if (a[j][k + p] != 4) {
                            found = 0;
                            break;
                        }
                    }
                    if (found) {
                        flag4 = 1;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[k][j] == 1) {
                    int found = 1;
                    for (int p = 1; p < x; p++) {
                        if (a[k + p][j] != 1) {
                            found = 0;
                            break;
                        }
                    }
                    if (found) {
                        flag1 = 1;
                    }
                }
                if (a[j][k] == 2) {
                    int found = 1;
                    for (int p = 1; p < x; p++) {
                        if (a[k + p][j] != 2) {
                            found = 0;
                            break;
                        }
                    }
                    if (found) {
                        flag2 = 1;
                    }
                }
                if (a[j][k] == 4) {
                    int found = 1;
                    for (int p = 1; p < x; p++) {
                        if (a[k + p][j] != 4) {
                            found = 0;
                            break;
                        }
                    }
                    if (found) {
                        flag4 = 1;
                    }
                }
            }
        }*/