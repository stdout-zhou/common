// 简易版本的std::tuple
// 大致思路是可变参数模板 + 递归
// 很多地方实现的很暴力

namespace stdout_cxx_template {

template <typename... Args> struct Tuple;

template <>
struct Tuple<> {
};

template <typename T, typename... Args>
struct Tuple<T, Args...> : Tuple<Args...> {
  // 需要一个空参数的构造函数作为递归出口，否则会报错
  Tuple() = default;
  Tuple(T first_arg, Args... args) {
    this->value = first_arg;
    this->base = BaseType(args...);
  }
  T value;
  using BaseType = Tuple<Args...>;
  using ValueType = T;
  BaseType base;
};

template <int idx, typename TupleType>
struct _TupleGetHelper {
  _TupleGetHelper(TupleType tuple) {
    this->tuple = tuple;
    this->value = _TupleGetHelper<idx - 1, typename TupleType::BaseType>(tuple.base).value;
  }
  TupleType tuple;
  using ValueType = typename _TupleGetHelper<idx - 1, typename TupleType::BaseType>::ValueType;
  ValueType value;  
};

template <typename TupleType>
struct _TupleGetHelper<0, TupleType> {
  _TupleGetHelper(TupleType tuple) {
    this->tuple = tuple;
    this->value = tuple.value;
  }
  TupleType tuple;
  using ValueType = typename TupleType::ValueType;
  ValueType value;
};

// 函数没办法偏特化，但可以用类偏特化去实现函数偏特化
template <int idx, typename TupleType>
constexpr auto get(TupleType tuple) {
  return _TupleGetHelper<idx, TupleType>(tuple).value;
}

} // namespace stdout_cxx_template
