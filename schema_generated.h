// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SCHEMA_TEST_H_
#define FLATBUFFERS_GENERATED_SCHEMA_TEST_H_

#include "flatbuffers/flatbuffers.h"

namespace test {

struct Person;
struct PersonBuilder;

struct GroupOfPerson;
struct GroupOfPersonBuilder;

struct client;
struct clientBuilder;

enum Any : uint8_t {
  Any_NONE = 0,
  Any_Person = 1,
  Any_GroupOfPerson = 2,
  Any_MIN = Any_NONE,
  Any_MAX = Any_GroupOfPerson
};

inline const Any (&EnumValuesAny())[3] {
  static const Any values[] = {
    Any_NONE,
    Any_Person,
    Any_GroupOfPerson
  };
  return values;
}

inline const char * const *EnumNamesAny() {
  static const char * const names[4] = {
    "NONE",
    "Person",
    "GroupOfPerson",
    nullptr
  };
  return names;
}

inline const char *EnumNameAny(Any e) {
  if (flatbuffers::IsOutRange(e, Any_NONE, Any_GroupOfPerson)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesAny()[index];
}

template<typename T> struct AnyTraits {
  static const Any enum_value = Any_NONE;
};

template<> struct AnyTraits<test::Person> {
  static const Any enum_value = Any_Person;
};

template<> struct AnyTraits<test::GroupOfPerson> {
  static const Any enum_value = Any_GroupOfPerson;
};

bool VerifyAny(flatbuffers::Verifier &verifier, const void *obj, Any type);
bool VerifyAnyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Person FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PersonBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_AGE = 6,
    VT_WEIGHT = 8,
    VT_GENDER = 10
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  int32_t age() const {
    return GetField<int32_t>(VT_AGE, 0);
  }
  float weight() const {
    return GetField<float>(VT_WEIGHT, 0.0f);
  }
  uint8_t gender() const {
    return GetField<uint8_t>(VT_GENDER, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<int32_t>(verifier, VT_AGE) &&
           VerifyField<float>(verifier, VT_WEIGHT) &&
           VerifyField<uint8_t>(verifier, VT_GENDER) &&
           verifier.EndTable();
  }
};

struct PersonBuilder {
  typedef Person Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Person::VT_NAME, name);
  }
  void add_age(int32_t age) {
    fbb_.AddElement<int32_t>(Person::VT_AGE, age, 0);
  }
  void add_weight(float weight) {
    fbb_.AddElement<float>(Person::VT_WEIGHT, weight, 0.0f);
  }
  void add_gender(uint8_t gender) {
    fbb_.AddElement<uint8_t>(Person::VT_GENDER, gender, 0);
  }
  explicit PersonBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Person> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Person>(end);
    return o;
  }
};

inline flatbuffers::Offset<Person> CreatePerson(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    int32_t age = 0,
    float weight = 0.0f,
    uint8_t gender = 0) {
  PersonBuilder builder_(_fbb);
  builder_.add_weight(weight);
  builder_.add_age(age);
  builder_.add_name(name);
  builder_.add_gender(gender);
  return builder_.Finish();
}

inline flatbuffers::Offset<Person> CreatePersonDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int32_t age = 0,
    float weight = 0.0f,
    uint8_t gender = 0) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return test::CreatePerson(
      _fbb,
      name__,
      age,
      weight,
      gender);
}

struct GroupOfPerson FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GroupOfPersonBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_GROUP_NAME = 4,
    VT_AVERAGE_WEIGHT = 6,
    VT_AVERAGE_HIGHT = 8,
    VT_LIST_OF_NAME = 10
  };
  const flatbuffers::String *group_name() const {
    return GetPointer<const flatbuffers::String *>(VT_GROUP_NAME);
  }
  int32_t average_weight() const {
    return GetField<int32_t>(VT_AVERAGE_WEIGHT, 0);
  }
  int32_t average_hight() const {
    return GetField<int32_t>(VT_AVERAGE_HIGHT, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *list_of_name() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_LIST_OF_NAME);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_GROUP_NAME) &&
           verifier.VerifyString(group_name()) &&
           VerifyField<int32_t>(verifier, VT_AVERAGE_WEIGHT) &&
           VerifyField<int32_t>(verifier, VT_AVERAGE_HIGHT) &&
           VerifyOffset(verifier, VT_LIST_OF_NAME) &&
           verifier.VerifyVector(list_of_name()) &&
           verifier.VerifyVectorOfStrings(list_of_name()) &&
           verifier.EndTable();
  }
};

