#include "build/test/mocks/mock_stm32f4xx_hal.h"
#include "Inc/init.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"












void setUp(void)

{

}



void tearDown(void)

{

}



void test_RCCinit(void)

{

    UnityAssertEqualNumber((UNITY_INT)((0x0001)), (UNITY_INT)(((1 << 0))), (

   ((void *)0)

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x20000)), (UNITY_INT)(((1 << 17))), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

}



void test_GPIOinit(void)

{



    UnityAssertEqualNumber((UNITY_INT)((0x7700)), (UNITY_INT)((0x0700 | 0x7000)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x04A0)), (UNITY_INT)((0x0020 | 0x0080 | 0x0400)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}



void test_USARTinit(void)

{

    UnityAssertEqualNumber((UNITY_INT)((0x0683)), (UNITY_INT)((0x0683)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x000C)), (UNITY_INT)((0x0008 | 0x0004)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x2000)), (UNITY_INT)((0x2000)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}
