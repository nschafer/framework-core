/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file
 * distributed with this source distribution.
 *
 * This file is part of REDHAWK core.
 *
 * REDHAWK core is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * REDHAWK core is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */
// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#include "spd-pimpl.h"
#include "ossie/debug.h"

using namespace spd;

CREATE_LOGGER(spd_parser);
// softPkg_pimpl
//

void softPkg_pimpl::
pre ()
{
    LOG_TRACE(spd_parser, "softpkg pre")
    _spd.reset(new ossie::SPD());
}

void softPkg_pimpl::
title (const ::std::string& title)
{
    _spd->title = title;
}

void softPkg_pimpl::
author (const ossie::SPD::Author& author)
{
    _spd->authors.push_back(author);
}

void softPkg_pimpl::
description (const ::std::string& description)
{
    _spd->description = description;
}

void softPkg_pimpl::
propertyfile (const ::std::string& propertyfile)
{
    LOG_TRACE(spd_parser, "softpkg propertyfile " << propertyfile)
    _spd->properties = propertyfile; 
}

void softPkg_pimpl::
descriptor (const ::std::string& descriptor)
{
    LOG_TRACE(spd_parser, "softpkg descriptor " << descriptor)
    _spd->descriptor = descriptor;
}

void softPkg_pimpl::
implementation (const ossie::SPD::Implementation& implementation)
{
    LOG_TRACE(spd_parser, "softpkg impl " << implementation.implementationID << " entry point " << implementation.code.entrypoint)
    _spd->implementations.push_back(implementation);
}

void softPkg_pimpl::
usesdevice (const ossie::SPD::UsesDevice& usesdev)
{
    LOG_TRACE(spd_parser, "softpkg usesdev " << usesdev)
    _spd->usesDevice.push_back(usesdev);
}

void softPkg_pimpl::
id (const ::std::string& id)
{
    _spd->id = id;
}

void softPkg_pimpl::
name (const ::std::string& name)
{
    _spd->name = name;
}

void softPkg_pimpl::
type (const ::std::string& type)
{
    _spd->type = type;
}

void softPkg_pimpl::
version (const ::std::string& version)
{
    _spd->version = version;
}

std::auto_ptr<ossie::SPD> softPkg_pimpl::
post_softPkg ()
{
    LOG_TRACE(spd_parser, "softpkg post")
    return _spd;
}

// localFile_pimpl
//

void localFile_pimpl::
pre ()
{
    localfile = "";
}

void localFile_pimpl::
name (const ::std::string& name)
{
    localfile = name;
}

::std::string localFile_pimpl::
post_localFile ()
{
    return localfile;
}

// propertyFile_pimpl
//

void propertyFile_pimpl::
pre ()
{
    propertyfile = "";
}

void propertyFile_pimpl::
localfile (const ::std::string& localfile)
{
    propertyfile = localfile;
}

void propertyFile_pimpl::
type (const ::std::string& type)
{
  // TODO
  //
}

std::string propertyFile_pimpl::
post_propertyFile ()
{
    return propertyfile;
}

// author_pimpl
//

void author_pimpl::
pre ()
{
    author.reset(new ossie::SPD::Author());
}

void author_pimpl::
name (const ::std::string& name)
{
    author->name.push_back(name);
}

void author_pimpl::
company (const ::std::string& company)
{
    author->company = company;
}

void author_pimpl::
webpage (const ::std::string& webpage)
{
    author->webpage = webpage;
}

ossie::SPD::Author author_pimpl::
post_author ()
{
  return *author;
}

// descriptor_pimpl
//

void descriptor_pimpl::
pre ()
{
    _localfile = "";
}

void descriptor_pimpl::
localfile (const ::std::string& localfile)
{
    _localfile = localfile;
}

void descriptor_pimpl::
name (const ::std::string& name)
{
  // TODO
  //
}

::std::string descriptor_pimpl::
post_descriptor ()
{
    return _localfile;
}

// implementation_pimpl
//

void implementation_pimpl::
pre ()
{
    LOG_TRACE(spd_parser, "implementation pre")
    implementation.reset(new ossie::SPD::Implementation());
}

void implementation_pimpl::
description (const ::std::string& description)
{
    LOG_TRACE(spd_parser, "implementation description " << description)
    // Ignored
}

void implementation_pimpl::
propertyfile (const ::std::string& propertyfile)
{
    LOG_TRACE(spd_parser, "implementation property file " << propertyfile)
    implementation->prfFile = propertyfile;
}

void implementation_pimpl::
code (const ossie::SPD::Code& code)
{
    LOG_TRACE(spd_parser, "implementation code " << code)
    implementation->code = code;
}

