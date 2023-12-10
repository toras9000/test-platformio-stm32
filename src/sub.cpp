#include <Arduino.h>
#include <Base64.h>
#include <Base64.hpp>
#include <arduino_base64.hpp>

void sub_loop()
{
  static int counter = 0;

  Serial.println("Base64 Test sub");

  static bool init = false;
  static uint8_t source[1024];
  static char buff[sizeof(source) * 2];

  if (!init)
  {
    for (auto i = 0; i < sizeof(source); i++)
    {
      source[i] = (uint8_t)i;
    }
  }

  uint32_t time1, time2, time3;
  {
    uint32_t begin = micros();
    auto len = Base64.encode(buff, (char *)source, sizeof(source));
    Serial.printf("Base64(1): %s\n", buff);
    time1 = micros() - begin;
  }
  {
    uint32_t begin = micros();
    auto len = encode_base64(source, sizeof(source), (uint8_t *)buff);
    Serial.printf("Base64(2): %s\n", buff);
    time2 = micros() - begin;
  }
  {
    uint32_t begin = micros();
    base64::encode(source, sizeof(source), buff);
    Serial.printf("Base64(3): %s\n", buff);
    time3 = micros() - begin;
  }
  Serial.printf("Time1: %u\n", time1);
  Serial.printf("Time2: %u\n", time2);
  Serial.printf("Time3: %u\n", time3);
}
