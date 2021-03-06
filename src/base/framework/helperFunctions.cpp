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


#include <string>
#include <iostream>
#include <fstream>

#include <uuid/uuid.h>

#include <boost/filesystem/path.hpp>

namespace fs = boost::filesystem;

#include <ossie/CorbaUtils.h>
#include <ossie/ossieSupport.h>

void ossie::createProfileFromFileName(std::string fileName, std::string& profile)
{
    profile = "<profile filename=\"" + fileName + "\" />";

    return;
}

bool ossie::isValidFileName(const char* fileName)
{
    int fsOpSuccessAttempts = 0;
    bool fsOpSuccess = false;
    while (!fsOpSuccess) {
        try {
#if BOOST_FILESYSTEM_VERSION == 2
            fs::path testPath(fileName, fs::portable_posix_name);
#else            
	    fs::path testPath(fileName);
#endif
	    fsOpSuccess = true;
        } catch ( ... ) {
            fsOpSuccessAttempts++;
            if (fsOpSuccessAttempts == 10)
                { break; }
            usleep(10000);
        }
    }
    return fsOpSuccess;
}

const char* ossie::spd_rel_file(const char* spdFile, const char* name, std::string& fileName)
{
    fs::path spdPath(spdFile);

    fs::path filePath = spdPath.branch_path() / name;

    fileName = filePath.string();

    return fileName.c_str();
}

std::string ossie::generateUUID()
{
    uuid_t id;
    uuid_generate(id);

    // Per the man page, UUID strings are 36 characters plus the '\0' terminator.
    char strbuf[37];
    uuid_unparse(id, strbuf);

    return std::string("DCE:") + strbuf;
}


namespace ossie {

  namespace helpers {
  
  /**
     is_jarfile 
     
     Helper method to test if parameter is a valid jar file in lue of "file" command
     result differences from various OS distros

     @return 0   contents of jarPath is a valid jar format
     @return 1   contents of file does not match magic number format
     @return -1  file acces/open error

   */
    int is_jarfile( const std::string &jarPath ) {
      int retval=-1;
      std::ifstream r_fs(jarPath.c_str() );
      // test if file was opened...
      if ( r_fs.fail() == false )  {
        int mlen=6;
        // magic numbers for jar/zip files
        uint8_t java_m1[6] = { 0x50, 0x4b, 0x03, 0x04, 0x14, 0x00 };
        uint8_t java_m2[6] = { 0x50, 0x4b, 0x03, 0x04, 0x0a, 0x00 };
        uint8_t tbuf[mlen];
        r_fs.read( (char *)tbuf, mlen );
        retval=memcmp( tbuf, java_m1, mlen);
        /// check file contents against magic number sequence
        if ( retval != 0 ) {
          retval = memcmp( tbuf, java_m2, mlen);
          if ( retval != 0 ) retval=1;
        }
      }
      return retval;
    };

  };

};
