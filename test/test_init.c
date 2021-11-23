#ifdef TEST

#include "unity.h"

#include "init.h"
#include "mock_stm32f4xx_hal.h"

#define STM32F446xx

void setUp(void)
{
}

void tearDown(void)
{
}

void test_RCCinit(void)
{
    TEST_ASSERT_EQUAL(0x0001, GPIOAEN);
    TEST_ASSERT_EQUAL(0x20000, USART2EN);
}

void test_GPIOinit(void)
{
    //AF7 function PA2 & PA3 0111 0111 0000 0000
    TEST_ASSERT_EQUAL(0x7700, PA2_AF7 | PA3_AF7);
    TEST_ASSERT_EQUAL(0x04A0, MODER2_AF | MODER3_AF | MODER5_OUTPUT);
}

void test_USARTinit(void)
{
    TEST_ASSERT_EQUAL(0x0683, baud_9600);
    TEST_ASSERT_EQUAL(0x000C, TE | RE);
    TEST_ASSERT_EQUAL(0x2000, UE);
}

#endif // TEST
