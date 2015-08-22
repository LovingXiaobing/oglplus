/**
 *  @file oglplus/texgen/delegate_output.hpp
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2015 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma once
#ifndef OGLPLUS_TEXGEN_DELEGATE_OUTPUT_HPP
#define OGLPLUS_TEXGEN_DELEGATE_OUTPUT_HPP

#include <oglplus/texgen/interface.hpp>
#include <memory>

namespace oglplus {
namespace texgen {

class DelegateOutputSlot
 : public OutputSlot
{
private:
	Node* _parent;
	std::unique_ptr<OutputSlot> _output;
public:
	DelegateOutputSlot(Node& ,std::unique_ptr<OutputSlot>&&);

	Node& Parent(void);

	void Assign(std::unique_ptr<OutputSlot>&& output);

	OutputSlot& Output(void);

	const char* Name(void)
	OGLPLUS_OVERRIDE;

	SlotDataType ValueType(void)
	OGLPLUS_OVERRIDE;

	std::ostream& Definitions(std::ostream&, CompileContext&)
	OGLPLUS_OVERRIDE;

	std::ostream& Expression(std::ostream&, CompileContext&)
	OGLPLUS_OVERRIDE;

	bool IsConnected(InputSlot& input)
	OGLPLUS_OVERRIDE;

	bool Connect(InputSlot& input)
	OGLPLUS_OVERRIDE;

	void Disconnect(InputSlot& input)
	OGLPLUS_OVERRIDE;

	void UpdateConnected(void)
	OGLPLUS_OVERRIDE;

	bool Render(const RenderParams&)
	OGLPLUS_OVERRIDE;
};

} // namespace texgen
} // namespace oglplus

//#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/delegate_output.ipp>
//#endif

#endif // include guard