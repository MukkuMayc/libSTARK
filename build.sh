#create build dir
if [ ! -d "_build" ]; then
    mkdir _build
fi
cd _build

#run cmake
cmake ..

#set threads number while compilation
input=../threads_num.txt
if [ -f "$input" ]; then
  while IFS= read -r line || [ -n "$line" ]; do
    echo "LINE: $line"
    threads_num="$line"
  done < "$input"
else
  threads_num=2
fi

#compile
make -j"$threads_num"