## Name ##
 WebdavClient - A very simple C++ interface for the webdav neon lib

## Description ##
 __WebdavClient__ makes it very easy to transmit data between a local machine
and a webdav server.  

## Build ##
   + Include WebdavClient.h
   + compile with -lneon
   + example: g++ main.cc WebdavClient.cc -I . -lneon

## Examples ##
>#include <WebdavClient.h>
>#include <iostream>
>
>int main(){
>  
>  const std::string host("my_webdavserver.com");
>  const std::string user("my_user");
>  const std::string pass("my_password");
>  const std::string uri("/my_location/");
>  const unsigned port = 80;
>
>  WebdavClient webdavClient(host, port, user, pass);
>
>  // Upload a file to webdav server
>  if(webdavClient.put(uri + "my_file_put", "my_file_put")){
>    std::cout << "Upload succesfull!" << std::endl;
>  }
>  else {
>    std::cout << "Upload error! " << webdavClient.getLastError() << std::endl;
>  }
>
>  // Download a file from webdav server
>  if(webdavClient.get(uri + "my_file_put", "my_file_get")){
>    std::cout << "Download successfull!" << std::endl;
>  }
>  else {
>    std::cout << "Download error! " << webdavClient.getLastError() << std::endl;
>  }
>
>  // Check if a file on webdav server exists
>  if(webdavClient.exist(uri + "my_file_put")){
>    std::cout << "File exists! "  << std::endl;
>  }
>  else {
>    std::cout << "File does not exist! " << webdavClient.getLastError() << std::endl;
>  }
>
>  // Create directory on webdav server
>  if(webdavClient.mkdir(uri + "new_dir")){
>    std::cout << "Create folder successfull!" << std::endl;
>  }
>  else {
>    std::cout << "Create folder error! " << webdavClient.getLastError() << std::endl;
>  }
>
>  // Remove a file on webdav server
>  if(webdavClient.rm(uri + "my_file_put")){
>    std::cout << "Remove file successfull!" << std::endl;
>  }
>  else {
>    std::cout << "Remove file error! " << webdavClient.getLastError() << std::endl;
>  }
>
>  // Remove a directory on webdav server
>  if(webdavClient.rm(uri + "new_dir/")){
>    std::cout << "Remove directory successfull!" << std::endl;
>  }
>  else {
>    std::cout << "Remove directory error! " << webdavClient.getLastError() << std::endl;
>  }
>
>  return 0;
>}
   
## Dependencies ##
 + neon
 + c++99

## Copyrigth
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.  
This is free software: you are free to change and redistribute it.  There is NO WARRANTY, to the extent permitted by law.

## Author ##
Written by Erik Zenker (erikzenker@hotmail.com)
