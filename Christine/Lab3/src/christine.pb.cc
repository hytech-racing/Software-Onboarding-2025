// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/christine/christine.proto

#include "christine.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace christine {
PROTOBUF_CONSTEXPR Client::Client(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.sender_name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.message_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ClientDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ClientDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ClientDefaultTypeInternal() {}
  union {
    Client _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ClientDefaultTypeInternal _Client_default_instance_;
}  // namespace christine
static ::_pb::Metadata file_level_metadata_proto_2fchristine_2fchristine_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_proto_2fchristine_2fchristine_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_proto_2fchristine_2fchristine_2eproto = nullptr;

const uint32_t TableStruct_proto_2fchristine_2fchristine_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::christine::Client, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::christine::Client, _impl_.sender_name_),
  PROTOBUF_FIELD_OFFSET(::christine::Client, _impl_.message_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::christine::Client)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::christine::_Client_default_instance_._instance,
};

const char descriptor_table_protodef_proto_2fchristine_2fchristine_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\037proto/christine/christine.proto\022\tchris"
  "tine\".\n\006Client\022\023\n\013sender_name\030\001 \001(\t\022\017\n\007m"
  "essage\030\002 \001(\tb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_proto_2fchristine_2fchristine_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_proto_2fchristine_2fchristine_2eproto = {
    false, false, 100, descriptor_table_protodef_proto_2fchristine_2fchristine_2eproto,
    "proto/christine/christine.proto",
    &descriptor_table_proto_2fchristine_2fchristine_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_proto_2fchristine_2fchristine_2eproto::offsets,
    file_level_metadata_proto_2fchristine_2fchristine_2eproto, file_level_enum_descriptors_proto_2fchristine_2fchristine_2eproto,
    file_level_service_descriptors_proto_2fchristine_2fchristine_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_proto_2fchristine_2fchristine_2eproto_getter() {
  return &descriptor_table_proto_2fchristine_2fchristine_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_proto_2fchristine_2fchristine_2eproto(&descriptor_table_proto_2fchristine_2fchristine_2eproto);
namespace christine {

// ===================================================================

class Client::_Internal {
 public:
};

Client::Client(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:christine.Client)
}
Client::Client(const Client& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Client* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.sender_name_){}
    , decltype(_impl_.message_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.sender_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.sender_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_sender_name().empty()) {
    _this->_impl_.sender_name_.Set(from._internal_sender_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.message_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.message_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_message().empty()) {
    _this->_impl_.message_.Set(from._internal_message(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:christine.Client)
}

inline void Client::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.sender_name_){}
    , decltype(_impl_.message_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.sender_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.sender_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.message_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.message_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Client::~Client() {
  // @@protoc_insertion_point(destructor:christine.Client)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Client::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.sender_name_.Destroy();
  _impl_.message_.Destroy();
}

void Client::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Client::Clear() {
// @@protoc_insertion_point(message_clear_start:christine.Client)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.sender_name_.ClearToEmpty();
  _impl_.message_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Client::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string sender_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_sender_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "christine.Client.sender_name"));
        } else
          goto handle_unusual;
        continue;
      // string message = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_message();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "christine.Client.message"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Client::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:christine.Client)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string sender_name = 1;
  if (!this->_internal_sender_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_sender_name().data(), static_cast<int>(this->_internal_sender_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "christine.Client.sender_name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_sender_name(), target);
  }

  // string message = 2;
  if (!this->_internal_message().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_message().data(), static_cast<int>(this->_internal_message().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "christine.Client.message");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_message(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:christine.Client)
  return target;
}

size_t Client::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:christine.Client)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string sender_name = 1;
  if (!this->_internal_sender_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sender_name());
  }

  // string message = 2;
  if (!this->_internal_message().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_message());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Client::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Client::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Client::GetClassData() const { return &_class_data_; }


void Client::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Client*>(&to_msg);
  auto& from = static_cast<const Client&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:christine.Client)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_sender_name().empty()) {
    _this->_internal_set_sender_name(from._internal_sender_name());
  }
  if (!from._internal_message().empty()) {
    _this->_internal_set_message(from._internal_message());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Client::CopyFrom(const Client& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:christine.Client)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Client::IsInitialized() const {
  return true;
}

void Client::InternalSwap(Client* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.sender_name_, lhs_arena,
      &other->_impl_.sender_name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.message_, lhs_arena,
      &other->_impl_.message_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata Client::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_proto_2fchristine_2fchristine_2eproto_getter, &descriptor_table_proto_2fchristine_2fchristine_2eproto_once,
      file_level_metadata_proto_2fchristine_2fchristine_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace christine
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::christine::Client*
Arena::CreateMaybeMessage< ::christine::Client >(Arena* arena) {
  return Arena::CreateMessageInternal< ::christine::Client >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>