/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmConfigureFileCommand_h
#define cmConfigureFileCommand_h

#include "cmStandardIncludes.h"
#include "cmCommand.h"

class cmConfigureFileCommand : public cmCommand
{
public:
  virtual cmCommand* Clone() 
    {
      return new cmConfigureFileCommand;
    }

  /**
   * This is called when the command is first encountered in
   * the input file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "CONFIGURE_FILE";}

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() 
    {
    return "Create a file from an autoconf style file.in file.";
    }
  
  /**
   * Longer documentation.
   */
  virtual const char* GetFullDocumentation()
    {
      return
        "CONFIGURE_FILE(InputFile OutputFile [COPYONLY] [ESCAPE_QUOTES] [IMMEDIATE] [@ONLY])\n"
        "The Input and Ouput files have to have full paths.\n"
        "They can also use variables like CMAKE_BINARY_DIR,CMAKE_SOURCE_DIR. "
        "This command replaces any variables in the input file with their "
        "values as determined by CMake. If a variables in not defined, it "
        "will be replaced with nothing.  If COPYONLY is passed in, then "
        "then no variable expansion will take place. If ESCAPE_QUOTES is "
        "passed in then any substitued quotes will be C style escaped. "
        "If IMMEDIATE is specified, then the file will be configured with "
        "the current values of CMake variables instead of waiting until the "
        "end of CMakeLists processing.  If @ONLY is present, only variables "
        "of the form @var@ will be replaces and ${var} will be ignored. "
        "This is useful for configuring tcl scripts that use ${var}.";
    }

  virtual void FinalPass();
private:
  void ConfigureFile();
  
  std::string m_InputFile;
  std::string m_OuputFile;
  bool m_CopyOnly;
  bool m_EscapeQuotes;
  bool m_Immediate;
  bool m_AtOnly;
};



#endif
