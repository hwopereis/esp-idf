// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _DRIVER_GPIO_H_
#define _DRIVER_GPIO_H_

#include <esp_types.h>
#include "soc/gpio_reg.h"
#include "soc/gpio_struct.h"
#include "soc/rtc_io_reg.h"
#include "soc/io_mux_reg.h"
#include "rom/gpio.h"
#include "esp_attr.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_SEL_0              (BIT(0))                         /* Pin 0 selected */
#define GPIO_SEL_1              (BIT(1))                         /* Pin 1 selected */
#define GPIO_SEL_2              (BIT(2))                         /* Pin 2 selected */
#define GPIO_SEL_3              (BIT(3))                         /* Pin 3 selected */
#define GPIO_SEL_4              (BIT(4))                         /* Pin 4 selected */
#define GPIO_SEL_5              (BIT(5))                         /* Pin 5 selected */
#define GPIO_SEL_6              (BIT(6))                         /* Pin 6 selected */
#define GPIO_SEL_7              (BIT(7))                         /* Pin 7 selected */
#define GPIO_SEL_8              (BIT(8))                         /* Pin 8 selected */
#define GPIO_SEL_9              (BIT(9))                         /* Pin 9 selected */
#define GPIO_SEL_10             (BIT(10))                        /* Pin 10 selected */
#define GPIO_SEL_11             (BIT(11))                        /* Pin 11 selected */
#define GPIO_SEL_12             (BIT(12))                        /* Pin 12 selected */
#define GPIO_SEL_13             (BIT(13))                        /* Pin 13 selected */
#define GPIO_SEL_14             (BIT(14))                        /* Pin 14 selected */
#define GPIO_SEL_15             (BIT(15))                        /* Pin 15 selected */
#define GPIO_SEL_16             (BIT(16))                        /* Pin 16 selected */
#define GPIO_SEL_17             (BIT(17))                        /* Pin 17 selected */
#define GPIO_SEL_18             (BIT(18))                        /* Pin 18 selected */
#define GPIO_SEL_19             (BIT(19))                        /* Pin 19 selected */

#define GPIO_SEL_21             (BIT(21))                        /* Pin 21 selected */
#define GPIO_SEL_22             (BIT(22))                        /* Pin 22 selected */
#define GPIO_SEL_23             (BIT(23))                        /* Pin 23 selected */

#define GPIO_SEL_25             (BIT(25))                        /* Pin 25 selected */
#define GPIO_SEL_26             (BIT(26))                        /* Pin 26 selected */
#define GPIO_SEL_27             (BIT(27))                        /* Pin 27 selected */

#define GPIO_SEL_32             ((uint64_t)(((uint64_t)1)<<32))  /* Pin 32 selected */
#define GPIO_SEL_33             ((uint64_t)(((uint64_t)1)<<33))  /* Pin 33 selected */
#define GPIO_SEL_34             ((uint64_t)(((uint64_t)1)<<34))  /* Pin 34 selected */
#define GPIO_SEL_35             ((uint64_t)(((uint64_t)1)<<35))  /* Pin 35 selected */
#define GPIO_SEL_36             ((uint64_t)(((uint64_t)1)<<36))  /* Pin 36 selected */
#define GPIO_SEL_37             ((uint64_t)(((uint64_t)1)<<37))  /* Pin 37 selected */
#define GPIO_SEL_38             ((uint64_t)(((uint64_t)1)<<38))  /* Pin 38 selected */
#define GPIO_SEL_39             ((uint64_t)(((uint64_t)1)<<39))  /* Pin 39 selected */

