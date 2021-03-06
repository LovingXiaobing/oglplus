//  File doc/quickbook/oalplus/quickref/enums/string_query_class.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oalplus/string_query.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2019 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oalplus_enums_string_query_class
#if !__OGLPLUS_NO_ENUM_VALUE_CLASSES
namespace enums {

template <typename Base, template<__StringQuery> class Transform>
class __EnumToClass<Base, __StringQuery, Transform> /*<
Specialization of __EnumToClass for the __StringQuery enumeration.
>*/
 : public Base
{
public:
	EnumToClass();
	EnumToClass(Base&& base);

	Transform<StringQuery::Version>
		Version;
	Transform<StringQuery::Renderer>
		Renderer;
	Transform<StringQuery::Vendor>
		Vendor;
	Transform<StringQuery::Extensions>
		Extensions;
};

} // namespace enums
#endif
//]

