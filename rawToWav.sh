#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Usage: $0 input.raw"
  exit 1
fi

input="$1"
output="${input%.*}.wav"

ffmpeg -f f32le -ar 44100 -ac 1 -i "$input" "$output"
