#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Usage: $0 input.wav"
  exit 1
fi

input="$1"
output="${input%.*}.raw"

ffmpeg -i "$input" -f f32le -ar 44100 -ac 1 "$output"
