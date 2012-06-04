//===--- TypeChecker.cpp - Type Checking ----------------------------------===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
//
// This file implements semantic analysis for expressions, and other pieces
// that require final type checking.  If this passes a translation unit with no
// errors, then it is good to go.
//
//===----------------------------------------------------------------------===//

#include "TypeChecker.h"
#include "swift/AST/NameLookup.h"
using namespace swift;

ProtocolDecl *TypeChecker::getEnumerableProtocol() {
  if (!EnumerableProto) {
    UnqualifiedLookup Globals(Context.getIdentifier("Enumerable"), &TU);
    EnumerableProto
      = dyn_cast_or_null<ProtocolDecl>(Globals.getSingleTypeResult());
  }
  
  return EnumerableProto;
}

ProtocolDecl *TypeChecker::getRangeProtocol() {
  if (!RangeProto) {
    UnqualifiedLookup Globals(Context.getIdentifier("Range"), &TU);
    RangeProto = dyn_cast_or_null<ProtocolDecl>(Globals.getSingleTypeResult());
  }
  
  return RangeProto;
}
