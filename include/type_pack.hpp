/* MIT License
 *
 * Copyright (c) 2023 Gleb Zlatanov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef TYPE_PACK_HPP
#define TYPE_PACK_HPP

#include <cstddef>
#include <type_traits>

namespace tp {

  template <typename T>
  struct just_type {
      using type = T;
  };

  template <typename... Types>
  class type_pack {
    private:
      static constexpr std::size_t sz = (sizeof...(Types));
    public:
      static constexpr std::size_t size() noexcept { return sz; }

      static constexpr bool empty() noexcept { return sz == 0; }
  };

  using empty_pack = type_pack<>;

  template <typename T>
  struct head {};

  template <typename T, typename... Ts>
  struct head<type_pack<T, Ts...>> {
      using type = T;
  };

  template <typename T>
  struct tail {};

  template <typename T, typename... Ts>
  struct tail<type_pack<T, Ts...>> {
      using type = type_pack<Ts...>;
  };

  template <class...>
  struct concatenate {};

  template <typename... Ts, typename... Us>
  struct concatenate<type_pack<Ts...>, type_pack<Us...>> {
      using type = type_pack<Ts..., Us...>;
  };

  template <typename T, typename... Ts>
  struct concatenate<type_pack<Ts...>, just_type<T>> {
      using type = type_pack<Ts..., T>;
  };

  template <typename T, typename... Ts>
  struct concatenate<just_type<T>, type_pack<Ts...>> {
      using type = type_pack<T, Ts...>;
  };

  template <typename A, typename B>
  struct concatenate<just_type<A>, just_type<B>> {
      using type = type_pack<A, B>;
  };

  template <class T, class... Ts>
  struct concatenate<T, Ts...>
      : concatenate<T, typename concatenate<Ts...>::type> {};

  template <class... Ts>
  using concatenate_t = typename concatenate<Ts...>::type;

  template <class T, class U>
  constexpr auto operator+(T, U) -> concatenate_t<T, U> {
    return {};
  }

  template <class T, class U>
  struct is_equal : std::false_type {};

  template <typename... Ts>
  struct is_equal<type_pack<Ts...>, type_pack<Ts...>> : std::true_type {};

  template <typename T>
  struct is_equal<just_type<T>, just_type<T>> : std::true_type {};

  template <typename T>
  struct is_equal<just_type<T>, type_pack<T>> : std::true_type {};

  template <class T, class U>
  struct is_not_equal : std::integral_constant<bool, !is_equal<T, U>::value> {};

  template <class T, class U>
  constexpr bool operator==(T, U) {
    return is_equal<T, U>::value;
  }

  template <class T, class U>
  constexpr bool operator!=(T, U) {
    return is_not_equal<T, U>::value;
  }

  template <typename T, class TP>
  struct push_front {};

  template <typename T, typename... Ts>
  struct push_front<T, type_pack<Ts...>> {
      using type = type_pack<T, Ts...>;
  };

  template <typename T, class TP>
  using push_front_t = typename push_front<T, TP>::type;

  template <class TP>
  struct pop_front {};

  template <typename T, typename... Ts>
  struct pop_front<type_pack<T, Ts...>> {
      using type = type_pack<Ts...>;
  };

  template <class TP>
  using pop_front_t = typename pop_front<TP>::type;

  template <typename T, class TP>
  struct push_back {};

  template <typename T, typename... Ts>
  struct push_back<T, type_pack<Ts...>> {
      using type = type_pack<Ts..., T>;
  };

  template <typename T, class TP>
  using push_back_t = typename push_back<T, TP>::type;

  template <class TP>
  struct pop_back;

  template <typename T, typename U, typename... Ts>
  struct pop_back<type_pack<T, U, Ts...>> {
      using type = concatenate_t<type_pack<T, U>,
                                 typename pop_back<type_pack<Ts...>>::type>;
  };

  template <typename T>
  struct pop_back<type_pack<T>> {
      using type = empty_pack;
  };

  template <class TP>
  using pop_back_t = typename pop_back<TP>::type;

  template <typename, class>
  struct contains {};

  template <typename T>
  struct contains<T, type_pack<>> : std::false_type {};

  template <typename T, typename U, typename... Ts>
  struct contains<T, type_pack<U, Ts...>>
      : std::integral_constant<bool,
                               std::is_same<T, U>::value
                                   ? true
                                   : contains<T, type_pack<Ts...>>::value> {};

  namespace __details {

    template <typename T, typename TP, size_t Idx>
    struct find_helper {};

    template <typename T, size_t Idx>
    struct find_helper<T, empty_pack, Idx> {
        static constexpr size_t value = Idx;
    };

    template <typename T, typename... Ts, size_t Idx>
    struct find_helper<T, type_pack<T, Ts...>, Idx> {
        static constexpr std::size_t value = Idx;
    };

    template <typename T, typename U, typename... Ts, size_t Idx>
    struct find_helper<T, type_pack<U, Ts...>, Idx> {
        static constexpr size_t value =
            find_helper<T, type_pack<Ts...>, Idx + 1>::value;
    };

  } // namespace __details

  template <typename T, typename TP>
  struct find
      : std::integral_constant<std::size_t,
                               __details::find_helper<T, TP, 0>::value> {};

  template <template <class...> class F, class... Ts>
  struct part_caller {
      template <class... Us>
      using type = typename F<Ts..., Us...>::type;
  };

  namespace __details {

    template <bool Cond>
    using enable_if_t = typename std::enable_if<Cond, void>::type;

    template <template <typename...> class F, typename TP, size_t Idx,
              typename AlwaysVoid>
    struct find_if_helper {
        static constexpr size_t value = Idx;
    };

    template <template <typename...> class F, typename T, typename... Ts,
              size_t Idx>
    struct find_if_helper<F, type_pack<T, Ts...>, Idx,
                          enable_if_t<F<T>::value>> {
        static constexpr size_t value = Idx;
    };

    template <template <typename...> class F, typename T, typename... Ts,
              size_t Idx>
    struct find_if_helper<F, type_pack<T, Ts...>, Idx,
                          enable_if_t<F<T>::value == false>> {
        static constexpr size_t value =
            find_if_helper<F, type_pack<Ts...>, Idx + 1, void>::value;
    };

  } // namespace __details

  template <template <typename...> class F, class TP>
  struct find_if
      : std::integral_constant<
            std::size_t, __details::find_if_helper<F, TP, 0, void>::value> {};

  template <template <typename...> class F, class TP>
  struct all_of {};

  template <template <typename...> class F>
  struct all_of<F, empty_pack> : std::true_type {};

  template <template <typename...> class F, typename T, typename... Ts>
  struct all_of<F, type_pack<T, Ts...>>
      : std::integral_constant<bool, F<T>::value &&
                                         all_of<F, type_pack<Ts...>>::value> {};

  template <template <typename...> class F, class TP>
  struct any_of {};

  template <template <typename...> class F>
  struct any_of<F, empty_pack> : std::false_type {};

  template <template <typename...> class F, typename T, typename... Ts>
  struct any_of<F, type_pack<T, Ts...>>
      : std::integral_constant<bool, F<T>::value ||
                                         any_of<F, type_pack<Ts...>>::value> {};

  template <template <typename> class F, class TP>
  struct none_of : std::integral_constant<bool, !any_of<F, TP>::value> {};

  template <template <typename...> class F, class TP>
  struct transform {};

  template <template <typename...> class F, typename... Ts>
  struct transform<F, type_pack<Ts...>> {
      using type = type_pack<typename F<Ts>::type...>;
  };

  template <template <typename...> class F, class TP>
  using transform_t = typename transform<F, TP>::type;

  namespace __details {

    template <typename>
    struct Error_Type_Pack_Out_Of_Range;

    template <std::size_t Idx, std::size_t Count, class TP, typename>
    struct at_helper {
        using type = typename Error_Type_Pack_Out_Of_Range<TP>::type;
    };

    template <std::size_t Idx, std::size_t Count, typename T, typename... Ts>
    struct at_helper<Idx, Count, type_pack<T, Ts...>,
                     typename std::enable_if<Idx == Count, void>::type> {
        using type = T;
    };

    template <std::size_t Idx, std::size_t Count, typename T, typename... Ts>
    struct at_helper<Idx, Count, type_pack<T, Ts...>,
                     typename std::enable_if<Idx != Count, void>::type> {
        using type =
            typename at_helper<Idx, Count + 1, type_pack<Ts...>, void>::type;
    };

  } // namespace __details

  template <std::size_t Idx, class TP>
  struct at : __details::at_helper<Idx, 0, TP, void> {};

  template <std::size_t Idx, class TP>
  using at_t = typename at<Idx, TP>::type;

  template <std::size_t N, typename T>
  struct generate {
      using type =
          concatenate_t<just_type<T>, typename generate<N - 1, T>::type>;
  };

  template <typename T>
  struct generate<0, T> {
      using type = empty_pack;
  };

  template <std::size_t N, typename T>
  using generate_t = typename generate<N, T>::type;

  namespace __details {

    template <typename T, std::size_t Count, class TP>
    struct count_impl {
        static constexpr std::size_t value = Count;
    };

    template <typename T, std::size_t Count, typename... Ts>
    struct count_impl<T, Count, type_pack<T, Ts...>> {
        static constexpr std::size_t value =
            count_impl<T, Count + 1, type_pack<Ts...>>::value;
    };

    template <typename T, typename U, std::size_t Count, typename... Ts>
    struct count_impl<T, Count, type_pack<U, Ts...>> {
        static constexpr std::size_t value =
            count_impl<T, Count, type_pack<Ts...>>::value;
    };

  } // namespace __details

  template <typename T, class TP>
  struct count
      : std::integral_constant<std::size_t,
                               __details::count_impl<T, 0, TP>::value> {};

  namespace __details {

    template <template <typename...> class F, std::size_t Count, class TP>
    struct count_if_impl {
        static constexpr std::size_t value = Count;
    };

    template <template <typename...> class F, std::size_t Count, typename T,
              typename... Ts>
    struct count_if_impl<F, Count, type_pack<T, Ts...>> {
      private:
        static constexpr std::size_t counter = F<T>::value ? Count + 1 : Count;
      public:
        static constexpr std::size_t value =
            count_if_impl<F, counter, type_pack<Ts...>>::value;
    };

  } // namespace __details

  template <template <typename...> class F, class TP>
  struct count_if
      : std::integral_constant<std::size_t,
                               __details::count_if_impl<F, 0, TP>::value> {};

  template <typename T, class TP>
  struct remove {
      using type = TP;
  };

  template <typename T, typename... Ts>
  struct remove<T, type_pack<T, Ts...>> {
      using type = type_pack<Ts...>;
  };

  template <typename T, typename U, typename... Ts>
  struct remove<T, type_pack<U, Ts...>> {
      using type = concatenate_t<just_type<U>,
                                 typename remove<T, type_pack<Ts...>>::type>;
  };

  template <typename T, class TP>
  using remove_t = typename remove<T, TP>::type;

  template <template <typename...> class F, class TP>
  struct remove_if {
      using type = TP;
  };

  template <template <typename...> class F, typename T, typename... Ts>
  struct remove_if<F, type_pack<T, Ts...>> {
    private:
      using head_type = typename std::conditional<F<T>::value, empty_pack,
                                                  type_pack<T>>::type;
    public:
      using type = concatenate_t<head_type,
                                 typename remove_if<F, type_pack<Ts...>>::type>;
  };

  template <template <typename...> class F, class TP>
  using remove_if_t = typename remove_if<F, TP>::type;

  template <typename T, class TP>
  struct remove_all {
      using type = TP;
  };

  template <typename T, typename... Ts>
  struct remove_all<T, type_pack<T, Ts...>> {
      using type = typename remove_all<T, type_pack<Ts...>>::type;
  };

  template <typename T, typename U, typename... Ts>
  struct remove_all<T, type_pack<U, Ts...>> {
      using type =
          concatenate_t<just_type<U>,
                        typename remove_all<T, type_pack<Ts...>>::type>;
  };

  template <typename T, class TP>
  using remove_all_t = typename remove_all<T, TP>::type;

  template <class TP>
  struct unique {
      using type = TP;
  };

  template <typename T, typename... Ts>
  struct unique<type_pack<T, Ts...>> {
    private:
      using tail = remove_all_t<T, type_pack<Ts...>>;
    public:
      using type = concatenate_t<just_type<T>, typename unique<tail>::type>;
  };

  template <class TP>
  using unique_t = typename unique<TP>::type;

  template <typename Rep, typename To, class TP>
  struct replace {
    private:
      template <typename T>
      struct rep_one_element {
          using type = typename std::conditional<std::is_same<T, Rep>::value,
                                                 To, T>::type;
      };
    public:
      using type = transform_t<rep_one_element, TP>;
  };

  template <typename Rep, typename To, class TP>
  using replace_t = typename replace<Rep, To, TP>::type;

} // namespace tp

#endif