#define GPIO_PIN_REG_0          PERIPHS_IO_MUX_GPIO0_U
#define GPIO_PIN_REG_1          PERIPHS_IO_MUX_U0TXD_U
#define GPIO_PIN_REG_2          PERIPHS_IO_MUX_GPIO2_U
#define GPIO_PIN_REG_3          PERIPHS_IO_MUX_U0RXD_U
#define GPIO_PIN_REG_4          PERIPHS_IO_MUX_GPIO4_U
#define GPIO_PIN_REG_5          PERIPHS_IO_MUX_GPIO5_U
#define GPIO_PIN_REG_6          PERIPHS_IO_MUX_SD_CLK_U
#define GPIO_PIN_REG_7          PERIPHS_IO_MUX_SD_DATA0_U
#define GPIO_PIN_REG_8          PERIPHS_IO_MUX_SD_DATA1_U
#define GPIO_PIN_REG_9          PERIPHS_IO_MUX_SD_DATA2_U
#define GPIO_PIN_REG_10         PERIPHS_IO_MUX_SD_DATA3_U
#define GPIO_PIN_REG_11         PERIPHS_IO_MUX_SD_CMD_U
#define GPIO_PIN_REG_12         PERIPHS_IO_MUX_MTDI_U
#define GPIO_PIN_REG_13         PERIPHS_IO_MUX_MTCK_U
#define GPIO_PIN_REG_14         PERIPHS_IO_MUX_MTMS_U
#define GPIO_PIN_REG_15         PERIPHS_IO_MUX_MTDO_U
#define GPIO_PIN_REG_16         PERIPHS_IO_MUX_GPIO16_U
#define GPIO_PIN_REG_17         PERIPHS_IO_MUX_GPIO17_U
#define GPIO_PIN_REG_18         PERIPHS_IO_MUX_GPIO18_U
#define GPIO_PIN_REG_19         PERIPHS_IO_MUX_GPIO19_U
#define GPIO_PIN_REG_20         PERIPHS_IO_MUX_GPIO20_U
#define GPIO_PIN_REG_21         PERIPHS_IO_MUX_GPIO21_U
#define GPIO_PIN_REG_22         PERIPHS_IO_MUX_GPIO22_U
#define GPIO_PIN_REG_23         PERIPHS_IO_MUX_GPIO23_U
#define GPIO_PIN_REG_25         PERIPHS_IO_MUX_GPIO25_U
#define GPIO_PIN_REG_26         PERIPHS_IO_MUX_GPIO26_U
#define GPIO_PIN_REG_27         PERIPHS_IO_MUX_GPIO27_U
#define GPIO_PIN_REG_32         PERIPHS_IO_MUX_GPIO32_U
#define GPIO_PIN_REG_33         PERIPHS_IO_MUX_GPIO33_U
#define GPIO_PIN_REG_34         PERIPHS_IO_MUX_GPIO34_U
#define GPIO_PIN_REG_35         PERIPHS_IO_MUX_GPIO35_U
#define GPIO_PIN_REG_36         PERIPHS_IO_MUX_GPIO36_U
#define GPIO_PIN_REG_37         PERIPHS_IO_MUX_GPIO37_U
#define GPIO_PIN_REG_38         PERIPHS_IO_MUX_GPIO38_U
#define GPIO_PIN_REG_39         PERIPHS_IO_MUX_GPIO39_U

#define GPIO_APP_CPU_INTR_ENA      (BIT(0))
#define GPIO_APP_CPU_NMI_INTR_ENA  (BIT(1))
#define GPIO_PRO_CPU_INTR_ENA      (BIT(2))
#define GPIO_PRO_CPU_NMI_INTR_ENA  (BIT(3))
#define GPIO_SDIO_EXT_INTR_ENA     (BIT(4))

#define GPIO_MODE_DEF_INPUT           (BIT0)
#define GPIO_MODE_DEF_OUTPUT          (BIT1)
#define GPIO_MODE_DEF_OD              (BIT2)

#define GPIO_PIN_COUNT              40
extern const uint32_t GPIO_PIN_MUX_REG[GPIO_PIN_COUNT];
#define GPIO_IS_VALID_GPIO(gpio_num)      ((gpio_num < GPIO_PIN_COUNT && GPIO_PIN_MUX_REG[gpio_num] != 0))   //to decide whether it is a valid GPIO number
#define GPIO_IS_VALID_OUTPUT_GPIO(gpio_num)      ((GPIO_IS_VALID_GPIO(gpio_num)) && (gpio_num < 34))         //to decide whether it can be a valid GPIO number of output mode

