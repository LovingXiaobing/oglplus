//  File doc/quickbook/eglplus/quickref/enums/context_flag_class.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/eglplus/context_flag.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2019 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[eglplus_enums_context_flag_class
#if !__OGLPLUS_NO_ENUM_VALUE_CLASSES
namespace enums {

template <typename Base, template<__ContextFlag> class Transform>
class __EnumToClass<Base, __ContextFlag, Transform> /*<
Specialization of __EnumToClass for the __ContextFlag enumeration.
>*/
 : public Base
{
public:
	EnumToClass();
	EnumToClass(Base&& base);

	Transform<ContextFlag::OpenGLDebug>
		OpenGLDebug;
	Transform<ContextFlag::OpenGLForwardCompatible>
		OpenGLForwardCompatible;
	Transform<ContextFlag::OpenGLRobustAccess>
		OpenGLRobustAccess;
};

} // namespace enums
#endif
//]

