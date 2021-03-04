#include <konvertjson.h>
#include "gtest/gtest.h"

using namespace std;

 TEST(konvertjsonTest, konvertjson_getValuesNonOptional) {

  std::string jsonString("{\"id\":\"abc\",\"number\":123}");

  rapidjson::Document doc;
  doc.Parse(jsonString.c_str());

  uint32_t number;
  GetJsonValue(doc,"number",number);
  EXPECT_EQ(static_cast<uint32_t>(123),number);
  //  std::cout << number << std::endl;

  std::string id;
  GetJsonValue(doc,"id",id);
  EXPECT_EQ("abc",id);
  //  std::cout << id << std::endl;

}

 TEST(konvertjsonTest, konvertjson_getValuesOptional) {

  std::string jsonString("{\"id\":\"abc\",\"number\":123}");
  rapidjson::Document doc;
  doc.Parse(jsonString.c_str());

  std::optional<std::string> idOpt;
  GetJsonValue(doc,"id",idOpt);
  EXPECT_EQ("abc",idOpt);
  //  std::cout << idOpt.value() << std::endl;
}
