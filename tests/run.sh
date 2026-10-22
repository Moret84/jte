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

# expect_listed <file> <line expected in jte -l output>
expect_listed() {
    if ! "$JTE" -l "$1" 2> /dev/null | grep -qxF "$2"; then
        echo "FAIL: jte -l $1 does not list \"$2\""
        failures=$((failures + 1))
    fi
}

cp "$FIXTURES/silence.flac" song.flac
printf 'not really a picture' > cover.png

expect 0 -t Title -n 1 -d 2 -a Artist -A Album -y 2000 -g Genre song.flac
expect_listed song.flac "Title: Title"
expect_listed song.flac "Disc: 2"
expect 0 -c cover.png song.flac
expect 0 -l song.flac
expect 0 --clear song.flac
expect_listed song.flac "Title: "
expect_listed song.flac "Disc: "

cp "$FIXTURES/silence.flac" read-only.flac
chmod 444 read-only.flac
printf 'not a picture either' > cover.gif

expect 1 -t Title missing.flac
expect 1 -l missing.flac
expect 1 --clear missing.flac
expect 1 -t Title song.xyz
expect 1 song.flac
expect 1 -d two song.flac
expect 1 -c cover.gif song.flac
expect 1 -c missing.png song.flac
if [ "$(id -u)" -ne 0 ]; then
    expect 1 -t Title read-only.flac
fi

expect 1 -t Other missing.flac song.flac
expect_listed song.flac "Title: Other"

if [ "$failures" -ne 0 ]; then
    echo "$failures failure(s)"
    exit 1
fi
echo "All tests passed"
