# FileCoder
FileCoder - small program for file ecryption that use [Vernam Cipher](https://en.wikipedia.org/wiki/One-time_pad).
 
 ## Commands:
* Encode file: encode -F file_to_encode -K key_file -C cipher_file 
* Decode file: decode -F decoded_file -K key_file -C cipher_file 

## Also valid commands:
* Encode file: encode -F file_to_encode
* Decode file: decode -K key_file -C cipher_file 

## Encode modificators:
* File to encode : -F file_path
* Your own name\path to key: -K key_name or key_path or key_path\key_name
* Your own name\path to cipher: -C cipher_name or cipher_path or cipher_path\cipher_name

## Decode modificators:
* Path to cipher file : -F cipher_path
* Path to key file : -K key_path
* Decoded file path + name : -F path + name

## Encode details:
* If there is no path\name to store the cipher file, path will be taken from file_path\name.The path will also be assigned a modifier: ".cipher"
* If there is no path\name to store the key file, path will be taken from file_path\name.The path will also be assigned a modifier: ".key"

## Decode details
* If there is no path\name to store the encoded file , path will be taken from cipher_path\name.The path will also be assigned a modifier: ".decoded"
