#include <QString>

#include <nlohmann/json.hpp>
#include <curl/curl.h>

#include <sstream>

using namespace nlohmann;
using namespace std;

ostringstream stream;

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    ostringstream *stream = (ostringstream*)userdata;
    size_t count = size * nmemb;
    stream->str("");
    stream->write(ptr, count);
    return count;
}

class Response
{
    public:
        int status_code;
        QString url, data;
};

class GitHub
{
    public:
        QString download(string url){
            CURL *curl;
            CURLcode res;

            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream);
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

                res = curl_easy_perform(curl);

                curl_easy_cleanup(curl);
                string answer = stream.str();
                return QString::fromStdString(answer);
            }
            return QString("ban");
        }

        QString download_(QString url_)
        {
            return url_;
        }
    private:
        QString pass = "1488";
};
