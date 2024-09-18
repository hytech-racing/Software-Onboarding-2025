// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protobuf.proto
// Protobuf C++ Version: 4.25.4

#ifndef GOOGLE_PROTOBUF_INCLUDED_protobuf_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_protobuf_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025004 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_protobuf_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_protobuf_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_protobuf_2eproto;
namespace OnboardingLab3 {
class SimpleMessage;
struct SimpleMessageDefaultTypeInternal;
extern SimpleMessageDefaultTypeInternal _SimpleMessage_default_instance_;
}  // namespace OnboardingLab3
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace OnboardingLab3 {

// ===================================================================


// -------------------------------------------------------------------

class SimpleMessage final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:OnboardingLab3.SimpleMessage) */ {
 public:
  inline SimpleMessage() : SimpleMessage(nullptr) {}
  ~SimpleMessage() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR SimpleMessage(::google::protobuf::internal::ConstantInitialized);

  inline SimpleMessage(const SimpleMessage& from)
      : SimpleMessage(nullptr, from) {}
  SimpleMessage(SimpleMessage&& from) noexcept
    : SimpleMessage() {
    *this = ::std::move(from);
  }

  inline SimpleMessage& operator=(const SimpleMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline SimpleMessage& operator=(SimpleMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SimpleMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const SimpleMessage* internal_default_instance() {
    return reinterpret_cast<const SimpleMessage*>(
               &_SimpleMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SimpleMessage& a, SimpleMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(SimpleMessage* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SimpleMessage* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SimpleMessage* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<SimpleMessage>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const SimpleMessage& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const SimpleMessage& from) {
    SimpleMessage::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(SimpleMessage* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "OnboardingLab3.SimpleMessage";
  }
  protected:
  explicit SimpleMessage(::google::protobuf::Arena* arena);
  SimpleMessage(::google::protobuf::Arena* arena, const SimpleMessage& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSenderNameFieldNumber = 1,
    kSenderMessageFieldNumber = 2,
  };
  // optional string sender_name = 1;
  bool has_sender_name() const;
  void clear_sender_name() ;
  const std::string& sender_name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_sender_name(Arg_&& arg, Args_... args);
  std::string* mutable_sender_name();
  PROTOBUF_NODISCARD std::string* release_sender_name();
  void set_allocated_sender_name(std::string* value);

  private:
  const std::string& _internal_sender_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_sender_name(
      const std::string& value);
  std::string* _internal_mutable_sender_name();

  public:
  // optional string sender_message = 2;
  bool has_sender_message() const;
  void clear_sender_message() ;
  const std::string& sender_message() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_sender_message(Arg_&& arg, Args_... args);
  std::string* mutable_sender_message();
  PROTOBUF_NODISCARD std::string* release_sender_message();
  void set_allocated_sender_message(std::string* value);

  private:
  const std::string& _internal_sender_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_sender_message(
      const std::string& value);
  std::string* _internal_mutable_sender_message();

  public:
  // @@protoc_insertion_point(class_scope:OnboardingLab3.SimpleMessage)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      62, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr sender_name_;
    ::google::protobuf::internal::ArenaStringPtr sender_message_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_protobuf_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// SimpleMessage

// optional string sender_name = 1;
inline bool SimpleMessage::has_sender_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void SimpleMessage::clear_sender_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.sender_name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& SimpleMessage::sender_name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:OnboardingLab3.SimpleMessage.sender_name)
  return _internal_sender_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void SimpleMessage::set_sender_name(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.sender_name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:OnboardingLab3.SimpleMessage.sender_name)
}
inline std::string* SimpleMessage::mutable_sender_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_sender_name();
  // @@protoc_insertion_point(field_mutable:OnboardingLab3.SimpleMessage.sender_name)
  return _s;
}
inline const std::string& SimpleMessage::_internal_sender_name() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.sender_name_.Get();
}
inline void SimpleMessage::_internal_set_sender_name(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.sender_name_.Set(value, GetArena());
}
inline std::string* SimpleMessage::_internal_mutable_sender_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.sender_name_.Mutable( GetArena());
}
inline std::string* SimpleMessage::release_sender_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:OnboardingLab3.SimpleMessage.sender_name)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.sender_name_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.sender_name_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void SimpleMessage::set_allocated_sender_name(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.sender_name_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.sender_name_.IsDefault()) {
          _impl_.sender_name_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:OnboardingLab3.SimpleMessage.sender_name)
}

// optional string sender_message = 2;
inline bool SimpleMessage::has_sender_message() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void SimpleMessage::clear_sender_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.sender_message_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& SimpleMessage::sender_message() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:OnboardingLab3.SimpleMessage.sender_message)
  return _internal_sender_message();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void SimpleMessage::set_sender_message(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.sender_message_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:OnboardingLab3.SimpleMessage.sender_message)
}
inline std::string* SimpleMessage::mutable_sender_message() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_sender_message();
  // @@protoc_insertion_point(field_mutable:OnboardingLab3.SimpleMessage.sender_message)
  return _s;
}
inline const std::string& SimpleMessage::_internal_sender_message() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.sender_message_.Get();
}
inline void SimpleMessage::_internal_set_sender_message(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.sender_message_.Set(value, GetArena());
}
inline std::string* SimpleMessage::_internal_mutable_sender_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.sender_message_.Mutable( GetArena());
}
inline std::string* SimpleMessage::release_sender_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:OnboardingLab3.SimpleMessage.sender_message)
  if ((_impl_._has_bits_[0] & 0x00000002u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* released = _impl_.sender_message_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.sender_message_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void SimpleMessage::set_allocated_sender_message(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.sender_message_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.sender_message_.IsDefault()) {
          _impl_.sender_message_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:OnboardingLab3.SimpleMessage.sender_message)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace OnboardingLab3


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_protobuf_2eproto_2epb_2eh
