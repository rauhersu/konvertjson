

#include <optional>
#include <string>
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <type_traits>

// Check value is of a type
//
template <typename T>
struct AlwaysFalse : std::false_type
{
};

template<typename T> bool IsJson(const rapidjson::Value& v) {
  static_assert(AlwaysFalse<T>::value, "Type not supported"); }

template<> bool IsJson<bool>(const rapidjson::Value& v ) {
  return v.IsBool(); }
template<> bool IsJson<int32_t>(const rapidjson::Value& v ) {
  return v.IsInt(); }
template<> bool IsJson<int64_t>(const rapidjson::Value& v ) {
  return v.IsInt64(); }
template<> bool IsJson<uint32_t>(const rapidjson::Value& v) {
  return v.IsUint(); }
template<> bool IsJson<uint64_t>(const rapidjson::Value& v) {
  return v.IsUint64(); }
template<> bool IsJson<float>(const rapidjson::Value& v) {
  return v.IsDouble(); }
template<> bool IsJson<double>(const rapidjson::Value& v) {
  return v.IsDouble(); }
template<> bool IsJson<std::string>(const rapidjson::Value& v) {
  return v.IsString(); }

// Get the value as a type
//
template<typename T> T GetJson(const rapidjson::Value& v) {
  static_assert(AlwaysFalse<T>::value, "Type not supported"); }
template<> bool GetJson<bool>(const rapidjson::Value& v) {
  return v.GetBool(); }
template<> int32_t GetJson<int32_t>(const rapidjson::Value& v) {
  return v.GetInt(); }
template<> uint32_t GetJson<uint32_t>(const rapidjson::Value& v) {
  return v.GetUint(); }
template<> int64_t GetJson<int64_t>(const rapidjson::Value& v) {
  return v.GetInt64(); }
template<> uint64_t GetJson<uint64_t>(const rapidjson::Value& v) {
  return v.GetUint64(); }
template<> float GetJson<float>(const rapidjson::Value& v) {
  return v.GetDouble(); }
template<> double GetJson<double>(const rapidjson::Value& v) {
  return v.GetDouble(); }
template<> std::string GetJson<std::string>(const rapidjson::Value& v) {
  return v.GetString(); }

// Check optional
//
// template< typename T >
// struct IsOptional : public std::false_type {
// };

// template< typename T >
// struct IsOptional< std::optional< T > > : public std::true_type {
// };

// template< typename T >
// constexpr bool IsOptionalValue = IsOptional< T >::value;

template<template<class...> class tmpl, typename T>
struct _is_template_for : public std::false_type {};

template<template<class...> class tmpl, class... Args>
struct _is_template_for<tmpl, tmpl<Args...>> : public std::true_type {};

template<template<class...> class tmpl, typename... Ts>
using is_template_for = std::conjunction<_is_template_for<tmpl, std::decay_t<Ts>>...>;

template<template<class...> class tmpl, typename... Ts>
constexpr bool is_template_for_v = is_template_for<tmpl, Ts...>::value;

// function that tries to obtain a value with the given name
//
// template <typename Element, typename Target, typename TargetOptionalOf = std::result_of_t<Target(void)>::value_type > >
// template <typename Element, typename Target, typename TargetOptionalOf = 
// template <typename Element, typename Target, typename TargetOptionalOf = Target >

//You can change the `std::result_of_t<...>` for `typename std::result_of<...>::type` to make it work in C++11 :)

template <typename Element, typename Target >
bool GetJsonValue(const Element &element, const char* name, Target& target) {

  //   typename std::conditional<std::is_void<T>::value, _X<> : _X<T>>::type
  if constexpr(is_template_for_v<std::optional, Target>)
  {
        typedef typename Target::value_type TargetOfOptional;
        auto it = element.FindMember(name);
        if (it != element.MemberEnd() && IsJson<TargetOfOptional>(it->value))
          {
            target = std::move(GetJson<TargetOfOptional>(it->value));
            return true;
          }
        return false;
   }
   else
     {
       // static_assert(!is_template_for_v<std::optional, Target>, "Optional type not supported" );
       auto it = element.FindMember(name);
       if (it != element.MemberEnd() && IsJson<Target>(it->value))
         {
           target = std::move(GetJson<Target>(it->value));
           return true;
         }
       return false;
     }
}


