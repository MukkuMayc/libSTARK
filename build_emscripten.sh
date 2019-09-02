if [ ! -d '_build' ]; then
    mkdir _build
fi
cd _build

emcmake cmake ..
emmake make -j2
python3 ../put_arguments.py

cd tinyram/stark-tinyram

PAGE=index.html
if test -f "$PAGE"; then
    rm "$PAGE"
fi

echo -n "<script src='stark-tinyram.js'></script>" >> "$PAGE"
python3 -m http.server