typedef enum {
    GPIO_NUM_0 = 0,
    GPIO_NUM_1 = 1,
    GPIO_NUM_2 = 2,
    GPIO_NUM_3 = 3,
    GPIO_NUM_4 = 4,
    GPIO_NUM_5 = 5,
    GPIO_NUM_6 = 6,
    GPIO_NUM_7 = 7,
    GPIO_NUM_8 = 8,
    GPIO_NUM_9 = 9,
    GPIO_NUM_10 = 10,
    GPIO_NUM_11 = 11,
    GPIO_NUM_12 = 12,
    GPIO_NUM_13 = 13,
    GPIO_NUM_14 = 14,
    GPIO_NUM_15 = 15,
    GPIO_NUM_16 = 16,
    GPIO_NUM_17 = 17,
    GPIO_NUM_18 = 18,
    GPIO_NUM_19 = 19,

    GPIO_NUM_21 = 21,
    GPIO_NUM_22 = 22,
    GPIO_NUM_23 = 23,

    GPIO_NUM_25 = 25,
    GPIO_NUM_26 = 26,
    GPIO_NUM_27 = 27,

    GPIO_NUM_32 = 32,
    GPIO_NUM_33 = 33,
    GPIO_NUM_34 = 34, /*input mode only */
    GPIO_NUM_35 = 35, /*input mode only */
    GPIO_NUM_36 = 36, /*input mode only */
    GPIO_NUM_37 = 37, /*input mode only */
    GPIO_NUM_38 = 38, /*input mode only */
    GPIO_NUM_39 = 39, /*input mode only */
} gpio_num_t;

typedef enum {
    GPIO_INTR_DISABLE = 0,     /* disable GPIO interrupt                             */
    GPIO_INTR_POSEDGE = 1,     /* GPIO interrupt type : rising edge                  */
    GPIO_INTR_NEGEDGE = 2,     /* GPIO interrupt type : falling edge                 */
    GPIO_INTR_ANYEDGE = 3,     /* GPIO interrupt type : both rising and falling edge */
    GPIO_INTR_LOW_LEVEL = 4,   /* GPIO interrupt type : input low level trigger      */
    GPIO_INTR_HIGH_LEVEL = 5,  /* GPIO interrupt type : input high level trigger     */
    GPIO_INTR_MAX,
} gpio_int_type_t;

typedef enum {
    GPIO_MODE_INPUT = GPIO_MODE_DEF_INPUT,                                                         /* GPIO mode : input only                           */
    GPIO_MODE_OUTPUT = GPIO_MODE_DEF_OUTPUT,                                                       /* GPIO mode : output only mode                     */
    GPIO_MODE_OUTPUT_OD = ((GPIO_MODE_DEF_OUTPUT)|(GPIO_MODE_DEF_OD)),                             /* GPIO mode : output only with open-drain mode     */
    GPIO_MODE_INPUT_OUTPUT_OD = ((GPIO_MODE_DEF_INPUT)|(GPIO_MODE_DEF_OUTPUT)|(GPIO_MODE_DEF_OD)), /* GPIO mode : output and input with open-drain mode*/
    GPIO_MODE_INPUT_OUTPUT = ((GPIO_MODE_DEF_INPUT)|(GPIO_MODE_DEF_OUTPUT)),                       /* GPIO mode : output and input mode                */
} gpio_mode_t;

typedef enum {
    GPIO_PULLUP_DISABLE = 0x0,     /* disable GPIO pull-up resistor */
    GPIO_PULLUP_ENABLE = 0x1,      /*  enable GPIO pull-up resistor */
} gpio_pullup_t;

typedef enum {
    GPIO_PULLDOWN_DISABLE = 0x0,   /* disable GPIO pull-down resistor */
    GPIO_PULLDOWN_ENABLE = 0x1,    /* enable GPIO pull-down resistor  */
} gpio_pulldown_t;

typedef struct {
    uint64_t pin_bit_mask;          /* GPIO pin: set with bit mask, each bit maps to a GPIO */
    gpio_mode_t mode;               /* GPIO mode: set input/output mode                     */
    gpio_pullup_t pull_up_en;       /* GPIO pull-up                                         */
    gpio_pulldown_t pull_down_en;   /* GPIO pull-down                                       */
    gpio_int_type_t intr_type;      /* GPIO interrupt type                                  */
} gpio_config_t;

