# jte

jdid tag editor is a commandline application which allows you to edit your music files tags.

It supports title, artist, album, year, tracknumber, genre and front cover tags.  
Currently, it is only compatible with FLAC and MP3 formats.  
Be aware that setting a front cover will remove all pictures that could be attached to the music files.

### Dependencies


* gcc
* taglib
* tclap
* openssl
### Installation

To install just type
```
$ make 
# make install
```



### Usage

 jte  [-n <number>] [-t <title>] [-a <artist>] [-A <album>] [-y <year>] [-g <genre>] [-c <path/to/cover>] [-h] \<file(s)\>

 -n \<number\>,  --tracknumber \<number\>  
 Define the tracknumber tag
 
 -t \<title\>,  --title \<title\>  
 Define the title tag

  -a \<artist\>,  --artist \<artist\>  
  Define the artist tag

  -A \<album\>,  --album  \<album\>  
  Define the album tag

  -y \<year\>,  --year \<year\>  
  Define the year tag

  -g \<genre\>,  --genre \<genre\>  
  Define the genre tag

  -c \<path/to/cover\>,  --cover \<path/to/cover\>  
  Define the front cover tag

  \<file(s)\>  (accepted multiple times)  
  (required)  The tag edition audio file(s) target(s)

