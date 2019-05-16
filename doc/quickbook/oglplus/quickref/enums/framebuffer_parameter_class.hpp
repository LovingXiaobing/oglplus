//  File doc/quickbook/oglplus/quickref/enums/framebuffer_parameter_class.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/framebuffer_parameter.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2019 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_framebuffer_parameter_class
#if !__OGLPLUS_NO_ENUM_VALUE_CLASSES
namespace enums {

template <typename Base, template<__FramebufferParameter> class Transform>
class __EnumToClass<Base, __FramebufferParameter, Transform> /*<
Specialization of __EnumToClass for the __FramebufferParameter enumeration.
>*/
 : public Base
{
public:
	EnumToClass(void);
	EnumToClass(Base&& base);

	Transform<FramebufferParameter::DefaultWidth>
		DefaultWidth;
	Transform<FramebufferParameter::DefaultHeight>
		DefaultHeight;
	Transform<FramebufferParameter::Layers>
		Layers;
	Transform<FramebufferParameter::Samples>
		Samples;
	Transform<FramebufferParameter::FixedSampleLocations>
		FixedSampleLocations;
};

} // namespace enums
#endif
//]

