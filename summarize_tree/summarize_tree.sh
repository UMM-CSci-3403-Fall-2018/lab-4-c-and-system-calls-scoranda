#!/bin/bash

dir=$1

num_dirs=`find $dir -type d | wc -l`
num_files=`find $dir -type f | wc -l`

echo There were $num_dirs directories.
echo There were $num_files regular files.