typedef enum {
    GPIO_LOW_LEVEL = 0,
    GPIO_HIGH_LEVEL = 1,
    GPIO_LEVEL_ERR,
} gpio_level_t;

typedef enum {
    GPIO_PULLUP_ONLY,               /* Pad pull up            */
    GPIO_PULLDOWN_ONLY,             /* Pad pull down          */
    GPIO_PULLUP_PULLDOWN,           /* Pad pull up + pull down*/
    GPIO_FLOATING,                  /* Pad floating           */
} gpio_pull_mode_t;

typedef void (*gpio_event_callback)(gpio_num_t gpio_intr_num);

/** \defgroup Driver_APIs Driver APIs
 * @brief Driver APIs
 */

/** @addtogroup Driver_APIs
 * @{
 */

/** \defgroup GPIO_Driver_APIs GPIO Driver APIs
 * @brief GPIO APIs
 */

/** @addtogroup GPIO_Driver_APIs
 * @{
 */

/**
 * @brief	   GPIO common configuration
 *
 * Use this Function ,Configure GPIO's Mode,pull-up,PullDown,IntrType
 *
 * @parameter[in]  pGPIOConfig
 *                 pGPIOConfig.pin_bit_mask   : Configure GPIO pins bits,set this parameter with bit mask.
 *                                              If you want to configure GPIO34 and GPIO16, pin_bit_mask=GPIO_Pin_16|GPIO_Pin_34;
 *                 pGPIOConfig.mode           : Configure GPIO mode,such as output ,input...
 *                 pGPIOConfig.pull_up_en     : Enable or Disable pull-up
 *                 pGPIOConfig.pull_down_en   : Enable or Disable pull-down
 *                 pGPIOConfig.intr_type : Configure GPIO interrupt trigger type
 * @return	       ESP_OK: success ;
 *                 ESP_ERR_INVALID_ARG: parameter error
 *                 ESP_FAIL : GPIO error
 *
 */
esp_err_t gpio_config(gpio_config_t *pGPIOConfig);


/**
 * @brief      GPIO set interrupt trigger type
 *
 * @parameter[in]  gpio_num : GPIO number.
 *                            If you want to set output level of GPIO16, gpio_num should be GPIO_NUM_16 (16);
 * @parameter[in]  intr_type: interrupt type, select from gpio_int_type_t
 *
 * @return         ESP_OK   : success
 *                 ESP_ERR_INVALID_ARG: parameter error
 *
 */
esp_err_t gpio_set_intr_type(gpio_num_t gpio_num, gpio_int_type_t intr_type);

/**
 * @brief      enable GPIO module interrupt signal
 *
 * @parameter[in]  gpio_num : GPIO number.
 *                            If you want to set output level of GPIO16, gpio_num should be GPIO_NUM_16 (16);
 *
 * @return         ESP_OK   : success
 *                 ESP_ERR_INVALID_ARG: parameter error
 *
 */
esp_err_t gpio_intr_enable(gpio_num_t gpio_num);

/**
 * @brief      disable GPIO module interrupt signal
 *
 * @parameter[in]  gpio_num : GPIO number.
 *                            If you want to set output level of GPIO16, gpio_num should be GPIO_NUM_16 (16);
 *
 * @return         ESP_OK   : success
 *                 ESP_ERR_INVALID_ARG: parameter error
 *
 */
esp_err_t gpio_intr_disable(gpio_num_t gpio_num);

/**
 * @brief	   GPIO set output level
 *
 * @parameter[in]  gpio_num : GPIO number.
 *                            If you want to set output level of GPIO16, gpio_num should be GPIO_NUM_16 (16);
 * @parameter[in]  level    : Output level. 0: low ; 1: high
 *
 * @return	       ESP_OK   : success
 *                 ESP_FAIL : GPIO error
 *
 */
esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level);

/**
 * @brief	   GPIO get input level
 *
 * @parameter[in]  gpio_num : GPIO number.
 *                            If you want to get level of pin GPIO16, gpio_num should be GPIO_NUM_16 (16);
 *
 * @return	    0  : the GPIO input level is 0
 *              1  : the GPIO input level is 1
 *
 */