void implementation_pimpl::
compiler (const ossie::SPD::NameVersionPair& compiler)
{
    LOG_TRACE(spd_parser, "implementation compiler " << compiler.first << " " << compiler.second)
    implementation->compiler = compiler;
}

void implementation_pimpl::
programminglanguage ()
{
}

void implementation_pimpl::
humanlanguage ()
{
}

void implementation_pimpl::
runtime (const ossie::SPD::NameVersionPair& runtime)
{
    LOG_TRACE(spd_parser, "implementation runtime " << runtime.first << " " << runtime.second)
    implementation->runtime = runtime;
}

void implementation_pimpl::
os (const ossie::SPD::NameVersionPair& os)
{
    implementation->osDeps.push_back(os);
}

void implementation_pimpl::
processor (const ::std::string& processor)
{
    LOG_TRACE(spd_parser, "implementation processor " << processor)
    implementation->processorDeps.push_back(processor);
}

void implementation_pimpl::
dependency (ossie::SPD::DependencyRef* dep)
{
    assert(dep != 0);
    LOG_TRACE(spd_parser, "add implementation dependencies " << *dep)
    if (dynamic_cast<const ossie::SPD::PropertyRef*>(dep) != NULL) {
        implementation->dependencies.push_back(*dynamic_cast<const ossie::SPD::PropertyRef*>(dep));
    } else if (dynamic_cast<const ossie::SPD::SoftPkgRef*>(dep) != NULL) {
        implementation->softPkgDependencies.push_back(*dynamic_cast<const ossie::SPD::SoftPkgRef*>(dep));
    }
}

void implementation_pimpl::
usesdevice (const ossie::SPD::UsesDevice& usesdev)
{
    LOG_TRACE(spd_parser, "implementation usesdev " << usesdev)
    implementation->usesDevice.push_back(usesdev);
}

void implementation_pimpl::
id (const ::std::string& id)
{
    implementation->implementationID = id;
}

void implementation_pimpl::
aepcompliance ()
{
}

ossie::SPD::Implementation implementation_pimpl::
post_implementation ()
{
  LOG_TRACE(spd_parser, "implementation post")
  return *implementation;
}

// code_pimpl
//

void code_pimpl::
pre ()
{
    LOG_TRACE(spd_parser, "code pre")
    code.reset(new ossie::SPD::Code());
}

void code_pimpl::
localfile (const ::std::string& localfile)
{
    LOG_TRACE(spd_parser, "code localfile " << localfile)
    code->localfile = localfile;
}

void code_pimpl::
entrypoint (const ::std::string& entrypoint)
{
    LOG_TRACE(spd_parser, "code entrypoint " << entrypoint)
    code->entrypoint = entrypoint;
}

void code_pimpl::
stacksize (unsigned long long stacksize)
{
    LOG_TRACE(spd_parser, "code stacksize " << stacksize)
    code->stacksize = stacksize;
}

void code_pimpl::
priority (unsigned long long priority)
{
    LOG_TRACE(spd_parser, "code priority " << priority)
    code->priority = priority;
}

void code_pimpl::
type (const ::std::string& type1)
{
    LOG_TRACE(spd_parser, "code type " << type1)
    code->type = type1;
}

ossie::SPD::Code code_pimpl::
post_code ()
{
  LOG_TRACE(spd_parser, "code post " << *code)
  assert(code.get() != 0);
  return *code;
}

// compiler_pimpl
//

void compiler_pimpl::
pre ()
{
    compiler = ossie::SPD::NameVersionPair();
}

void compiler_pimpl::
name (const ::std::string& name)
{
    compiler.first = name;
}

void compiler_pimpl::
version (const ::std::string& version)
{
    compiler.second = version;
}

ossie::SPD::NameVersionPair compiler_pimpl::
post_compiler ()
{
  return compiler;
}

// programmingLanguage_pimpl
//

void programmingLanguage_pimpl::
pre ()
{
}

void programmingLanguage_pimpl::
name (const ::std::string& name)
{
  // TODO
  //
}

void programmingLanguage_pimpl::
version (const ::std::string& version)
{
  // TODO
  //
}

void programmingLanguage_pimpl::
post_programmingLanguage ()
{
}

// humanLanguage_pimpl
//

void humanLanguage_pimpl::
pre ()
{
}

void humanLanguage_pimpl::
name (const ::std::string& name)
{
  // TODO
  //
}

void humanLanguage_pimpl::
post_humanLanguage ()
{
}

// os_pimpl
//

void os_pimpl::
pre ()
{
    os = ossie::SPD::NameVersionPair();
}

void os_pimpl::
name (const ::std::string& name)
{
  os.first = name;
}

void os_pimpl::
version (const ::std::string& version)
{
  os.second = version;
}

