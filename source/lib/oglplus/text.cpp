/**
 *  .file lib/oglplus/text.cpp
 *  .brief Text rendering utility functions
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2019 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "prologue.ipp"
#if GL_VERSION_4_1 || GL_ARB_separate_shader_objects || \
  GL_EXT_direct_state_access

#include <oglplus/buffer.hpp>
#include <oglplus/context.hpp>
#include <oglplus/error/glfunc.hpp>
#include <oglplus/error/limit.hpp>
#include <oglplus/images/image.hpp>
#include <oglplus/object/desc.hpp>
#include <oglplus/program.hpp>
#include <oglplus/shader.hpp>
#include <oglplus/string/def.hpp>
#include <oglplus/string/empty.hpp>
#include <oglplus/string/utf8.hpp>
#include <oglplus/texture.hpp>
#include <oglplus/uniform.hpp>
#include <oglplus/vertex_attrib.hpp>

#include "implement.ipp"

#include <oglplus/text/bitmap_glyph.hpp>
#include <oglplus/text/stb_truetype.hpp>
#include <oglplus/text/unicode.hpp>
#if OGLPLUS_PANGO_CAIRO_FOUND
#include <oglplus/text/pango_cairo.hpp>
#endif

#endif

#include "epilogue.ipp"