int gpio_get_level(gpio_num_t gpio_num);

/**
 * @brief	   GPIO set direction
 *
 * Configure GPIO direction,such as output_only,input_only,output_and_input
 *
 * @parameter[in]  gpio_num : Configure GPIO pins number,it should be GPIO number.
 *                            If you want to set direction of GPIO16, gpio_num should be GPIO_NUM_16 (16);
 * @parameter[in]  mode     : Configure GPIO direction,such as output_only,input_only,...
 *
 * @return	       ESP_OK   : success
 *                 ESP_ERR_INVALID_ARG : fail
 *                 ESP_FAIL : GPIO error
 *
 */
esp_err_t gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode);

/**
 * @brief	   GPIO set pull
 *
 * User this Function,configure GPIO pull mode,such as pull-up,pull-down
 *
 * @parameter[in]  gpio_num : Configure GPIO pins number,it should be GPIO number.
 *                            If you want to set pull up or down mode for GPIO16,gpio_num should be GPIO_NUM_16 (16);
 * @parameter[in]  pull     : Configure GPIO pull up/down mode,such as pullup_only,pulldown_only,pullup_and_pulldown,...
 *
 * @return	       ESP_OK   : success
 *                 ESP_ERR_INVALID_ARG : fail
 *                 ESP_FAIL : GPIO error
 *
 */
esp_err_t gpio_set_pull_mode(gpio_num_t gpio_num, gpio_pull_mode_t pull);

/**
  * @brief enable GPIO wake-up function.
  *
  * @param gpio_num_t gpio_num : GPIO number.
  *
  * @param gpio_int_type_t intr_type : only GPIO_INTR_LOLEVEL\GPIO_INTR_HILEVEL can be used
  *
  * @return ESP_OK: success
  *         ESP_ERR_INVALID_ARG: parameter error
  */
esp_err_t gpio_wakeup_enable(gpio_num_t gpio_num, gpio_int_type_t intr_type);

/**
  * @brief disable GPIO wake-up function.
  *
  * @param gpio_num_t gpio_num: GPIO number
  *
  * @return ESP_OK: success
  *         ESP_ERR_INVALID_ARG: parameter error
  */
esp_err_t gpio_wakeup_disable(gpio_num_t gpio_num);

/**
 * @brief   register GPIO interrupt handler, the handler is an ISR.
 *          The handler will be attached to the same CPU core that this function is running on.
 *          Users should know that which CPU is running and then pick a INUM that is not used by system.
 *          We can find the information of INUM and interrupt level in soc.h.
 *          TODO: to move INUM options to menu_config
 * @parameter   uint32_t gpio_intr_num     : GPIO interrupt number,check the info in soc.h, and please see the core-isa.h for more details
 * @parameter   void (* fn)(void* )       : interrupt handler function.
 *                                          Note that the handler function MUST be defined with attribution of "IRAM_ATTR".
 * @parameter   void * arg                : parameter for handler function
 *
 * @return      ESP_OK : success ;
 *              ESP_FAIL: gpio error
 */
esp_err_t gpio_isr_register(uint32_t gpio_intr_num, void (*fn)(void*), void * arg);

/**
 * ***************        ATTENTION       ********************/
/**
 *
 * Each GPIO has its own separate configuration register, so we do not use
 * a lock to serialize access to them. This works under the assumption that
 * no situation will occur where two tasks try to configure the same GPIO
 * pin simultaneously. It is up to the application developer to guarantee this.
 */


/*----------EXAMPLE TO CONIFGURE GPIO AS OUTPUT ------------ */
/*     gpio_config_t io_conf;
 *     io_conf.intr_type = GPIO_INTR_DISABLE;             //disable interrupt
 *     io_conf.mode = GPIO_MODE_OUTPUT;                       //set as output mode
 *     io_conf.pin_bit_mask = GPIO_SEL_18 | GPIO_SEL_19;      //bit mask of the pins that you want to set,e.g.GPIO18/19
 *     io_conf.pull_down_en = 0;                              //disable pull-down mode
 *     io_conf.pull_up_en = 0;                                //disable pull-up mode
 *     gpio_config(&io_conf);                                 //configure GPIO with the given settings
 **/
