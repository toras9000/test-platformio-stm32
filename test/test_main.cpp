#include <Arduino.h>
#include <unity.h>

void setUp(void)
{
  Serial.begin(115200);
  Serial.println("Unit Testing");
}

void tearDown(void)
{
}

void setup()
{
  // Wait ~2 seconds before the Unity test runner
  // establishes connection with a board Serial interface
  delay(5000);

  UNITY_BEGIN();
  void test_json();
  test_json();
  void test_base64();
  test_base64();
  UNITY_END();
}
void loop() {}
