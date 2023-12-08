#include <Arduino.h>
#include <ArduinoJson.h>
#include <unity.h>

void test_json_deserialize()
{
  static const char *jsonText =
      "{"
      "   \"propInteger\": 100,"
      "   \"propFloat\": 2.345,"
      "   \"propString\": \"abcd\","
      "   \"propStrNum\": \"999\""
      "}";

  auto doc = DynamicJsonDocument(1024);
  auto error = deserializeJson(doc, jsonText);
  TEST_ASSERT_FALSE(error);

  TEST_ASSERT_EQUAL_INT(100, doc["propInteger"]);
  TEST_ASSERT_EQUAL_FLOAT(2.345f, doc["propFloat"]);
  TEST_ASSERT_EQUAL_STRING("abcd", doc["propString"]);
  TEST_ASSERT_EQUAL_STRING("999", doc["propStrNum"]);
  TEST_ASSERT_EQUAL_INT(999, doc["propStrNum"]);
  TEST_ASSERT_EQUAL_INT(0, doc["propString"]);

  TEST_ASSERT_EQUAL_INT(100, doc["propInteger"].as<int>());
  TEST_ASSERT_EQUAL_FLOAT(2.345f, doc["propFloat"].as<float>());
  TEST_ASSERT_EQUAL_STRING("abcd", doc["propString"].as<const char *>());
  TEST_ASSERT_EQUAL_STRING("999", doc["propStrNum"].as<const char *>());
  TEST_ASSERT_EQUAL_INT(999, doc["propStrNum"].as<int>());
  TEST_ASSERT_EQUAL_INT(0, doc["propString"].as<int>());
}

void test_json()
{
  Serial.println("Test Json");

  RUN_TEST(test_json_deserialize);
}
