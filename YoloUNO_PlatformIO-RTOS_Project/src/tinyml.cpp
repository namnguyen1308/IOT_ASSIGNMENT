/**
 * Feature mapping của model (theo thứ tự input[]):
 *   [0] temp              - Nhiệt độ không khí (°C)
 *   [1] humidity          - Độ ẩm tương đối (%)
 *   [2] velocity          - Vận tốc không khí (m/s)  -- mặc định 0.1
 *   [3] clo               -- mặc định 1.0 (quần áo văn phòng)
 *   [4] met               -- mặc định 1.2 (ngồi làm việc)
 *   [5] outdoor_temp      -- mặc định giống temp (chưa có cảm biến ngoài trời)
 *   [6] gender            -- mặc định 1 (Male)
 *   [7] age               -- mặc định 1 (Young Adult, 19-35 tuổi)
 *   [8] season            -- mặc định 1 (Summer)
 *   [9] bmi               -- mặc định 22.0 (BMI trung bình)
 *  [10] temp_outdoor_diff -- = temp - outdoor_temp = 0.0 (khi dùng cùng giá trị)
 *
 * Label đầu ra:
 *   0 → Khó chịu (Uncomfortable)
 *   1 → Bình thường (Neutral)
 *   2 → Dễ chịu   (Comfortable)
 */

#include "tinyml.h"

// -------- Cấu hình giá trị mặc định cho các feature không đo được --------
#define DEFAULT_VELOCITY        0.1   // m/s  - tốc độ gió nhẹ trong phòng
#define DEFAULT_CLO             1.0   // clo  - quần áo văn phòng tiêu chuẩn
#define DEFAULT_MET             1.2   // met  - ngồi làm việc
#define DEFAULT_GENDER          1.0   // 1 = Male
#define DEFAULT_AGE_GROUP       1.0   // 1 = Young Adult (19-35)
#define DEFAULT_SEASON          1.0   // 1 = Summer
#define DEFAULT_BMI             22.0  // kg/m² - BMI trung bình

// -------- Số feature và số class --------
#define N_FEATURES  11
#define N_CLASSES    3

static const char *COMFORT_LABELS[N_CLASSES] = {
    "Kho chiu (Uncomfortable)",
    "Binh thuong (Neutral)",
    "De chiu   (Comfortable)"
};

// -------------------------------------------------------------------------
void tiny_ml_task(void *pvParameters)
{
    SensorContext_t *context = (SensorContext_t *)pvParameters;

    Serial.println("[TinyML] Task started. Waiting for sensor data...");

    while (1)
    {
        // Chờ semaphore từ task temp_humi_monitor (báo có dữ liệu mới)
        if (xSemaphoreTake(context->semTempUpdate, portMAX_DELAY) == pdTRUE)
        {
            float temperature = 0.0f;
            float humidity    = 0.0f;

            // Lấy dữ liệu an toàn qua mutex
            if (xSemaphoreTake(context->dataMutex, pdMS_TO_TICKS(500)) == pdTRUE)
            {
                temperature = context->temperature;
                humidity    = context->humidity;
                xSemaphoreGive(context->dataMutex);
            }
            else
            {
                Serial.println("[TinyML] Could not acquire dataMutex, skipping.");
                continue;
            }

            // ---- Xây dựng vector feature ----
            //
            // outdoor_temp: không có cảm biến ngoài → dùng chính temperature
            // temp_outdoor_diff = temp - outdoor_temp = 0
            double outdoor_temp     = (double)temperature;
            double temp_outdoor_diff = (double)(temperature - outdoor_temp);

            double input[N_FEATURES] = {
                (double)temperature,      // [0] temp
                (double)humidity,         // [1] humidity
                DEFAULT_VELOCITY,         // [2] velocity
                DEFAULT_CLO,              // [3] clo
                DEFAULT_MET,              // [4] met
                outdoor_temp,             // [5] outdoor_temp
                DEFAULT_GENDER,           // [6] gender
                DEFAULT_AGE_GROUP,        // [7] age (group)
                DEFAULT_SEASON,           // [8] season
                DEFAULT_BMI,              // [9] bmi
                temp_outdoor_diff         // [10] temp_outdoor_diff
            };

            // ---- Chạy inference với model Random Forest ----
            double output[N_CLASSES] = {0.0, 0.0, 0.0};
            score(input, output);

            // ---- Chọn class có xác suất cao nhất ----
            int predicted_class = 0;
            double max_prob = output[0];
            for (int i = 1; i < N_CLASSES; i++)
            {
                if (output[i] > max_prob)
                {
                    max_prob = output[i];
                    predicted_class = i;
                }
            }

            // ---- In kết quả ----
            Serial.println("------------------------------");
            Serial.print("[TinyML] Input  -> Temp: ");
            Serial.print(temperature, 1);
            Serial.print(" C,  Humidity: ");
            Serial.print(humidity, 1);
            Serial.println(" %");

            Serial.print("[TinyML] Scores -> ");
            for (int i = 0; i < N_CLASSES; i++)
            {
                Serial.print("Class ");
                Serial.print(i);
                Serial.print(": ");
                Serial.print(output[i] * 100.0, 1);
                Serial.print("%  ");
            }
            Serial.println();

            Serial.print("[TinyML] Result -> ");
            Serial.println(COMFORT_LABELS[predicted_class]);
            Serial.println("------------------------------");
        }
    }
}