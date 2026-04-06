/* Random Forest Model converted by m2cgen */
#ifndef MODEL_H
#define MODEL_H

#include <string.h>
void add_vectors(double *v1, double *v2, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] + v2[i];
}
void mul_vector_number(double *v1, double num, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] * num;
}
void score(double * input, double * output) {
    double var0[2];
    double var1[2];
    double var2[2];
    double var3[2];
    double var4[2];
    double var5[2];
    double var6[2];
    double var7[2];
    double var8[2];
    double var9[2];
    double var10[2];
    if (input[1] <= 42.5) {
        memcpy(var10, (double[]){0.0, 1.0}, 2 * sizeof(double));
    } else {
        memcpy(var10, (double[]){1.0, 0.0}, 2 * sizeof(double));
    }
    double var11[2];
    if (input[0] <= 25.5) {
        memcpy(var11, (double[]){1.0, 0.0}, 2 * sizeof(double));
    } else {
        memcpy(var11, (double[]){0.25, 0.75}, 2 * sizeof(double));
    }
    add_vectors(var10, var11, 2, var9);
    double var12[2];
    if (input[1] <= 61.5) {
        memcpy(var12, (double[]){0.5, 0.5}, 2 * sizeof(double));
    } else {
        memcpy(var12, (double[]){1.0, 0.0}, 2 * sizeof(double));
    }
    add_vectors(var9, var12, 2, var8);
    double var13[2];
    if (input[0] <= 27.0) {
        memcpy(var13, (double[]){1.0, 0.0}, 2 * sizeof(double));
    } else {
        memcpy(var13, (double[]){0.3333333333333333, 0.6666666666666666}, 2 * sizeof(double));
    }
    add_vectors(var8, var13, 2, var7);
    double var14[2];
    if (input[1] <= 64.0) {
        memcpy(var14, (double[]){0.25, 0.75}, 2 * sizeof(double));
    } else {
        memcpy(var14, (double[]){1.0, 0.0}, 2 * sizeof(double));
    }
    add_vectors(var7, var14, 2, var6);
    double var15[2];
    if (input[0] <= 25.5) {
        memcpy(var15, (double[]){1.0, 0.0}, 2 * sizeof(double));
    } else {
        memcpy(var15, (double[]){0.5, 0.5}, 2 * sizeof(double));
    }
    add_vectors(var6, var15, 2, var5);
    double var16[2];
    if (input[0] <= 50.5) {
        memcpy(var16, (double[]){1.0, 0.0}, 2 * sizeof(double));
    } else {
        memcpy(var16, (double[]){0.0, 1.0}, 2 * sizeof(double));
    }
    add_vectors(var5, var16, 2, var4);
    double var17[2];
    if (input[0] <= 27.0) {
        memcpy(var17, (double[]){1.0, 0.0}, 2 * sizeof(double));
    } else {
        memcpy(var17, (double[]){0.5, 0.5}, 2 * sizeof(double));
    }
    add_vectors(var4, var17, 2, var3);
    double var18[2];
    if (input[0] <= 27.0) {
        memcpy(var18, (double[]){1.0, 0.0}, 2 * sizeof(double));
    } else {
        memcpy(var18, (double[]){0.25, 0.75}, 2 * sizeof(double));
    }
    add_vectors(var3, var18, 2, var2);
    double var19[2];
    if (input[1] <= 64.0) {
        memcpy(var19, (double[]){0.6666666666666666, 0.3333333333333333}, 2 * sizeof(double));
    } else {
        memcpy(var19, (double[]){1.0, 0.0}, 2 * sizeof(double));
    }
    add_vectors(var2, var19, 2, var1);
    mul_vector_number(var1, 0.1, 2, var0);
    memcpy(output, var0, 2 * sizeof(double));
}


#endif