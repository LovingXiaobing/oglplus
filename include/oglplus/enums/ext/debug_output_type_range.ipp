/*
 *  .file oglplus/enums/ext/debug_output_type_range.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/ext/debug_output_type.txt' instead.
 *
 *  Copyright 2010-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

OGLPLUS_LIB_FUNC aux::CastIterRange<
	const GLenum*,
	DebugOutputType
> EnumValueRange(DebugOutputType*)
OGLPLUS_NOEXCEPT(true)
#if OGLPLUS_LINK_LIBRARY && !defined(OGLPLUS_IMPLEMENTING_LIBRARY)
;
#else
{
static const GLenum _values[] = {
#if defined GL_DEBUG_TYPE_ERROR_ARB
GL_DEBUG_TYPE_ERROR_ARB,
#endif
#if defined GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB
GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB,
#endif
#if defined GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB
GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB,
#endif
#if defined GL_DEBUG_TYPE_PORTABILITY_ARB
GL_DEBUG_TYPE_PORTABILITY_ARB,
#endif
#if defined GL_DEBUG_TYPE_PERFORMANCE_ARB
GL_DEBUG_TYPE_PERFORMANCE_ARB,
#endif
#if defined GL_DEBUG_TYPE_OTHER_ARB
GL_DEBUG_TYPE_OTHER_ARB,
#endif
#if defined GL_DONT_CARE
GL_DONT_CARE,
#endif
0
};
return aux::CastIterRange<
	const GLenum*,
	DebugOutputType
>(_values, _values+sizeof(_values)/sizeof(_values[0])-1);
}
#endif

