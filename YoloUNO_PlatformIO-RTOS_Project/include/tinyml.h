#ifndef __TINY_ML__
#define __TINY_ML__

#include <Arduino.h>

#include "global.h"

extern "C" {
    // Khai báo tên hàm mặc định mà m2cgen sinh ra để C++ biết đường gọi
    void score(double * input, double * output); 
}

void tiny_ml_task(void *pvParameters);

#endif