/*----------EXAMPLE TO CONIFGURE GPIO AS OUTPUT ------------ */
/*     io_conf.intr_type = GPIO_INTR_POSEDGE;             //set posedge interrupt
 *     io_conf.mode = GPIO_MODE_INPUT;                        //set as input
 *     io_conf.pin_bit_mask = GPIO_SEL_4 | GPIO_SEL_5;        //bit mask of the pins that you want to set, e.g.,GPIO4/5
 *     io_conf.pull_down_en = 0;                              //disable pull-down mode
 *     io_conf.pull_up_en = 1;                                //enable pull-up mode
 *     gpio_config(&io_conf);                                 //configure GPIO with the given settings
 *----------EXAMPLE TO SET ISR HANDLER ----------------------*/
/*     gpio_isr_register(18,gpio_intr_test,NULL);    //hook the isr handler for GPIO interrupt
 *                                                            //the first parameter is INUM, you can pick one form interrupt level 1/2 which is not used by the system.
 *                                                            //NOTE1:user should arrange the INUMs that used, better not to use a same INUM for different interrupt.
 *                                                            //NOTE2:do not pick the INUM that already occupied by the system.
 *                                                            //NOTE3:refer to soc.h to check which INUMs that can be used.
 *-------------EXAMPLE OF HANDLER FUNCTION-------------------*/
/*#include "esp_attr.h"
 * void IRAM_ATTR gpio_intr_test(void* arg)
 *{
 *  //GPIO intr process
 *  ets_printf("in gpio_intr\n");
 *  uint32_t gpio_num = 0;
 *  uint32_t gpio_intr_status = READ_PERI_REG(GPIO_STATUS_REG);   //read status to get interrupt status for GPIO0-31
 *  uint32_t gpio_intr_status_h = READ_PERI_REG(GPIO_STATUS1_REG);//read status1 to get interrupt status for GPIO32-39
 *  SET_PERI_REG_MASK(GPIO_STATUS_W1TC_REG, gpio_intr_status);    //Clear intr for gpio0-gpio31
 *  SET_PERI_REG_MASK(GPIO_STATUS1_W1TC_REG, gpio_intr_status_h); //Clear intr for gpio32-39
 *  do {
 *      if(gpio_num < 32) {
 *          if(gpio_intr_status & BIT(gpio_num)) { //gpio0-gpio31
 *              ets_printf("Intr GPIO%d ,val: %d\n",gpio_num,gpio_get_level(gpio_num));
 *              //This is an isr handler, you should post an event to process it in RTOS queue.
 *          }
 *      } else {
 *          if(gpio_intr_status_h & BIT(gpio_num - 32)) {
 *              ets_printf("Intr GPIO%d, val : %d\n",gpio_num,gpio_get_level(gpio_num));
 *              //This is an isr handler, you should post an event to process it in RTOS queue.
 *          }
 *      }
 *  } while(++gpio_num < GPIO_PIN_COUNT);
 *}
 *----EXAMPLE OF I2C CONFIG AND PICK SIGNAL FOR IO MATRIX---*/
/*     gpio_config_t io_conf;
 *     io_conf.intr_type = GPIO_INTR_DISABLE;                 //disable interrupt
 *     io_conf.mode = GPIO_MODE_INPUT_OUTPUT_OD;              //set as output mode
 *     io_conf.pin_bit_mask = GPIO_SEL_21 | GPIO_SEL_22;      //bit mask of the pins that you want to set,e.g.GPIO21/22
 *     io_conf.pull_down_en = 0;                              //disable pull-down mode
 *     io_conf.pull_up_en = 1;                                //enable pull-up mode
 *     gpio_config(&io_conf);                                 //configure GPIO with the given settings
 *     gpio_matrix_out(21, EXT_I2C_SCL_O_IDX, 0,  0);         //set output signal for io_matrix
 *     gpio_matrix_out(22, EXT_I2C_SDA_O_IDX, 0,  0);         //set output signal for io_matrix
 *     gpio_matrix_in( 22, EXT_I2C_SDA_I_IDX, 0);             //set input signal for io_matrix
 *
 */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _DRIVER_GPIO_H_ */
