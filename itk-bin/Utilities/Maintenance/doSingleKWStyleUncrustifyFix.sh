#!/bin/bash
#==========================================================================
#
#   Copyright Insight Software Consortium
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#          http://www.apache.org/licenses/LICENSE-2.0.txt
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#==========================================================================*/

## the intent of this file is to clean the files, make them KWSTYLE compliant,
## and then make sure that subsequent runs of this script do not modify `
## The goal of this script is to develop a consistent system of auto-formating
## and format testing such that if uncrustify is run, then the code will pass
## the KWStyle format checker

## https://www.itk.org/Wiki/ITKv4_StyleChangeProposal

if [ -f stop ]; then
  echo "Quitting because stop function given"
  exit -1;
fi

mkdir -p kwstyle


UNCRUSTIFYBIN=$(git config hooks.uncrustify.path) ||
  UNCRUSTIFYBIN=$(which uncrustify) ||
  die "uncrustify executable was not found.
Please install uncrustify or set the executable location with

  git config hooks.uncrustify.path /path/to/uncrustify

  See https://github.com/uncrustify/uncrustify"


for file in $@; do


KWERRORS=kwstyle/${file}.txt
touch ${KWERRORS}

while [ -f ${KWERRORS} ]; do

if [ -f stop ]; then
  exit -1
fi

if [ ! -f ${KWERRORS}_skip_uncrustify ]; then
### A possible bug in uncrustify breaks complicated macros by adding extra spaces surrounding "##" and "#"
### This is an interaction betweeen the macro directives and indenting of includes and defines.
${UNCRUSTIFYBIN} -c C:/Project/PlusB-bin/itk/Utilities/Maintenance/uncrustify_itk.cfg -l CPP -f ${file} | sed 's/  *##  */##/g' | sed 's/#  */#/g' > ${file}_uncrustify
diff  ${file}_uncrustify ${file}
if [ $? -ne 0 ]; then
  mv ${file}_uncrustify ${file}
else
  rm ${file}_uncrustify
fi
fi

KWSTYLE_EXECUTABLE-NOTFOUND -xml C:/Project/PlusB-bin/itk-bin/Utilities/KWStyle/ITK.kws.xml -v -o C:/Project/PlusB-bin/itk/Utilities/KWStyle/ITKOverwrite.txt -gcc $file > ${KWERRORS}

find ${KWERRORS} -size 0 -exec rm {} \;

if [ -f ${KWERRORS} ]; then
  vim -q ${KWERRORS}

  echo "Shall I skip uncrustify step (y/n)?  Or ignore KWErrors (U)?"
  read skipuncrustify

  if [ ${skipuncrustify} == "y" ]; then
    ${UNCRUSTIFYBIN} -c C:/Project/PlusB-bin/itk/Utilities/Maintenance/uncrustify_itk.cfg -l CPP -f ${file} -o ${KWERRORS}_skip_uncrustify
  fi
  if [  ${skipuncrustify} == "U" ]; then
     echo "Ignoring KWErrors"
     rm ${KWERRORS}
  fi
fi


done


done
