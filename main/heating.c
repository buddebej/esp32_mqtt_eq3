static const char *HEAT_TAG = "Heating";
const int ServoPin = 22;

// http://icircuit.net/esp-idf-lets-control-servo-using-esp32/2073

void heating_init(){
    ESP_LOGI(HEAT_TAG, "init");
    // ledcSetup(1, 166, 8); 
}   

void heating_on(){
    ESP_LOGI(HEAT_TAG, "turned on");
 	// ledcWrite(ServoPin, 100);
}

void heating_off(){
    ESP_LOGI(HEAT_TAG, "turned off");
	// ledcWrite(ServoPin, 0);
}