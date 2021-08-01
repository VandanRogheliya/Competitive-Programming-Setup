#!/bin/bash
if [ -z $1 ]
then
  cp ../sol.cpp a.cpp
  cp ../sol.cpp b.cpp
  cp ../sol.cpp c.cpp
  cp ../sol.cpp d.cpp
  cp ../sol.cpp e.cpp
  cp ../sol.cpp f.cpp
else 
  cp ../sol.cpp "$1".cpp
fi