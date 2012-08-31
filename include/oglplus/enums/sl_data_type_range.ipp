/*
 *  .file oglplus/enums/sl_data_type_range.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/sl_data_type.txt' instead.
 *
 *  Copyright 2010-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

OGLPLUS_LIB_FUNC aux::CastIterRange<
	const GLenum*,
	SLDataType
> EnumValueRange(SLDataType*)
OGLPLUS_NOEXCEPT(true)
#if OGLPLUS_LINK_LIBRARY && !defined(OGLPLUS_IMPLEMENTING_LIBRARY)
;
#else
{
static const GLenum _values[] = {
#if defined GL_FLOAT
GL_FLOAT,
#endif
#if defined GL_FLOAT_VEC2
GL_FLOAT_VEC2,
#endif
#if defined GL_FLOAT_VEC3
GL_FLOAT_VEC3,
#endif
#if defined GL_FLOAT_VEC4
GL_FLOAT_VEC4,
#endif
#if defined GL_DOUBLE
GL_DOUBLE,
#endif
#if defined GL_DOUBLE_VEC2
GL_DOUBLE_VEC2,
#endif
#if defined GL_DOUBLE_VEC3
GL_DOUBLE_VEC3,
#endif
#if defined GL_DOUBLE_VEC4
GL_DOUBLE_VEC4,
#endif
#if defined GL_INT
GL_INT,
#endif
#if defined GL_INT_VEC2
GL_INT_VEC2,
#endif
#if defined GL_INT_VEC3
GL_INT_VEC3,
#endif
#if defined GL_INT_VEC4
GL_INT_VEC4,
#endif
#if defined GL_UNSIGNED_INT
GL_UNSIGNED_INT,
#endif
#if defined GL_UNSIGNED_INT_VEC2
GL_UNSIGNED_INT_VEC2,
#endif
#if defined GL_UNSIGNED_INT_VEC3
GL_UNSIGNED_INT_VEC3,
#endif
#if defined GL_UNSIGNED_INT_VEC4
GL_UNSIGNED_INT_VEC4,
#endif
#if defined GL_BOOL
GL_BOOL,
#endif
#if defined GL_BOOL_VEC2
GL_BOOL_VEC2,
#endif
#if defined GL_BOOL_VEC3
GL_BOOL_VEC3,
#endif
#if defined GL_BOOL_VEC4
GL_BOOL_VEC4,
#endif
#if defined GL_FLOAT_MAT2
GL_FLOAT_MAT2,
#endif
#if defined GL_FLOAT_MAT3
GL_FLOAT_MAT3,
#endif
#if defined GL_FLOAT_MAT4
GL_FLOAT_MAT4,
#endif
#if defined GL_FLOAT_MAT2x3
GL_FLOAT_MAT2x3,
#endif
#if defined GL_FLOAT_MAT2x4
GL_FLOAT_MAT2x4,
#endif
#if defined GL_FLOAT_MAT3x2
GL_FLOAT_MAT3x2,
#endif
#if defined GL_FLOAT_MAT3x4
GL_FLOAT_MAT3x4,
#endif
#if defined GL_FLOAT_MAT4x2
GL_FLOAT_MAT4x2,
#endif
#if defined GL_FLOAT_MAT4x3
GL_FLOAT_MAT4x3,
#endif
#if defined GL_DOUBLE_MAT2
GL_DOUBLE_MAT2,
#endif
#if defined GL_DOUBLE_MAT3
GL_DOUBLE_MAT3,
#endif
#if defined GL_DOUBLE_MAT4
GL_DOUBLE_MAT4,
#endif
#if defined GL_DOUBLE_MAT2x3
GL_DOUBLE_MAT2x3,
#endif
#if defined GL_DOUBLE_MAT2x4
GL_DOUBLE_MAT2x4,
#endif
#if defined GL_DOUBLE_MAT3x2
GL_DOUBLE_MAT3x2,
#endif
#if defined GL_DOUBLE_MAT3x4
GL_DOUBLE_MAT3x4,
#endif
#if defined GL_DOUBLE_MAT4x2
GL_DOUBLE_MAT4x2,
#endif
#if defined GL_DOUBLE_MAT4x3
GL_DOUBLE_MAT4x3,
#endif
#if defined GL_SAMPLER_1D
GL_SAMPLER_1D,
#endif
#if defined GL_SAMPLER_2D
GL_SAMPLER_2D,
#endif
#if defined GL_SAMPLER_3D
GL_SAMPLER_3D,
#endif
#if defined GL_SAMPLER_CUBE
GL_SAMPLER_CUBE,
#endif
#if defined GL_SAMPLER_1D_SHADOW
GL_SAMPLER_1D_SHADOW,
#endif
#if defined GL_SAMPLER_2D_SHADOW
GL_SAMPLER_2D_SHADOW,
#endif
#if defined GL_SAMPLER_1D_ARRAY
GL_SAMPLER_1D_ARRAY,
#endif
#if defined GL_SAMPLER_2D_ARRAY
GL_SAMPLER_2D_ARRAY,
#endif
#if defined GL_SAMPLER_CUBE_MAP_ARRAY
GL_SAMPLER_CUBE_MAP_ARRAY,
#endif
#if defined GL_SAMPLER_1D_ARRAY_SHADOW
GL_SAMPLER_1D_ARRAY_SHADOW,
#endif
#if defined GL_SAMPLER_2D_ARRAY_SHADOW
GL_SAMPLER_2D_ARRAY_SHADOW,
#endif
#if defined GL_SAMPLER_2D_MULTISAMPLE
GL_SAMPLER_2D_MULTISAMPLE,
#endif
#if defined GL_SAMPLER_2D_MULTISAMPLE_ARRAY
GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
#endif
#if defined GL_SAMPLER_CUBE_SHADOW
GL_SAMPLER_CUBE_SHADOW,
#endif
#if defined GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
#endif
#if defined GL_SAMPLER_BUFFER
GL_SAMPLER_BUFFER,
#endif
#if defined GL_SAMPLER_2D_RECT
GL_SAMPLER_2D_RECT,
#endif
#if defined GL_SAMPLER_2D_RECT_SHADOW
GL_SAMPLER_2D_RECT_SHADOW,
#endif
#if defined GL_INT_SAMPLER_1D
GL_INT_SAMPLER_1D,
#endif
#if defined GL_INT_SAMPLER_2D
GL_INT_SAMPLER_2D,
#endif
#if defined GL_INT_SAMPLER_3D
GL_INT_SAMPLER_3D,
#endif
#if defined GL_INT_SAMPLER_CUBE
GL_INT_SAMPLER_CUBE,
#endif
#if defined GL_INT_SAMPLER_1D_ARRAY
GL_INT_SAMPLER_1D_ARRAY,
#endif
#if defined GL_INT_SAMPLER_2D_ARRAY
GL_INT_SAMPLER_2D_ARRAY,
#endif
#if defined GL_INT_SAMPLER_CUBE_MAP_ARRAY
GL_INT_SAMPLER_CUBE_MAP_ARRAY,
#endif
#if defined GL_INT_SAMPLER_2D_MULTISAMPLE
GL_INT_SAMPLER_2D_MULTISAMPLE,
#endif
#if defined GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
#endif
#if defined GL_INT_SAMPLER_BUFFER
GL_INT_SAMPLER_BUFFER,
#endif
#if defined GL_INT_SAMPLER_2D_RECT
GL_INT_SAMPLER_2D_RECT,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_1D
GL_UNSIGNED_INT_SAMPLER_1D,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_2D
GL_UNSIGNED_INT_SAMPLER_2D,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_3D
GL_UNSIGNED_INT_SAMPLER_3D,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_CUBE
GL_UNSIGNED_INT_SAMPLER_CUBE,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_BUFFER
GL_UNSIGNED_INT_SAMPLER_BUFFER,
#endif
#if defined GL_UNSIGNED_INT_SAMPLER_2D_RECT
GL_UNSIGNED_INT_SAMPLER_2D_RECT,
#endif
#if defined GL_NONE
GL_NONE,
#endif
0
};
return aux::CastIterRange<
	const GLenum*,
	SLDataType
>(_values, _values+sizeof(_values)/sizeof(_values[0])-1);
}
#endif

