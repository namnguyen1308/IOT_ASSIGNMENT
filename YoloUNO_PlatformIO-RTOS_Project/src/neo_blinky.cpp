#include "neo_blinky.h"
#include "global.h"  // For SensorContext_t

// NeoPixel configuration
#define LED_COUNT 1
#define NEO_PIN 48  // GPIO pin for NeoPixel (adjust based on your board)

// Color definitions (RGB values)
#define COLOR_NORMAL    0, 255, 0     // Green for normal humidity (0-40%)
#define COLOR_OPTIMAL   0, 0, 255     // Blue for optimal humidity (40-70%)
#define COLOR_HIGH      255, 0, 0     // Red for high humidity (>70%)

// Humidity thresholds
#define HUMIDITY_LOW_THRESHOLD     40.0
#define HUMIDITY_OPTIMAL_THRESHOLD 70.0

// Semaphore timeout in milliseconds
#define SEMAPHORE_TIMEOUT_MS 100

void neo_blinky(void *pvParameters) {
    // Get the shared context with sensor data and semaphores
    SensorContext_t *context = (SensorContext_t *)pvParameters;
    
    // Initialize NeoPixel strip
    Adafruit_NeoPixel strip(LED_COUNT, NEO_PIN, NEO_GRB + NEO_KHZ800);
    strip.begin();
    strip.clear();
    strip.show();
    
    Serial.println("NeoPixel task started");
    
    // Current humidity level tracking
    float currentHumidity = 0.0;
    int currentColorState = -1;  // -1 = unknown, 0 = normal, 1 = optimal, 2 = high
    int newColorState = -1;
    
    while(1) {
        // Wait for humidity semaphores with timeout
        // Check for LOW humidity (normal)
        if (xSemaphoreTake(context->semHumiUpdate, portMAX_DELAY) == pdTRUE) {
            if (context->humidity <= HUMIDITY_LOW_THRESHOLD) {
                newColorState = 0;  // Normal
                Serial.println("NeoPixel: Normal humidity detected (0-40%)");
            }
            // Check for OPTIMAL humidity
            else if (context->humidity > HUMIDITY_LOW_THRESHOLD && context->humidity <= HUMIDITY_OPTIMAL_THRESHOLD) {
                newColorState = 1;  // Optimal
                Serial.println("NeoPixel: Optimal humidity detected (40-70%)");
            }
            // Check for HIGH humidity
            else {
                newColorState = 2;  // High
                Serial.println("NeoPixel: High humidity detected (>70%)");
            }
        }
    }
        
        // Also read actual humidity value for debugging
        if (xSemaphoreTake(context->dataMutex, portMAX_DELAY) == pdTRUE) {
            currentHumidity = context->humidity;
            xSemaphoreGive(context->dataMutex);
        }
        
        // Update LED color if state changed
        if (newColorState != -1 && newColorState != currentColorState) {
            currentColorState = newColorState;
            
            // Set LED color based on humidity level
            switch(currentColorState) {
                case 0:  // Normal (0-40%)
                    strip.setPixelColor(0, strip.Color(COLOR_NORMAL));
                    break;
                case 1:  // Optimal (40-70%)
                    strip.setPixelColor(0, strip.Color(COLOR_OPTIMAL));
                    break;
                case 2:  // High (>70%)
                    strip.setPixelColor(0, strip.Color(COLOR_HIGH));
                    break;
            }
            strip.show();
            
            // Log the color change with actual humidity value
            Serial.printf("NeoPixel updated: Humidity = %.1f%%, ", currentHumidity);
            switch(currentColorState) {
                case 0: Serial.println("Color = GREEN (NORMAL)"); break;
                case 1: Serial.println("Color = BLUE (OPTIMAL)"); break;
                case 2: Serial.println("Color = RED (HIGH)"); break;
            }
        }
        
        // Reset newColorState for next iteration
        newColorState = -1;
        
        // Small delay to prevent task from hogging CPU
        vTaskDelay(pdMS_TO_TICKS(50));
    }
