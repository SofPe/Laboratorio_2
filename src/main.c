#include <stdio.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/timer.h"      


#define F1_PIN 23
#define F2_PIN 22
#define F3_PIN 21
#define F4_PIN 19
#define F5_PIN 18
#define F6_PIN 5    // Problematico!!!
#define F7_PIN 17
#define F8_PIN 16

#define CR1_PIN 27
#define CR2_PIN 14  // Problematico!!!
#define CR3_PIN 12
#define CR4_PIN 13

#define CG5_PIN 32
#define CG6_PIN 33
#define CG7_PIN 25
#define CG8_PIN 26

#define BTN1_PIN 35     // IZQUIERDA
#define BTN2_PIN 34     // DERECHA
#define BTN3_PIN 39     // ABAJO
#define BTN4_PIN 36     // ARRIBA

void level_1 (){
    // Arriba, abajo, derecha, abajo
    uint64_t count = 0;
    timer_start(TIMER_GROUP_0,TIMER_0);
    while (count <= 8000000){
        timer_get_counter_value(TIMER_GROUP_0, TIMER_0, &count);
        if (count <= 2000000){ // Arriba
            gpio_set_level(F1_PIN, 1);
            gpio_set_level(F2_PIN, 1);
            gpio_set_level(F3_PIN, 1);
            gpio_set_level(F4_PIN, 1);
            gpio_set_level(CR2_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F1_PIN, 0);
            gpio_set_level(F3_PIN, 0);
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(CR1_PIN, 1);
            gpio_set_level(CR3_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F1_PIN, 0);
            gpio_set_level(F2_PIN, 0);
            gpio_set_level(F3_PIN, 0);
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR3_PIN, 0);
        }
        if (count > 2000000 && count <= 4000000){ // Abajo
            gpio_set_level(F5_PIN, 1);
            gpio_set_level(F6_PIN, 1);
            gpio_set_level(F7_PIN, 1);
            gpio_set_level(F8_PIN, 1);
            gpio_set_level(CR2_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(F6_PIN, 0);
            gpio_set_level(F8_PIN, 0);
            gpio_set_level(CR1_PIN, 1);
            gpio_set_level(CR3_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(F6_PIN, 0);
            gpio_set_level(F7_PIN, 0);
            gpio_set_level(F8_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR3_PIN, 0);
            vTaskDelay(pdMS_TO_TICKS(10));
        }
        if (count > 4000000 && count <= 6000000){ // Derecha
            gpio_set_level(F4_PIN, 1);
            gpio_set_level(CR1_PIN, 1);
            gpio_set_level(CR2_PIN, 1);
            gpio_set_level(CR3_PIN, 1);
            gpio_set_level(CR4_PIN, 1); 
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR4_PIN, 0);
            gpio_set_level(F5_PIN, 1);
            gpio_set_level(F3_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(F3_PIN, 0);
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR3_PIN, 0);
            gpio_set_level(CR4_PIN, 0);
            vTaskDelay(pdMS_TO_TICKS(10));
        }
        if (count > 6000000 && count <= 8000000){ // Abajo
            gpio_set_level(F5_PIN, 1);
            gpio_set_level(F6_PIN, 1);
            gpio_set_level(F7_PIN, 1);
            gpio_set_level(F8_PIN, 1);
            gpio_set_level(CR2_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(F6_PIN, 0);
            gpio_set_level(F8_PIN, 0);
            gpio_set_level(CR1_PIN, 1);
            gpio_set_level(CR3_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(F6_PIN, 0);
            gpio_set_level(F7_PIN, 0);
            gpio_set_level(F8_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR3_PIN, 0);
            vTaskDelay(pdMS_TO_TICKS(10));
        }
    }
    timer_pause(TIMER_GROUP_0,TIMER_0);
    timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
}

void level_2 (){
    // Izquierda, derecha, derecha, arriba
    uint64_t count = 0;
    timer_start(TIMER_GROUP_0,TIMER_0);
    
    while (count <= 8000000){
        timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
        if (count <= 2000000){ // Izquierda
            gpio_set_level(F4_PIN, 1);
            gpio_set_level(CR1_PIN, 1);
            gpio_set_level(CR2_PIN, 1);
            gpio_set_level(CR3_PIN, 1);
            gpio_set_level(CR4_PIN, 1); 
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR3_PIN, 0);
            gpio_set_level(CR4_PIN, 0);
            gpio_set_level(F5_PIN, 1);
            gpio_set_level(F3_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(F3_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            vTaskDelay(pdMS_TO_TICKS(10));
        }
        if (count > 2000000 && count <= 4000000){ // Derecha
            gpio_set_level(F5_PIN, 1);
            gpio_set_level(CR1_PIN, 1);
            gpio_set_level(CR2_PIN, 1);
            gpio_set_level(CR3_PIN, 1);
            gpio_set_level(CR4_PIN, 1); 
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR4_PIN, 0);
            gpio_set_level(F6_PIN, 1);
            gpio_set_level(F4_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(F3_PIN, 0);
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(F6_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR3_PIN, 0);
            gpio_set_level(CR4_PIN, 0);
            vTaskDelay(pdMS_TO_TICKS(10));
        }
        if (count > 4000000 && count <= 6000000){ // Derecha
            gpio_set_level(F4_PIN, 1);
            gpio_set_level(CR1_PIN, 1);
            gpio_set_level(CR2_PIN, 1);
            gpio_set_level(CR3_PIN, 1);
            gpio_set_level(CR4_PIN, 1); 
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR4_PIN, 0);
            gpio_set_level(F5_PIN, 1);
            gpio_set_level(F3_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(F3_PIN, 0);
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR3_PIN, 0);
            gpio_set_level(CR4_PIN, 0);
            vTaskDelay(pdMS_TO_TICKS(10));
        }
        if (count > 6000000 && count <= 8000000){
            gpio_set_level(F1_PIN, 1);
            gpio_set_level(F2_PIN, 1);
            gpio_set_level(F3_PIN, 1);
            gpio_set_level(F4_PIN, 1);
            gpio_set_level(CR2_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F1_PIN, 0);
            gpio_set_level(F3_PIN, 0);
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(CR1_PIN, 1);
            gpio_set_level(CR3_PIN, 1);
            vTaskDelay(pdMS_TO_TICKS(10));
            gpio_set_level(F1_PIN, 0);
            gpio_set_level(F2_PIN, 0);
            gpio_set_level(F3_PIN, 0);
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CR3_PIN, 0);
        }
    }
    timer_pause(TIMER_GROUP_0,TIMER_0);
    timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
}

void win_sequence (){
    uint64_t count = 0;
    timer_start(TIMER_GROUP_0,TIMER_0);
    while (count <= 4000000){
        timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
        if (count <= 500000 || (count > 2000000 && count <= 2500000)){
            gpio_set_level(F1_PIN, 0);
            gpio_set_level(F8_PIN, 0);
            gpio_set_level(F4_PIN, 0);
            gpio_set_level(F5_PIN, 0);
            gpio_set_level(F3_PIN, 0);
            gpio_set_level(F6_PIN, 0);
            gpio_set_level(F2_PIN, 0);
            gpio_set_level(F7_PIN, 0);
            gpio_set_level(CR1_PIN, 0);
            gpio_set_level(CG8_PIN, 0);
            gpio_set_level(F4_PIN, 1);
            gpio_set_level(F5_PIN, 1);
            gpio_set_level(CR4_PIN, 1);
            gpio_set_level(CG5_PIN, 1);
        }
        if ((count > 500000 && count <= 1000000) || (count > 2500000 && count <= 3000000)){
            gpio_set_level(CR4_PIN, 0);
            gpio_set_level(CG5_PIN, 0);
            gpio_set_level(F3_PIN, 1);
            gpio_set_level(F6_PIN, 1);
            gpio_set_level(CR3_PIN, 1);
            gpio_set_level(CG6_PIN, 1);
        }
        if ((count > 1000000 && count <= 1500000) || (count > 3000000 && count <= 3500000)){
            gpio_set_level(CR3_PIN, 0);
            gpio_set_level(CG6_PIN, 0);
            gpio_set_level(F2_PIN, 1);
            gpio_set_level(F7_PIN, 1);
            gpio_set_level(CR2_PIN, 1);
            gpio_set_level(CG7_PIN, 1);
        }
        if ((count > 1500000 && count <= 2000000) || (count > 3500000 && count <= 4000000)){
            gpio_set_level(CR2_PIN, 0);
            gpio_set_level(CG7_PIN, 0);
            gpio_set_level(F1_PIN, 1);
            gpio_set_level(F8_PIN, 1);
            gpio_set_level(CR1_PIN, 1);
            gpio_set_level(CG8_PIN, 1);
        }
    }
    timer_pause(TIMER_GROUP_0,TIMER_0);
    timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
    gpio_set_level(F1_PIN, 0);
    gpio_set_level(F8_PIN, 0);
    gpio_set_level(CR1_PIN, 0);
    gpio_set_level(CG8_PIN, 0);
}

void lose_sequence (){
    uint64_t count = 0;
    timer_start(TIMER_GROUP_0,TIMER_0);
    while (count <= 4000000){
        timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
        gpio_set_level(F6_PIN, 0);
        gpio_set_level(CR3_PIN, 0);
        gpio_set_level(CR4_PIN, 0);
        gpio_set_level(CG5_PIN, 0);
        gpio_set_level(F2_PIN, 1);
        gpio_set_level(F3_PIN, 1);
        gpio_set_level(CR2_PIN, 1);
        gpio_set_level(CR3_PIN, 1);
        gpio_set_level(CG6_PIN, 1);
        gpio_set_level(CG7_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(F2_PIN, 0);
        gpio_set_level(F3_PIN, 0);
        gpio_set_level(CR2_PIN, 0);
        gpio_set_level(CR3_PIN, 0);
        gpio_set_level(CG6_PIN, 0);
        gpio_set_level(CG7_PIN, 0);
        gpio_set_level(F7_PIN, 1);
        gpio_set_level(CR2_PIN, 1);
        gpio_set_level(CG7_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(F7_PIN, 0);
        gpio_set_level(CR2_PIN, 0);
        gpio_set_level(CG7_PIN, 0);
        gpio_set_level(F6_PIN, 1);
        gpio_set_level(CR3_PIN, 1);
        gpio_set_level(CR4_PIN, 1);
        gpio_set_level(CG5_PIN, 1);
        gpio_set_level(CG6_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    timer_pause(TIMER_GROUP_0,TIMER_0);
    timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
}

// Esta función espera infinitamente hasta que se presiona un botón y retorna su número
int wait_for_button_press() {
    while (1) {
        if (gpio_get_level(BTN1_PIN) == 0) {
            vTaskDelay(pdMS_TO_TICKS(50)); // Antirrebote
            while(gpio_get_level(BTN1_PIN) == 0) vTaskDelay(pdMS_TO_TICKS(10)); // Espera a que se suelte el botón
            return 1; // Izquierda
        }
        if (gpio_get_level(BTN2_PIN) == 0) {
            vTaskDelay(pdMS_TO_TICKS(50));
            while(gpio_get_level(BTN2_PIN) == 0) vTaskDelay(pdMS_TO_TICKS(10));
            return 2; // Derecha
        }
        if (gpio_get_level(BTN3_PIN) == 0) {
            vTaskDelay(pdMS_TO_TICKS(50));
            while(gpio_get_level(BTN3_PIN) == 0) vTaskDelay(pdMS_TO_TICKS(10));
            return 3; // Abajo
        }
        if (gpio_get_level(BTN4_PIN) == 0) {
            vTaskDelay(pdMS_TO_TICKS(50));
            while(gpio_get_level(BTN4_PIN) == 0) vTaskDelay(pdMS_TO_TICKS(10));
            return 4; // Arriba
        }
        
        // Es vital incluir este delay en ciclos infinitos para no asfixiar 
        // al Watchdog Timer de FreeRTOS (Task Watchdog)
        vTaskDelay(pdMS_TO_TICKS(10)); 
    }
}

void reset_game (){
    gpio_set_level(F1_PIN, 0);
    gpio_set_level(F2_PIN, 0);
    gpio_set_level(F3_PIN, 0);
    gpio_set_level(F4_PIN, 0);
    gpio_set_level(F5_PIN, 0);
    gpio_set_level(F6_PIN, 0);
    gpio_set_level(F7_PIN, 0);
    gpio_set_level(F8_PIN, 0);
    gpio_set_level(CR1_PIN, 0);
    gpio_set_level(CR2_PIN, 0);
    gpio_set_level(CR3_PIN, 0);
    gpio_set_level(CR4_PIN, 0);
    gpio_set_level(CG5_PIN, 0);
    gpio_set_level(CG6_PIN, 0);
    gpio_set_level(CG7_PIN, 0);
    gpio_set_level(CG8_PIN, 0);

}

void app_main() {
    gpio_config_t out_conf = {
        .pin_bit_mask = (1ULL << F1_PIN | 1ULL << F2_PIN | 1ULL << F3_PIN | 1ULL << F4_PIN | 1ULL << F5_PIN | 1ULL << F6_PIN | 
                        1ULL << F7_PIN | 1ULL << F8_PIN | 1ULL << CR1_PIN | 1ULL << CR2_PIN | 1ULL << CR3_PIN | 1ULL << CR4_PIN | 
                        1ULL << CG5_PIN | 1ULL << CG6_PIN | 1ULL << CG7_PIN | 1ULL << CG8_PIN),    
        .mode = GPIO_MODE_OUTPUT,   /*Defino el modo del pin, en este caso salida*/
        .pull_up_en = GPIO_PULLUP_DISABLE,  /*Defino si necesito resistencia pull up, en este caso no*/
        .pull_down_en = GPIO_PULLDOWN_DISABLE,  /*Defino si necesito resistencia pull down, en este caso no*/
        .intr_type = GPIO_INTR_DISABLE  /*Defino si necesito interrupciones, en este caso no*/
    };
    gpio_config(&out_conf);   /*Le mando la configuración del pin*/

    gpio_config_t in_conf = {
        .pin_bit_mask = (1ULL << BTN1_PIN | 1ULL << BTN2_PIN | 1ULL << BTN3_PIN | 1ULL << BTN4_PIN),    
        .mode = GPIO_MODE_INPUT,   /*Defino el modo del pin, en este caso entrada*/
        .pull_up_en = GPIO_PULLUP_ENABLE,  /*Defino si necesito resistencia pull up, en este caso sí*/
        .pull_down_en = GPIO_PULLDOWN_DISABLE,  /*Defino si necesito resistencia pull down, en este caso no*/
        .intr_type = GPIO_INTR_DISABLE  /*Defino si necesito interrupciones, en este caso no*/
    };
    gpio_config(&in_conf);   /*Le mando la configuración del pin*/

    timer_config_t timer_conf={
        .divider = 80, // 1 tick cada 1 us
        .counter_dir = TIMER_COUNT_UP, // Contador ascendente
        .counter_en = TIMER_PAUSE,
        .alarm_en = TIMER_ALARM_DIS,
        .auto_reload = false
    };
    timer_init(TIMER_GROUP_0,TIMER_0, &timer_conf);
    timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);

    gpio_set_level(CR2_PIN, 0);
    gpio_set_level(F6_PIN, 0);

    bool btn1_state = 0;
    bool btn2_state = 0;
    bool end = false;
    bool in_cicle = false;

    while (1) {
        btn1_state = gpio_get_level(BTN1_PIN);  /*Leo el estado del botón izquierdo*/
        btn2_state = gpio_get_level(BTN2_PIN);  /*Leo el estado del botón derecho*/

        if (btn1_state == 0 && end == false && in_cicle == false){ // Botón 1 presionado - Nivel 1
            level_1();
            in_cicle = true;
            if (wait_for_button_press()== 4){ 
                uint64_t count = 0;
                timer_start(TIMER_GROUP_0,TIMER_0);
                while (count<= 1000000){    // Arriba
                    timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
                    gpio_set_level(F1_PIN, 1);
                    gpio_set_level(F2_PIN, 1);
                    gpio_set_level(F3_PIN, 1);
                    gpio_set_level(F4_PIN, 1);
                    gpio_set_level(CG6_PIN, 1);
                    vTaskDelay(pdMS_TO_TICKS(10));
                    gpio_set_level(F1_PIN, 0);
                    gpio_set_level(F3_PIN, 0);
                    gpio_set_level(F4_PIN, 0);
                    gpio_set_level(CG5_PIN, 1);
                    gpio_set_level(CG7_PIN, 1);
                    vTaskDelay(pdMS_TO_TICKS(10));
                    gpio_set_level(F1_PIN, 0);
                    gpio_set_level(F2_PIN, 0);
                    gpio_set_level(F3_PIN, 0);
                    gpio_set_level(F4_PIN, 0);
                    gpio_set_level(CG5_PIN, 0);
                    gpio_set_level(CG6_PIN, 0);
                    gpio_set_level(CG7_PIN, 0);
                }
                timer_pause(TIMER_GROUP_0,TIMER_0);
                timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
                if (wait_for_button_press()== 3){
                    uint64_t count = 0;
                    timer_start(TIMER_GROUP_0,TIMER_0);
                    while (count<= 1000000){   // Abajo
                        timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
                        gpio_set_level(F5_PIN, 1);
                        gpio_set_level(F6_PIN, 1);
                        gpio_set_level(F7_PIN, 1);
                        gpio_set_level(F8_PIN, 1);
                        gpio_set_level(CG6_PIN, 1);
                        vTaskDelay(pdMS_TO_TICKS(10));
                        gpio_set_level(F5_PIN, 0);
                        gpio_set_level(F6_PIN, 0);
                        gpio_set_level(F8_PIN, 0);
                        gpio_set_level(CG5_PIN, 1);
                        gpio_set_level(CG7_PIN, 1);
                        vTaskDelay(pdMS_TO_TICKS(10));
                        gpio_set_level(F5_PIN, 0);
                        gpio_set_level(F6_PIN, 0);
                        gpio_set_level(F7_PIN, 0);
                        gpio_set_level(F8_PIN, 0);
                        gpio_set_level(CG5_PIN, 0);
                        gpio_set_level(CG6_PIN, 0);
                        gpio_set_level(CG7_PIN, 0);
                        vTaskDelay(pdMS_TO_TICKS(10));
                    }
                    timer_pause(TIMER_GROUP_0,TIMER_0);
                    timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
                    if (wait_for_button_press()== 2){
                        uint64_t count = 0;
                        timer_start(TIMER_GROUP_0,TIMER_0);
                        while (count<= 1000000){   // Derecha
                            timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
                            gpio_set_level(F4_PIN, 1);
                            gpio_set_level(CG5_PIN, 1);
                            gpio_set_level(CG6_PIN, 1);
                            gpio_set_level(CG7_PIN, 1);
                            gpio_set_level(CG8_PIN, 1); 
                            vTaskDelay(pdMS_TO_TICKS(10));
                            gpio_set_level(F4_PIN, 0);
                            gpio_set_level(CG5_PIN, 0);
                            gpio_set_level(CG6_PIN, 0);
                            gpio_set_level(CG8_PIN, 0);
                            gpio_set_level(F5_PIN, 1);
                            gpio_set_level(F3_PIN, 1);
                            vTaskDelay(pdMS_TO_TICKS(10));
                            gpio_set_level(F5_PIN, 0);
                            gpio_set_level(F3_PIN, 0);
                            gpio_set_level(F4_PIN, 0);
                            gpio_set_level(CG5_PIN, 0);
                            gpio_set_level(CG6_PIN, 0);
                            gpio_set_level(CG7_PIN, 0);
                            gpio_set_level(CG8_PIN, 0);
                            vTaskDelay(pdMS_TO_TICKS(10));
                        }
                        timer_pause(TIMER_GROUP_0,TIMER_0);
                        timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
                        if (wait_for_button_press()== 3){
                            uint64_t count = 0;
                            timer_start(TIMER_GROUP_0,TIMER_0);
                            while (count<= 1000000){   // Abajo
                                timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
                                gpio_set_level(F5_PIN, 1);
                                gpio_set_level(F6_PIN, 1);
                                gpio_set_level(F7_PIN, 1);
                                gpio_set_level(F8_PIN, 1);
                                gpio_set_level(CG6_PIN, 1);
                                vTaskDelay(pdMS_TO_TICKS(10));
                                gpio_set_level(F5_PIN, 0);
                                gpio_set_level(F6_PIN, 0);
                                gpio_set_level(F8_PIN, 0);
                                gpio_set_level(CG5_PIN, 1);
                                gpio_set_level(CG7_PIN, 1);
                                vTaskDelay(pdMS_TO_TICKS(10));
                                gpio_set_level(F5_PIN, 0);
                                gpio_set_level(F6_PIN, 0);
                                gpio_set_level(F7_PIN, 0);
                                gpio_set_level(F8_PIN, 0);
                                gpio_set_level(CG5_PIN, 0);
                                gpio_set_level(CG6_PIN, 0);
                                gpio_set_level(CG7_PIN, 0);
                                vTaskDelay(pdMS_TO_TICKS(10));
                            }
                            timer_pause(TIMER_GROUP_0,TIMER_0);
                            timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
                            win_sequence();
                            end = true;
                            in_cicle = false;
                        }
                        else {
                            lose_sequence();
                            reset_game();
                            end = true;
                            in_cicle = false;
                        }
                    }
                    else {
                        lose_sequence();
                        reset_game();
                        end = true;
                        in_cicle = false;
                    }
                }
                else {
                    lose_sequence();
                    reset_game();
                    end = true;
                    in_cicle = false;
                }
            }
            else {
                lose_sequence();
                reset_game();
                end = true;
                in_cicle = false;
            }
        in_cicle = false;
        }
        
        if (btn2_state == 0 && end == false && in_cicle == false){ // Botón 1 presionado - Nivel 1
            level_2();
            in_cicle = true;
            if (wait_for_button_press() == 1){
                uint64_t count = 0;
                timer_start(TIMER_GROUP_0,TIMER_0);
                while (count<= 1000000){    // Izquierda
                    timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
                    gpio_set_level(F4_PIN, 1);
                    gpio_set_level(CG5_PIN, 1);
                    gpio_set_level(CG6_PIN, 1);
                    gpio_set_level(CG7_PIN, 1);
                    gpio_set_level(CG8_PIN, 1); 
                    vTaskDelay(pdMS_TO_TICKS(10));
                    gpio_set_level(F4_PIN, 0);
                    gpio_set_level(CG5_PIN, 0);
                    gpio_set_level(CG7_PIN, 0);
                    gpio_set_level(CG8_PIN, 0);
                    gpio_set_level(F5_PIN, 1);
                    gpio_set_level(F3_PIN, 1);
                    vTaskDelay(pdMS_TO_TICKS(10));
                    gpio_set_level(F5_PIN, 0);
                    gpio_set_level(F3_PIN, 0);
                    gpio_set_level(F4_PIN, 0);
                    gpio_set_level(CG5_PIN, 0);
                    gpio_set_level(CG6_PIN, 0);
                    gpio_set_level(CG7_PIN, 0);
                    gpio_set_level(CG8_PIN, 0);
                    vTaskDelay(pdMS_TO_TICKS(10));
                }
                timer_pause(TIMER_GROUP_0,TIMER_0);
                timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
                if (wait_for_button_press() == 2){
                    uint64_t count = 0;
                    timer_start(TIMER_GROUP_0,TIMER_0);
                    while (count<= 1000000){   // Derecha
                        timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
                        gpio_set_level(F4_PIN, 1);
                        gpio_set_level(CG5_PIN, 1);
                        gpio_set_level(CG6_PIN, 1);
                        gpio_set_level(CG7_PIN, 1);
                        gpio_set_level(CG8_PIN, 1); 
                        vTaskDelay(pdMS_TO_TICKS(10));
                        gpio_set_level(F4_PIN, 0);
                        gpio_set_level(CG5_PIN, 0);
                        gpio_set_level(CG6_PIN, 0);
                        gpio_set_level(CG8_PIN, 0);
                        gpio_set_level(F5_PIN, 1);
                        gpio_set_level(F3_PIN, 1);
                        vTaskDelay(pdMS_TO_TICKS(10));
                        gpio_set_level(F5_PIN, 0);
                        gpio_set_level(F3_PIN, 0);
                        gpio_set_level(F4_PIN, 0);
                        gpio_set_level(CG5_PIN, 0);
                        gpio_set_level(CG6_PIN, 0);
                        gpio_set_level(CG7_PIN, 0);
                        gpio_set_level(CG8_PIN, 0);
                        vTaskDelay(pdMS_TO_TICKS(10));
                    }
                    timer_pause(TIMER_GROUP_0,TIMER_0);
                    timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
                    if (wait_for_button_press() == 2){
                        uint64_t count = 0;
                        timer_start(TIMER_GROUP_0,TIMER_0);
                        while (count<= 1000000){   // Derecha
                            timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
                            gpio_set_level(F4_PIN, 1);
                            gpio_set_level(CG5_PIN, 1);
                            gpio_set_level(CG6_PIN, 1);
                            gpio_set_level(CG7_PIN, 1);
                            gpio_set_level(CG8_PIN, 1); 
                            vTaskDelay(pdMS_TO_TICKS(10));
                            gpio_set_level(F4_PIN, 0);
                            gpio_set_level(CG5_PIN, 0);
                            gpio_set_level(CG6_PIN, 0);
                            gpio_set_level(CG8_PIN, 0);
                            gpio_set_level(F5_PIN, 1);
                            gpio_set_level(F3_PIN, 1);
                            vTaskDelay(pdMS_TO_TICKS(10));
                            gpio_set_level(F5_PIN, 0);
                            gpio_set_level(F3_PIN, 0);
                            gpio_set_level(F4_PIN, 0);
                            gpio_set_level(CG5_PIN, 0);
                            gpio_set_level(CG6_PIN, 0);
                            gpio_set_level(CG7_PIN, 0);
                            gpio_set_level(CG8_PIN, 0);
                            vTaskDelay(pdMS_TO_TICKS(10));
                        }
                        timer_pause(TIMER_GROUP_0,TIMER_0);
                        timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
                        if (wait_for_button_press() == 4){
                            uint64_t count = 0;
                            timer_start(TIMER_GROUP_0,TIMER_0);
                            while (count<= 1000000){   // Arriba
                                timer_get_counter_value(TIMER_GROUP_0,TIMER_0, &count);
                                gpio_set_level(F1_PIN, 1);
                                gpio_set_level(F2_PIN, 1);
                                gpio_set_level(F3_PIN, 1);
                                gpio_set_level(F4_PIN, 1);
                                gpio_set_level(CG6_PIN, 1);
                                vTaskDelay(pdMS_TO_TICKS(10));
                                gpio_set_level(F1_PIN, 0);
                                gpio_set_level(F3_PIN, 0);
                                gpio_set_level(F4_PIN, 0);
                                gpio_set_level(CG5_PIN, 1);
                                gpio_set_level(CG7_PIN, 1);
                                vTaskDelay(pdMS_TO_TICKS(10));
                                gpio_set_level(F1_PIN, 0);
                                gpio_set_level(F2_PIN, 0);
                                gpio_set_level(F3_PIN, 0);
                                gpio_set_level(F4_PIN, 0);
                                gpio_set_level(CG5_PIN, 0);
                                gpio_set_level(CG6_PIN, 0);
                                gpio_set_level(CG7_PIN, 0);
                            }
                            timer_pause(TIMER_GROUP_0,TIMER_0);
                            timer_set_counter_value(TIMER_GROUP_0,TIMER_0,0);
                            win_sequence();
                            end = true;
                            in_cicle = false;
                        }
                        else {
                            lose_sequence();
                            reset_game();
                            end = true;
                            in_cicle = false;
                        }
                    }
                    else {
                        lose_sequence();
                        reset_game();
                        end = true;
                        in_cicle = false;
                    }
                }
                else {
                    lose_sequence();
                    reset_game();
                    end = true;
                    in_cicle = false;
                }
            }
            else {
                lose_sequence();
                reset_game();
                end = true;
                in_cicle = false;
            }
        }
        end = false;
        in_cicle = false;
        btn1_state = 0;
        btn2_state = 0;
    }
}