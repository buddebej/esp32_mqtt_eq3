#include "esp_log.h"
#include "driver/ledc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// http://icircuit.net/esp-idf-lets-control-servo-using-esp32/2073
// https://github.com/sankarcheppali/esp_idf_esp32_posts/blob/master/network_servo/main/network_servo.c

#define minValue 900  //  duty value for 0
#define maxValue  3800 // duty value for 180
#define ServoControlPin 22

int delta = maxValue - minValue;;
int duty;
static const char *HEAT_TAG = "Heating";



void setAngle(int target_angle){
    ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty+ (delta*(target_angle/180.0)) );
    ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0); 
}

void heating_init(){
    ESP_LOGI(HEAT_TAG, "init");

    // init servo
    duty = minValue ; 
	ledc_timer_config_t timer_conf;
	timer_conf.bit_num    = LEDC_TIMER_15_BIT;
	timer_conf.freq_hz    = 50;
	timer_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
	timer_conf.timer_num  = LEDC_TIMER_0;
	ledc_timer_config(&timer_conf);

	ledc_channel_config_t ledc_conf;
	ledc_conf.channel    = LEDC_CHANNEL_0;
	ledc_conf.duty       = duty;
	ledc_conf.gpio_num   = ServoControlPin;
	ledc_conf.intr_type  = LEDC_INTR_DISABLE;
	ledc_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
	ledc_conf.timer_sel  = LEDC_TIMER_0;
	ledc_channel_config(&ledc_conf);

}   

void heating_on(){
    ESP_LOGI(HEAT_TAG, "turned on");
 	setAngle(180);
 	vTaskDelay(1500 / portTICK_PERIOD_MS);
 	ledc_stop(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, 0);
}

void heating_off(){
    ESP_LOGI(HEAT_TAG, "turned off");
 	setAngle(0);
 	vTaskDelay(1500 / portTICK_PERIOD_MS);
 	ledc_stop(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, 0);
}