struct GroupOfPersonBuilder {
  typedef GroupOfPerson Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_group_name(flatbuffers::Offset<flatbuffers::String> group_name) {
    fbb_.AddOffset(GroupOfPerson::VT_GROUP_NAME, group_name);
  }
  void add_average_weight(int32_t average_weight) {
    fbb_.AddElement<int32_t>(GroupOfPerson::VT_AVERAGE_WEIGHT, average_weight, 0);
  }
  void add_average_hight(int32_t average_hight) {
    fbb_.AddElement<int32_t>(GroupOfPerson::VT_AVERAGE_HIGHT, average_hight, 0);
  }
  void add_list_of_name(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> list_of_name) {
    fbb_.AddOffset(GroupOfPerson::VT_LIST_OF_NAME, list_of_name);
  }
  explicit GroupOfPersonBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<GroupOfPerson> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GroupOfPerson>(end);
    return o;
  }
};

inline flatbuffers::Offset<GroupOfPerson> CreateGroupOfPerson(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> group_name = 0,
    int32_t average_weight = 0,
    int32_t average_hight = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> list_of_name = 0) {
  GroupOfPersonBuilder builder_(_fbb);
  builder_.add_list_of_name(list_of_name);
  builder_.add_average_hight(average_hight);
  builder_.add_average_weight(average_weight);
  builder_.add_group_name(group_name);
  return builder_.Finish();
}

inline flatbuffers::Offset<GroupOfPerson> CreateGroupOfPersonDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *group_name = nullptr,
    int32_t average_weight = 0,
    int32_t average_hight = 0,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *list_of_name = nullptr) {
  auto group_name__ = group_name ? _fbb.CreateString(group_name) : 0;
  auto list_of_name__ = list_of_name ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*list_of_name) : 0;
  return test::CreateGroupOfPerson(
      _fbb,
      group_name__,
      average_weight,
      average_hight,
      list_of_name__);
}

struct client FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef clientBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TEST_TYPE = 4,
    VT_TEST = 6
  };
  test::Any test_type() const {
    return static_cast<test::Any>(GetField<uint8_t>(VT_TEST_TYPE, 0));
  }
  const void *test() const {
    return GetPointer<const void *>(VT_TEST);
  }
  template<typename T> const T *test_as() const;
  const test::Person *test_as_Person() const {
    return test_type() == test::Any_Person ? static_cast<const test::Person *>(test()) : nullptr;
  }
  const test::GroupOfPerson *test_as_GroupOfPerson() const {
    return test_type() == test::Any_GroupOfPerson ? static_cast<const test::GroupOfPerson *>(test()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_TEST_TYPE) &&
           VerifyOffset(verifier, VT_TEST) &&
           VerifyAny(verifier, test(), test_type()) &&
           verifier.EndTable();
  }
};

template<> inline const test::Person *client::test_as<test::Person>() const {
  return test_as_Person();
}

template<> inline const test::GroupOfPerson *client::test_as<test::GroupOfPerson>() const {
  return test_as_GroupOfPerson();
}

struct clientBuilder {
  typedef client Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_test_type(test::Any test_type) {
    fbb_.AddElement<uint8_t>(client::VT_TEST_TYPE, static_cast<uint8_t>(test_type), 0);
  }
  void add_test(flatbuffers::Offset<void> test) {
    fbb_.AddOffset(client::VT_TEST, test);
  }
  explicit clientBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<client> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<client>(end);
    return o;
  }
};

inline flatbuffers::Offset<client> Createclient(
    flatbuffers::FlatBufferBuilder &_fbb,
    test::Any test_type = test::Any_NONE,
    flatbuffers::Offset<void> test = 0) {
  clientBuilder builder_(_fbb);
  builder_.add_test(test);
  builder_.add_test_type(test_type);
  return builder_.Finish();
}

inline bool VerifyAny(flatbuffers::Verifier &verifier, const void *obj, Any type) {
  switch (type) {
    case Any_NONE: {
      return true;
    }
    case Any_Person: {
      auto ptr = reinterpret_cast<const test::Person *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Any_GroupOfPerson: {
      auto ptr = reinterpret_cast<const test::GroupOfPerson *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return true;
  }
}

inline bool VerifyAnyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyAny(
        verifier,  values->Get(i), types->GetEnum<Any>(i))) {
      return false;
    }
  }
  return true;
}

inline const test::client *Getclient(const void *buf) {
  return flatbuffers::GetRoot<test::client>(buf);
}

inline const test::client *GetSizePrefixedclient(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<test::client>(buf);
}

inline bool VerifyclientBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<test::client>(nullptr);
}

inline bool VerifySizePrefixedclientBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<test::client>(nullptr);
}

inline void FinishclientBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<test::client> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedclientBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<test::client> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace test

#endif  // FLATBUFFERS_GENERATED_SCHEMA_TEST_H_