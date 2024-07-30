//
// Created by hy-20 on 2024/7/12.
//

#ifndef SLOWJSON_ASSERT_WITH_MESSAGE_HPP
#define SLOWJSON_ASSERT_WITH_MESSAGE_HPP

#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>

template<typename T>
concept is_string=std::is_same_v<std::remove_reference_t<std::remove_const_t<T>>, std::string>;
#ifdef NDEBUG
#define assert_with_message(...)
#else
#define assert_with_message(expr, message, ...) {                                                                                                                      \
       if(!(expr)){                                                                                                                                                  \
           fprintf(stderr,"程序断言失败,程序退出\n断言表达式:%s=%s\n文件:%s\n行数:%d\n函数名称:%s\n断言错误消息:",#expr,expr?"true":"false",__FILE__,__LINE__,__PRETTY_FUNCTION__);\
           fprintf(stderr,message"\n",##__VA_ARGS__);                                                                                                                    \
           std::terminate();                                                                                                                                                  \
       }                                                                                                                                                             \
}
#endif
#endif //SLOWJSON_ASSERT_WITH_MESSAGE_HPP