ossie::SPD::NameVersionPair os_pimpl::
post_os ()
{
  return os;
}

// processor_pimpl
//

void processor_pimpl::
pre ()
{
}

void processor_pimpl::
name (const ::std::string& name)
{
    processor = name;
}

::std::string processor_pimpl::
post_processor ()
{
  return processor;
}

// dependency_pimpl
//

void dependency_pimpl::
pre ()
{
    _ref.reset(0);
}

void dependency_pimpl::
softpkgref (const ossie::SPD::SoftPkgRef& ref)
{
    LOG_TRACE(spd_parser, "softpkg ref dep: " << ref)
    _ref.reset(new ossie::SPD::SoftPkgRef(ref));
}

void dependency_pimpl::
propertyref (const ossie::SPD::PropertyRef& ref)
{
    LOG_TRACE(spd_parser, "property ref dep: " << ref)
    _ref.reset(new ossie::SPD::PropertyRef(ref));
}

void dependency_pimpl::
simpleref (ossie::SimplePropertyRef* ref)
{
    LOG_TRACE(spd_parser, "simple property ref dep: " << ref);
    _ref.reset(new ossie::SPD::PropertyRef(ref));
}

void dependency_pimpl::
simplesequenceref (ossie::SimpleSequencePropertyRef* ref)
{
    LOG_TRACE(spd_parser, "simple sequence property ref dep: " << ref);
    _ref.reset(new ossie::SPD::PropertyRef(ref));
}

void dependency_pimpl::
structref (ossie::StructPropertyRef* ref)
{
    LOG_TRACE(spd_parser, "struct property ref dep: " << ref);
    _ref.reset(new ossie::SPD::PropertyRef(ref));
}

void dependency_pimpl::
structsequenceref (ossie::StructSequencePropertyRef* ref)
{
    LOG_TRACE(spd_parser, "struct sequence property ref dep: " << ref);
    _ref.reset(new ossie::SPD::PropertyRef(ref));
}

void dependency_pimpl::
type (const ::std::string& type)
{
  // TODO
  //
}

ossie::SPD::DependencyRef* dependency_pimpl::
post_dependency ()
{
    assert(_ref.get() != 0);
    LOG_TRACE(spd_parser, "dependency post " << *_ref);
    return _ref.get();
}

// runtime_pimpl
//

void runtime_pimpl::
pre ()
{
    runtime = ossie::SPD::NameVersionPair();
}

void runtime_pimpl::
name (const ::std::string& name)
{
    runtime.first = name;
}

void runtime_pimpl::
version (const ::std::string& version)
{
    runtime.second = version;
}

ossie::SPD::NameVersionPair runtime_pimpl::
post_runtime ()
{
  return runtime;
}

// propertyRef_pimpl
//

void propertyRef_pimpl::
pre ()
{
    _ref.reset(new ossie::SimplePropertyRef());
}

void propertyRef_pimpl::
refid (const ::std::string& refid)
{
    _ref->_id = refid;
}

void propertyRef_pimpl::
value (const ::std::string& value)
{
    _ref->_value = value;
}

ossie::SPD::PropertyRef propertyRef_pimpl::
post_propertyRef ()
{
    return ossie::SPD::PropertyRef(_ref->clone());
}

// softPkgRef_pimpl
//

void softPkgRef_pimpl::
pre ()
{
    _ref = ossie::SPD::SoftPkgRef();
}

void softPkgRef_pimpl::
localfile (const ::std::string& localfile)
{
    _ref.localfile = localfile;
}

void softPkgRef_pimpl::
implref (const ::std::string& refid)
{
    _ref.implref = refid;
}

ossie::SPD::SoftPkgRef softPkgRef_pimpl::
post_softPkgRef ()
{
    return _ref;
}

// implRef_pimpl
//

void implRef_pimpl::
pre ()
{
}

void implRef_pimpl::
refid (const ::std::string& refid)
{
    _refid = refid;
}

::std::string implRef_pimpl::
post_implRef ()
{
    return _refid;
}

// usesDevice_pimpl
//

void usesDevice_pimpl::
pre ()
{
    _uses.reset(new ossie::SPD::UsesDevice());
}

void usesDevice_pimpl::
propertyref (const ossie::SPD::PropertyRef& propertyRef)
{
    _uses->dependencies.push_back(propertyRef);
}

void usesDevice_pimpl::
simpleref (ossie::SimplePropertyRef* propertyRef)
{
    _uses->dependencies.push_back(propertyRef->clone());
}

void usesDevice_pimpl::
simplesequenceref (ossie::SimpleSequencePropertyRef* propertyRef)
{
    _uses->dependencies.push_back(propertyRef->clone());
}

