//
//  gl_utils.h
//  PBF
//
//  Created by Ye Kuang on 3/27/17.
//  Copyright © 2017 Ye Kuang. All rights reserved.
//

#ifndef gl_utils_h
#define gl_utils_h

#include <GL/glew.h>

namespace pbf
{
    void CHECK_SHADER_COMPILE_STATUS(GLint shader);
    void CHECK_PROGRAM_LINK_STATUS(GLint program);
} // namespace pbf

#endif /* gl_utils_h */
