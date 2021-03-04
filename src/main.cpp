#include <konvertjson.h>

int main() {

  std::string jsonString("{\"id\":\"abc\",\"number\":123}");
  rapidjson::Document doc;
  doc.Parse(jsonString.c_str());
 uint32_t number;
 GetJsonValue(doc,"number",number);
 std::cout << number << std::endl;

 std::string id;
 GetJsonValue(doc,"id",id);
 std::cout << id << std::endl;

 std::optional<std::string> idOpt;
 GetJsonValue(doc,"id",idOpt);
 std::cout << idOpt.value() << std::endl;

 return 0;
}
