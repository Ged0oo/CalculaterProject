/*
 * APP.c
 *
 * Created: 10/21/2022 7:40:36 PM
 *  Author: Mohamed Nagy
 */ 

#include "APP.h"

Std_ReturnType ret = E_OK;

/*
sint8 keypad_read = -1;
uint8 PIN[4];
uint8 password[4] = "0000";
uint8 checkPassword[4];
uint8 mode = -1;
*/

char_4bit_lcd_t lcd_1 =
{
	.lcd_rs.port=PORTB_INDEX,
	.lcd_rs.pin=GPIO_PIN1,
	.lcd_rs.pin_direction=GPIO_DIRECTION_OUTPUT,
	.lcd_rs.pin_logic=GPIO_LOW,
	
	.lcd_en.port=PORTB_INDEX,
	.lcd_en.pin=GPIO_PIN3,
	.lcd_en.pin_direction=GPIO_DIRECTION_OUTPUT,
	.lcd_en.pin_logic=GPIO_LOW,
	
	.lcd_data[0].port=PORTA_INDEX,
	.lcd_data[0].pin=GPIO_PIN4,
	.lcd_data[0].pin_direction=GPIO_DIRECTION_OUTPUT,
	.lcd_data[0].pin_logic=GPIO_LOW,
	
	.lcd_data[1].port=PORTA_INDEX,
	.lcd_data[1].pin=GPIO_PIN5,
	.lcd_data[1].pin_direction=GPIO_DIRECTION_OUTPUT,
	.lcd_data[1].pin_logic=GPIO_LOW,
	
	.lcd_data[2].port=PORTA_INDEX,
	.lcd_data[2].pin=GPIO_PIN6,
	.lcd_data[2].pin_direction=GPIO_DIRECTION_OUTPUT,
	.lcd_data[2].pin_logic=GPIO_LOW,
	
	.lcd_data[3].port=PORTA_INDEX,
	.lcd_data[3].pin=GPIO_PIN7,
	.lcd_data[3].pin_direction=GPIO_DIRECTION_OUTPUT,
	.lcd_data[3].pin_logic=GPIO_LOW,
	
};

/*
ST_keypad_t keypad_1 =
{
	.keypad_row_pin[0].port=PORTD_INDEX,
	.keypad_row_pin[0].pin=GPIO_PIN0,
	.keypad_row_pin[0].pin_direction=GPIO_DIRECTION_OUTPUT,
	.keypad_row_pin[0].pin_logic=GPIO_LOW,
	
	.keypad_row_pin[1].port=PORTD_INDEX,
	.keypad_row_pin[1].pin=GPIO_PIN1,
	.keypad_row_pin[1].pin_direction=GPIO_DIRECTION_OUTPUT,
	.keypad_row_pin[1].pin_logic=GPIO_LOW,
	
	.keypad_row_pin[2].port=PORTD_INDEX,
	.keypad_row_pin[2].pin=GPIO_PIN2,
	.keypad_row_pin[2].pin_direction=GPIO_DIRECTION_OUTPUT,
	.keypad_row_pin[2].pin_logic=GPIO_LOW,
	
	.keypad_row_pin[3].port=PORTD_INDEX,
	.keypad_row_pin[3].pin=GPIO_PIN3,
	.keypad_row_pin[3].pin_direction=GPIO_DIRECTION_OUTPUT,
	.keypad_row_pin[3].pin_logic=GPIO_LOW,
	
	.keypad_column_pin[0].port=PORTD_INDEX,
	.keypad_column_pin[0].pin=GPIO_PIN4,
	.keypad_column_pin[0].pin_direction=GPIO_DIRECTION_INPUT,
	.keypad_column_pin[0].pin_logic=GPIO_LOW,
	
	.keypad_column_pin[1].port=PORTD_INDEX,
	.keypad_column_pin[1].pin=GPIO_PIN5,
	.keypad_column_pin[1].pin_direction=GPIO_DIRECTION_INPUT,
	.keypad_column_pin[1].pin_logic=GPIO_LOW,
	
	.keypad_column_pin[2].port=PORTD_INDEX,
	.keypad_column_pin[2].pin=GPIO_PIN6,
	.keypad_column_pin[2].pin_direction=GPIO_DIRECTION_INPUT,
	.keypad_column_pin[2].pin_logic=GPIO_LOW,
	
	.keypad_column_pin[3].port=PORTD_INDEX,
	.keypad_column_pin[3].pin=GPIO_PIN7,
	.keypad_column_pin[3].pin_direction=GPIO_DIRECTION_INPUT,
	.keypad_column_pin[3].pin_logic=GPIO_LOW,
};

 ST_led_t led_1 =
 {
	 .port = PORTB_INDEX,
	 .pin = GPIO_PIN2,
	 .status = LED_OFF
 };
 
*/
 
 
  ST_pinCofig_t LCD_RW =
  {
	  .port = PORTB_INDEX,
	  .pin = GPIO_PIN2,
	  .pin_direction = GPIO_DIRECTION_OUTPUT,
	  .pin_logic = GPIO_LOW
  };
  
  
