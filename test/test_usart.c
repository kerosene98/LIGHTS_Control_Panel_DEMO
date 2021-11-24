#ifdef TEST

#include "unity.h"

// TODO create test case framework for USART!!

#include "davesusart.h"

void setUp(void)
{
    #define STM32F446xx
}

void tearDown(void)
{
}

void test_usart_read(void)
{
    TEST_ASSERT_EQUAL('A', 1);
}

#endif // TEST
