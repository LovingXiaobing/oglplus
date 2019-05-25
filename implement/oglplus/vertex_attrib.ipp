/**
 *  @file oglplus/vertex_attrib.ipp
 *  @brief Implementation of VertexAttrib functions
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2019 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <oglplus/lib/incl_begin.ipp>
#include <oglplus/lib/incl_end.ipp>
#include <oglplus/object/desc.hpp>

namespace oglplus {

OGLPLUS_LIB_FUNC
const char* ProgVarLocOps<tag::VertexAttrib>::MsgGettingInactive() {
    return "Getting the location of inactive program vertex attribute";
}

OGLPLUS_LIB_FUNC
const char* ProgVarLocOps<tag::VertexAttrib>::MsgUsingInactive() {
    return "Using inactive program vertex attribute";
}

OGLPLUS_LIB_FUNC
bool ProgVarLocOps<tag::VertexAttrib>::QueryCommonLocation(
  const Sequence<ProgramName>& programs,
  StrCRef identifier,
  VertexAttribSlot& location) {
    if(std::size_t n = programs.size()) {
        if(!QueryActiveLocation(programs[0], identifier, location))
            return false;

        const VertexAttribSlot prev_loc(location);

        for(std::size_t i = 1; i != n; ++i) {
            if(!QueryActiveLocation(programs[i], identifier, location))
                return false;

            if(prev_loc != location)
                return false;
        }
        return true;
    }
    return false;
}

OGLPLUS_LIB_FUNC
VertexAttribSlot ProgVarLocOps<tag::VertexAttrib>::GetCommonLocation(
  const Sequence<ProgramName>& programs, StrCRef identifier) {
    VertexAttribSlot location;
    bool found = QueryCommonLocation(programs, identifier, location);
    OGLPLUS_HANDLE_ERROR_IF(
      !found,
      GL_INVALID_OPERATION,
      "Inconsistent location of a vertex "
      "attribute in multiple programs",
      ProgVarError,
      Identifier(identifier.c_str()));
    return location;
}

} // namespace oglplus
