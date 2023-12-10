#include <Arduino.h>
#include <Base64.h>
#include <Base64.hpp>
#include <unity.h>

void test_base64_encode()
{
  uint8_t source[] = {
      0x12,
      0x34,
      0x56,
  };
  uint8_t buff[sizeof(source) * 2];

  {
    auto len = Base64.encode(buff, source, sizeof(source));
    Serial.println(buff);
  }
  {
    auto len = encode_base64(source, sizeof(source), buff);
    Serial.println(buff);
  }
}

void test_base64()
{
  Serial.println("Test Base64 ");

  RUN_TEST(test_base64_encode);
}