void usesDevice_pimpl::
structref (ossie::StructPropertyRef* propertyRef)
{
    _uses->dependencies.push_back(propertyRef->clone());
}

void usesDevice_pimpl::
structsequenceref (ossie::StructSequencePropertyRef* propertyRef)
{
    _uses->dependencies.push_back(propertyRef->clone());
}

void usesDevice_pimpl::
id (const ::std::string& id)
{
    _uses->id = id;
}

void usesDevice_pimpl::
type (const ::std::string& type)
{
    _uses->type = type;
}

ossie::SPD::UsesDevice usesDevice_pimpl::
post_usesDevice ()
{
    assert(_uses.get() != 0);
    LOG_TRACE(spd_parser, "post usesdev " << *_uses)
    return *_uses;
}

// scaComplianceType_pimpl
//

void scaComplianceType_pimpl::
pre ()
{
}

::std::string scaComplianceType_pimpl::
post_scaComplianceType ()
{
  const ::std::string& v (post_nmtoken ());
  // TODO enforce value restrictions
  return v;
}

// aepcompliance_pimpl
//

void aepcompliance_pimpl::
pre ()
{
}

void aepcompliance_pimpl::
post_aepcompliance ()
{
  const ::std::string& v (post_nmtoken ());
  (void)v;

  // TODO
  //
}

// codeFileType_pimpl
//

void codeFileType_pimpl::
pre ()
{
}

::std::string codeFileType_pimpl::
post_codeFileType ()
{
  const ::std::string& v (post_nmtoken ());
  if ((v != "Executable") 
      || (v != "SharedLibrary") 
      || (v != "KernelModule")
      || (v != "Driver")) {
      // TODO throw invalid_value<codeFileType_pimpl>(this, v
  }
  return v;
}

// simpleref_pimpl
//

void simpleref_pimpl::
pre ()
{
    simple = new ossie::SimplePropertyRef();
}

void simpleref_pimpl::
refid (const ::std::string& refid)
{
    assert(simple != 0);
    simple->_id = refid;
}

void simpleref_pimpl::
value (const ::std::string& value)
{
    assert(simple != 0);
    simple->_value = value;
}

ossie::SimplePropertyRef* simpleref_pimpl::
post_simpleref ()
{
    assert(simple != 0);
    return simple;
}

// simplesequenceref_pimpl
//

void simplesequenceref_pimpl::
pre ()
{
    simpleseq = new ossie::SimpleSequencePropertyRef();
}

void simplesequenceref_pimpl::
values (const ::std::vector<std::string>& values)
{
    assert(simpleseq != 0);
    simpleseq->_values = values;
}

void simplesequenceref_pimpl::
refid (const ::std::string& refid)
{
    assert(simpleseq != 0);
    simpleseq->_id = refid;
}

ossie::SimpleSequencePropertyRef* simplesequenceref_pimpl::
post_simplesequenceref ()
{
    return simpleseq;
}

// structref_pimpl
//

void structref_pimpl::
pre ()
{
    structref = new ossie::StructPropertyRef();
}

void structref_pimpl::
simpleref (ossie::SimplePropertyRef* simpleref)
{
    assert(structref != 0);
    structref->_values[simpleref->_id] = simpleref->_value;
}

void structref_pimpl::
refid (const ::std::string& refid)
{
    assert(structref != 0);
    structref->_id = refid;
}

ossie::StructPropertyRef* structref_pimpl::
post_structref ()
{
    assert(structref != 0);
    return structref;
}

// structsequenceref_pimpl
//

void structsequenceref_pimpl::
pre ()
{
    structsequenceref = new ossie::StructSequencePropertyRef();
}

void structsequenceref_pimpl::
structvalue (const std::map<std::string, std::string>& value)
{
    assert(structsequenceref != 0);
    structsequenceref->_values.push_back(value);
}

void structsequenceref_pimpl::
refid (const ::std::string& refid)
{
    assert(structsequenceref != 0);
    structsequenceref->_id = refid;
}

ossie::StructSequencePropertyRef* structsequenceref_pimpl::
post_structsequenceref ()
{
    assert(structsequenceref != 0);
    return structsequenceref;
}

// structvalue_pimpl
//

void structvalue_pimpl::
pre ()
{
    values.clear();
}

void structvalue_pimpl::
simpleref (ossie::SimplePropertyRef* simpleref)
{
    values[simpleref->_id] = simpleref->_value;
}

std::map<std::string, std::string> structvalue_pimpl::
post_structvalue ()
{
    return values;
}

// values_pimpl
//

void values_pimpl::
pre ()
{
    values.clear();
}

void values_pimpl::
value (const ::std::string& value)
{
    values.push_back(value);
}

::std::vector<std::string> values_pimpl::
post_values ()
{
    return values;
}
