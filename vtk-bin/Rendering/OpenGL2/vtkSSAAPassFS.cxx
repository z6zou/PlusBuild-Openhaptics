#include "vtkSSAAPassFS.h"

const char *vtkSSAAPassFS =
"//VTK::System::Dec\n"
"\n"
"// ============================================================================\n"
"//\n"
"//  Program:   Visualization Toolkit\n"
"//  Module:    vtkSSAAPassFS.glsl\n"
"//\n"
"//  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen\n"
"//  All rights reserved.\n"
"//  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.\n"
"//\n"
"//     This software is distributed WITHOUT ANY WARRANTY; without even\n"
"//     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR\n"
"//     PURPOSE.  See the above copyright notice for more information.\n"
"//\n"
"// ============================================================================\n"
"\n"
"// thanks to Brad Larson for posting sample code that helped get this started\n"
"\n"
"uniform sampler2D source;\n"
"\n"
"// the output of this shader\n"
"//VTK::Output::Dec\n"
"\n"
"uniform float texelWidthOffset;\n"
"uniform float texelHeightOffset;\n"
"\n"
"in vec2 tcoordVC;\n"
"\n"
"// Note that the texel offsets should be 3/8 of a pixel in the\n"
"// resulting image not the source image. Also note that this\n"
"// filter is meant to be run one dimension at a time.\n"
"// in the equation below 1.5 corresponds to 4 texel offsets\n"
"// aka 3/8 * 4 = 1.5\n"
"\n"
"// sinc(x) * sinc(x/a) = (a * sin(pi * x) * sin(pi * x / a)) / (pi^2 * x^2)\n"
"// Assuming a Lanczos constant of 2.0, and scaling values to max out at x = +/- 1.5\n"
"\n"
"void main()\n"
"{\n"
"  vec2 firstOffset = vec2(texelWidthOffset, texelHeightOffset);\n"
"\n"
"  vec4 fragmentColor = texture2D(source, tcoordVC) * 0.38026;\n"
"\n"
"  fragmentColor += texture2D(source, tcoordVC - firstOffset) * 0.27667;\n"
"  fragmentColor += texture2D(source, tcoordVC + firstOffset) * 0.27667;\n"
"\n"
"  fragmentColor += texture2D(source, tcoordVC - 2.0*firstOffset) * 0.08074;\n"
"  fragmentColor += texture2D(source, tcoordVC + 2.0*firstOffset) * 0.08074;\n"
"\n"
"  fragmentColor += texture2D(source, tcoordVC - 3.0*firstOffset) * -0.02612;\n"
"  fragmentColor += texture2D(source, tcoordVC + 3.0*firstOffset) * -0.02612;\n"
"\n"
"  fragmentColor += texture2D(source, tcoordVC - 4.0*firstOffset) * -0.02143;\n"
"  fragmentColor += texture2D(source, tcoordVC + 4.0*firstOffset) * -0.02143;\n"
"\n"
"  gl_FragData[0] = fragmentColor;\n"
"}\n"
"";
