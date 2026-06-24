#include <drogon/drogon.h>

using namespace drogon;

void hello(const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback)
{
    Json::Value result;
    result["message"] = "Hello, World!";

    auto resp = HttpResponse::newHttpJsonResponse(result);
    callback(resp);
}

int main() {
    app().registerHandler("/api/hello",
        &hello,
        {Get});
    app().addListener("0.0.0.0", 8080);
    app().run();
}
