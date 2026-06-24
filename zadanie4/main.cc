#include <drogon/drogon.h>

using namespace drogon;

void isPrime(const HttpRequestPtr& req,
             std::function<void(const HttpResponsePtr&)>&& callback,
             int number)
{
    bool prime = false;
    if (number > 1) {
        prime = true;
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                prime = false;
                break;
            }
        }
    }

    Json::Value result;
    result["number"] = number;
    result["isPrime"] = prime;

    auto resp = HttpResponse::newHttpJsonResponse(result);
    callback(resp);
}

int main() {
    app().registerHandler("/api/isprime/{number}",
        &isPrime,
        {Get});
    app().addListener("0.0.0.0", 8080);
    app().run();
}
