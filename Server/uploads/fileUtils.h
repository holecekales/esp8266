#ifndef _fileUtils_h_
#define _fileUtils_h_


// I am going to add another comment right here and see how it goes


// format file output with respect to size 
String formatBytes(size_t bytes)
{
  if (bytes < 1024)                 return String(bytes) + "B";
  if (bytes < (1024 * 1024))        return String(bytes / 1024.0) + "KB";
  if (bytes < (1024 * 1024 * 1024)) return String(bytes / 1024.0 / 1024.0) + "MB";
  return String(bytes / 1024.0 / 1024.0 / 1024.0) + "GB";
}

String getContentType(String filename, bool download)
{
  if (download)                         return "application/octet-stream";
  else if (filename.endsWith(".htm"))   return "text/html";
  else if (filename.endsWith(".html"))  return "text/html";
  else if (filename.endsWith(".css"))   return "text/css";
  else if (filename.endsWith(".js"))    return "application/javascript";
  else if (filename.endsWith(".png"))   return "image/png";
  else if (filename.endsWith(".gif"))   return "image/gif";
  else if (filename.endsWith(".jpg"))   return "image/jpeg";
  else if (filename.endsWith(".ico"))   return "image/x-icon";
  else if (filename.endsWith(".xml"))   return "text/xml";
  else if (filename.endsWith(".pdf"))   return "application/x-pdf";
  else if (filename.endsWith(".zip"))   return "application/x-zip";
  else if (filename.endsWith(".gz"))    return "application/x-gzip";
  return "text/plain";
}

#endif // _fileUtils_h_