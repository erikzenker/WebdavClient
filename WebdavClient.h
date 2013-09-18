#ifndef WebdavClient_H
#define WebdavClient_H

#include <string>
#include <vector>
#include <neon/ne_props.h> /* ne_prop_result_set, ne_session */

struct WebdavPath {
  WebdavPath(std::string host, std::string path, std::string ressourceType, std::string lastModified, std::string contentType) :
    host(host),
    path(path),
    ressourceType(ressourceType),
    lastModified(lastModified),
    contentType(contentType) {
  
  }
  
  bool isFile(){
    if(!ressourceType.compare(""))
      return true;
    return false;
  }

  bool isDirectory(){
    return !isFile();
  }

  std::string host;
  std::string path;
  std::string ressourceType;
  std::string lastModified;
  std::string contentType;

};

class WebdavClient {
 public:
  WebdavClient(const std::string url, const unsigned port, const std::string user, const std::string pass);
  ~WebdavClient();

  std::vector<WebdavPath> ls(std::string uri);
  std::vector<WebdavPath> tree(std::string uri);
  std::string getLastError();
  bool exist(std::string uri);
  bool put(std::string uri, std::string localSource);
  bool get(std::string uri, std::string localDestination);
  bool mkdir(std::string uri);
  bool rm(std::string uri);


 private:
  static int setLogin(void *userdata, const char *realm, int attempts, char *usernmae, char *password);
  static void getProps(void *userdata, const ne_uri *uri, const ne_prop_result_set *set);
  ne_session *mSession;
  std::string mError;

};

#endif /* WebdavClient_H */
