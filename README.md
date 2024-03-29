# jte

jdid tag editor is a commandline application which allows you to edit your music files tags using the [taglib](https://taglib.github.io/).

It supports title, artist, album, year, tracknumber, genre and front cover tags.
Currently, front cover can only be set on FLAC and MP3 music files.
Be aware that setting a front cover will remove all pictures that could be attached to the music files.
See [below](#informations-and-additional-formats) for more informations.

### Dependencies


* gcc
* taglib


### Installation

To install just type:
```
# make install
```


### Usage
```
 jte  [-n <number>] [-t <title>] [-a <artist>] [-A <album>] [-y <year>] [-g <genre>] [-c <path/to/cover>] [-h] <file(s)>
 
 --clear
 clear all tags

 -l,  --list
 list tag(s) instead of write them

 -n <number>,  --tracknumber <number>  
 Define the tracknumber tag
 
 -t <title>,  --title <title>  
 Define the title tag

  -a <artist>,  --artist <artist>  
  Define the artist tag

  -A <album>,  --album  <album>  
  Define the album tag

  -y <year>,  --year <year>  
  Define the year tag

  -g <genre>,  --genre <genre>  
  Define the genre tag

  -c <path/to/cover>,  --cover <path/to/cover>  
  Define the front cover tag

  <file(s)>  (accepted multiple times)  
  (required)  The tag edition audio file(s) target(s)
```
### Informations and additional formats

**jte** is very simple and uses the awesome [taglib](https://taglib.github.io/) library.  
Taglib provides an easy-to-implement high-level API to tag music (whatever the format) with commons metadatas such as title, artist, year, etc. But there is no high-level cover feature (for know).  
**jte** tries to help to provide it.  

As of now, **jte** supports MP3, FLAC, M4A and WAV.  
If you want to add a format to the list, you just have to extend the AudioFile class and implements the setCover method as well as clearCover(). Then, you just have to register your new format in the format map, giving the extension of the file it handles.  

Pull requests in that way are welcome.
