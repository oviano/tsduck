//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2019, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Representation of a multilingual_component_descriptor
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsAbstractMultilingualDescriptor.h"

namespace ts {
    //!
    //! Representation of a multilingual_component_descriptor.
    //! @see ETSI 300 468, 6.2.23.
    //! @ingroup descriptor
    //!
    class TSDUCKDLL MultilingualComponentDescriptor : public AbstractMultilingualDescriptor
    {
    public:
        // MultilingualComponentDescriptor fields, in addition to inherited "entries".
        uint8_t component_tag;  //!< Component tag, aka. stream identifier.

        //!
        //! Default constructor.
        //!
        MultilingualComponentDescriptor();

        //!
        //! Constructor from a binary descriptor
        //! @param [in,out] duck TSDuck execution context.
        //! @param [in] bin A binary descriptor to deserialize.
        //!
        MultilingualComponentDescriptor(DuckContext& duck, const Descriptor& bin);

        // Inherited methods
        virtual void fromXML(DuckContext&, const xml::Element*) override;
        DeclareDisplayDescriptor();

    protected:
        // Inherited methods
        virtual void buildXML(DuckContext&, xml::Element*) const override;
        virtual void serializeProlog(DuckContext& duck, const ByteBlockPtr& bbp) const override;
        virtual void deserializeProlog(DuckContext& duck, const uint8_t*& data, size_t& size) override;
    };
}