# Christopher Haack
# chaack

from math import *
from random import *

morse_code = { 
  'a' : '.-',
  'b' : '-...',
  'c' : '-.-.',
  'd' : '-..',
  'e' : '.',
  'f' : '..-.',
  'g' : '--.',
  'h' : '....',
  'i' : '..',
  'j' : '.---',
  'k' : '-.-',
  'l' : '.-..',
  'm' : '--',
  'n' : '-.',
  'o' : '---',
  'p' : '.--.',
  'q' : '--.-',
  'r' : '.-.',
  's' : '...',
  't' : '-',
  'u' : '..-',
  'v' : '...-',
  'w' : '.--',
  'x' : '-..-',
  'y' : '-.--',
  'z' : '--..'
}


def invert_dict(dic):
    ''' takes in a dictionary, and returns a new dictionary, with the old
    dictionaries keys set as its values, and its values set as the keys'''
    newdict ={}
    for key in dic:
        oldval = dic[key]
        newdict[oldval] = key
    return newdict
morse_uncode = invert_dict(morse_code)


def find_substring(string, i, c):
    ''' finds a substring from the input string, starting at the index i
    of the original string and ending at the character c and returns
    that substring'''
    assert i >= 0 and i < len(string), 'assert i is in the bounds of the str'
    assert len(c) ==1, 'asserts length of character to stop at is 1'
    temp = string[i:]
    if c in temp:
        endpoint = temp.index(c)
        final_string = temp[:endpoint]
    else:
        final_string = temp
    return final_string


def to_morse_code(s):
    ''' convert's a plain text string to a morse string and 
    returns the value'''
    code =''
    for char in s:
        if char >= 'a' and char <= 'z':
            morse = morse_code[char]
            code += '[' + morse + ']'
        elif char >= 'A' and char <= 'Z':
            morse = morse_code[char.lower()]
            code += '{' + morse + '}'
        elif char == '[' or char == ']' or char == '{' or char == '}' \
             or char == ',' or char == '.' or char == '\\':
            morse = '\\' + char
            code += morse
        else:
            code += char
    return code

def from_morse_code(s):
    ''' takes a string written in morse code and converts it to regular text'''
    decode = ''
    index = 0
    while index < len(s):
        if s[index] == '[' :
            morse = find_substring(s,index+1,']')
            decode += morse_uncode[morse]
            index += len(morse) + 2
            
        elif s[index] == '{' :
            morse = find_substring(s,index+1,'}')
            decode += morse_uncode[morse].upper()
            index += len(morse) + 2
        elif s[index] == '\\':
            decode += s[index +1]
            index +=2
        else:
            decode += s[index]
            index +=1
    return decode


def convert_file_to_morse_code(filename_root, ext1, ext2):
    ''' converts a file from text to a morse file and creates a morse file'''
    readfile = filename_root + ext1
    morse = ''
    textfile = open(readfile, 'r')
    while True:
        text = textfile.readline()
        morse += to_morse_code(text)
        if text == '':
            break
    textfile.close()
    writefile = filename_root + ext2
    morsefile = open(writefile, 'w')
    morsefile.write(morse)
    morsefile.close()    
    
def convert_file_from_morse_code(filename_root, ext1, ext2):
    ''' converts a morse file to a text file and creates a text file'''
    readfile = filename_root + ext1
    text = ''
    morsefile = open(readfile, 'r')
    while True:
        morse = morsefile.readline()
        text += from_morse_code(morse)
        if morse == '':
            break
    morsefile.close()
    writefile = filename_root + ext2
    textfile = open(writefile, 'w')
    textfile.write(text)
    textfile.close()               

