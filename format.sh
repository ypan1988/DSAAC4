CLANG_FORMAT=clang-format

for DIRECTORY in 01
do
    echo "Formatting code under $DIRECTORY/"
    find "$DIRECTORY" \( -name '*.h' -or -name '*.cpp' \) -print0 | xargs -0 "$CLANG_FORMAT" -i
done