#!/bin/sh
# Check jte exit status on success and failure cases.
# Usage: tests/run.sh [path/to/jte]

JTE=$(realpath "${1:-./jte}")
FIXTURES=$(realpath "$(dirname "$0")/fixtures")
WORKDIR=$(mktemp -d)
trap 'rm -rf "$WORKDIR"' EXIT
cd "$WORKDIR" || exit 1

failures=0

# expect <status> <jte arguments...>
expect() {
    expected=$1
    shift
    "$JTE" "$@" > /dev/null 2>&1
    status=$?
    if [ "$status" -ne "$expected" ]; then
        echo "FAIL: jte $* exited with $status, expected $expected"
        failures=$((failures + 1))
    fi
}

# expect_title <file> <title>
expect_title() {
    if ! "$JTE" -l "$1" 2> /dev/null | grep -qx "Title: $2"; then
        echo "FAIL: $1 is not titled $2"
        failures=$((failures + 1))
    fi
}

cp "$FIXTURES/silence.flac" song.flac
printf 'not really a picture' > cover.png

expect 0 -t Title -n 1 -a Artist -A Album -y 2000 -g Genre song.flac
expect_title song.flac Title
expect 0 -c cover.png song.flac
expect 0 -l song.flac
expect 0 --clear song.flac
expect_title song.flac ""

if [ "$failures" -ne 0 ]; then
    echo "$failures failure(s)"
    exit 1
fi
echo "All tests passed"