void appStart()
{
	
	ret = gpio_pin_init(&LCD_RW);
	ret = LCD_4Bit_Init(&lcd_1);
	
	while(1)
	{
		ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "Welcome.", 1,5);
		_delay_ms(1000);
		
		ret = LCD_4Bit_Send_Command(&lcd_1,_LCD_CLEAR);
		_delay_ms(100);
	}
	
	/*
	
	ret = Led_Init(&led_1);
	ret = LCD_4Bit_Init(&lcd_1);
	ret = keypad_intialize(&keypad_1);
	
	ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "Welcome.", 2,6);
	_delay_ms(1000);
	
	ret = LCD_4Bit_Send_Command(&lcd_1,_LCD_CLEAR);
	_delay_ms(100);
	
	
	ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "Check Password :", 2,1);
	for(uint8 counter=0 ; counter<4 ; counter++)
	{
		keypad_read = -1;
		do
		{
			ret = keypad_get_value(&keypad_1, &keypad_read);
		}
		while(keypad_read == -1);
		
		checkPassword[counter] = keypad_read;
		
		ret = LCD_4Bit_send_Data_char_Pos(&lcd_1, keypad_read, 3, 1+counter);
		_delay_ms(500);
		ret = LCD_4Bit_send_Data_char_Pos(&lcd_1, '*', 3, 1+counter);
	}
	
	if
	( (checkPassword[0] == password[0])
	&&(checkPassword[1] == password[1])
	&&(checkPassword[2] == password[2])
	&&(checkPassword[3] == password[3]))
	{
		ret = LCD_4Bit_Send_Command(&lcd_1, _LCD_CLEAR);
		_delay_ms(100);
		
		ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "Correct Password.", 2,1);
		_delay_ms(1000);
		
		ret = LCD_4Bit_Send_Command(&lcd_1, _LCD_CLEAR);
		_delay_ms(100);
		
		ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "Which Mode : ", 1,1);
		ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "1- Calculator : ", 2,1);
		ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "2- Blinking Led : ", 3,1);
		_delay_ms(500);
		
		keypad_read = -1;
		do
		{
			ret = keypad_get_value(&keypad_1, &keypad_read);
		}
		while(keypad_read == -1);
		
		if(keypad_read == '1')
		{
			calculatorMode();
		}
		else if(keypad_read == '2')
		{
			blinkingLedMode();
		}
		else
		{
			ret = LCD_4Bit_Send_Command(&lcd_1, _LCD_CLEAR);
			_delay_ms(100);
			
			ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "Wrong Mode.", 2,1);
			_delay_ms(500);
		}
	}
	else
	{
			ret = LCD_4Bit_Send_Command(&lcd_1, _LCD_CLEAR);
			_delay_ms(100);
			
			ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "Wrong Password.", 2,1);
			_delay_ms(500);
	}
	*/
}

/*

void calculatorMode()
{
	ret = LCD_4Bit_Send_Command(&lcd_1, _LCD_CLEAR);
	_delay_ms(100);
	
	ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "calculator Mode.", 2,1);
	_delay_ms(500);
}


void blinkingLedMode()
{
	ret = LCD_4Bit_Send_Command(&lcd_1, _LCD_CLEAR);
	_delay_ms(100);
	
	ret = LCD_4Bit_send_Data_String_Pos(&lcd_1, "Blinking Mode.", 2,1);
	_delay_ms(500);
}

*/