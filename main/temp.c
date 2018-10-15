#include "DHT22.h"
#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "rom/ets_sys.h"
#include "nvs_flash.h"
// #include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"
// #include "mqtt.h"

static const char *TEMP_TAG = "DHT";

// struct T_sensor {
// 	float temp;
// 	float relh;
// };

// struct T_sensor SensorData;

// void DHT_task(void *parameter)
// {
// 	setDHTgpio( 21 );
// 	ESP_LOGI(TEMP_TAG, "init");

// 	while(1) {
	
// 		int ret = readDHT();
// 		errorHandler(ret);
// 		struct T_sensor output_data = *((struct T_sensor*)parameter);  

// 		output_data.temp = getTemperature();
// 		output_data.relh = getHumidity();

// 		ESP_LOGI(TEMP_TAG, "Tmp %.1f\n", getTemperature() )
// 		ESP_LOGI(TEMP_TAG, "Hum %.1f\n", getHumidity() )

// 		parameter = (void*)&output_data;

// 		vTaskDelay( 10000 / portTICK_RATE_MS );
// 	}
// }

// void temp_init(){
// 	xTaskCreate( &DHT_task, "DHT_task", 2048,  (void*)&SensorData, 5, NULL );
// }

// float getTemp(){
// 	return SensorData.temp;
// }

// float getRelh(){
// 	return SensorData.temp;
// }


void temp_init(){
	setDHTgpio( 21 );
	ESP_LOGI(TEMP_TAG, "init");
}

void getDhtData(){
	int ret = readDHT();
	errorHandler(ret);
}