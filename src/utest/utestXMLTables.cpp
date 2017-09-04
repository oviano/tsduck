//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2017, Thierry Lelegard
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
//
//  CppUnit test suite for ts::XMLTables.
//
//----------------------------------------------------------------------------

#include "tsXMLTables.h"
#include "tsStringUtils.h"
#include "tsCerrReport.h"
#include "utestCppUnitTest.h"
TSDUCK_SOURCE;


//----------------------------------------------------------------------------
// The test fixture
//----------------------------------------------------------------------------

class XMLTablesTest: public CppUnit::TestFixture
{
public:
    void setUp();
    void tearDown();
    void testRegistrations();

    CPPUNIT_TEST_SUITE(XMLTablesTest);
    CPPUNIT_TEST(testRegistrations);
    CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION(XMLTablesTest);


//----------------------------------------------------------------------------
// Initialization.
//----------------------------------------------------------------------------

// Test suite initialization method.
void XMLTablesTest::setUp()
{
}

// Test suite cleanup method.
void XMLTablesTest::tearDown()
{
}


//----------------------------------------------------------------------------
// Unitary tests.
//----------------------------------------------------------------------------

void XMLTablesTest::testRegistrations()
{
    ts::StringList names;

    ts::XMLTables::GetRegisteredTableNames(names);
    utest::Out() << "XMLTablesTest::testRegistrations: tables: " << ts::JoinStrings(names) << std::endl;

    CPPUNIT_ASSERT(!names.empty());
    CPPUNIT_ASSERT(ts::ContainSimilarString(names, "PAT"));
    CPPUNIT_ASSERT(ts::ContainSimilarString(names, "PMT"));

    ts::XMLTables::GetRegisteredDescriptorNames(names);
    utest::Out() << "XMLTablesTest::testRegistrations: descriptors: " << ts::JoinStrings(names) << std::endl;

    CPPUNIT_ASSERT(!names.empty());
    CPPUNIT_ASSERT(ts::ContainSimilarString(names, "ca_descriptor"));
}