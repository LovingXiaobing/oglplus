//  File doc/quickbook/eglplus/quickref/enums/vg_colorspace_class.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/eglplus/vg_colorspace.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2019 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[eglplus_enums_vg_colorspace_class
#if !__OGLPLUS_NO_ENUM_VALUE_CLASSES
namespace enums {

template <typename Base, template<__VGColorspace> class Transform>
class __EnumToClass<Base, __VGColorspace, Transform> /*<
Specialization of __EnumToClass for the __VGColorspace enumeration.
>*/
 : public Base
{
public:
	EnumToClass();
	EnumToClass(Base&& base);

	Transform<VGColorspace::sRGB>
		sRGB;
	Transform<VGColorspace::Linear>
		Linear;
};

} // namespace enums
#endif
//]

