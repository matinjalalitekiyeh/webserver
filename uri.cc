#include "uri.hpp"

struct magno::uri::Impl {
//        std::string /path_delimiter = "/";
    std::string scheme;
    std::string host;
    std::vector<std::string> path;
};

magno::uri::uri() : impl_(new Impl) {}

bool magno::uri::parse_from_string(const std::string &uriString) {
    // parse scheme.
    const auto scheme_end = uriString.find(':');
    impl_->scheme = uriString.substr(0, scheme_end);
    auto rest = uriString.substr(scheme_end + 1);

    // parse host.
    if (rest.substr(0, 2) == "//") {
        const auto authority_end = rest.find('/', 2);
        const auto port_delimiter = rest.find(":");
        if (port_delimiter == std::string::npos) {
            impl_->host = rest.substr(2, authority_end - 2);
        }else{
            impl_->host = rest.substr(2, port_delimiter - 2);
        }
        rest = rest.substr(authority_end);
    }else{
        impl_->host.clear();
    }

    // parse path.
    impl_->path.clear();
    if (rest == "/") {
       impl_->path.push_back("");
    } else  if (!rest.empty()) {
        for (;;) {
            auto path_delimiter = rest.find('/');
            if (path_delimiter == std::string::npos) {
                impl_->path.push_back(rest);
                break;
            }else{
                impl_->path.emplace_back(
                                rest.begin(),
                                rest.begin() + path_delimiter
                            );
                rest = rest.substr(path_delimiter + /*impl_->path_delimiter.length()*/1);
            }
        }
    }

//    do  {
//        const auto path_delimiter = rest.find('/');
//        if (path_delimiter == std::string::npos) {
//            path_delimiter = rest.length();
//        }
//        impl_->path.emplace_back(
//                        rest.begin(), rest.begin() + path_delimiter
//                    );
//        rest = rest.substr(path_delimiter + 1);
//    }while (!rest.empty());



    return true;
}

std::string magno::uri::get_scheme() const {
    return impl_->scheme;
}

std::string magno::uri::get_host() const {
    return impl_->host;
}

std::vector<std::string> magno::uri::get_path() const {
    return impl_->path;
}

bool magno::uri::has_port() const {
    return true;
}

uint16_t magno::uri::get_port() const {
    return 8080;
}

//void magno::uri::set_path_delimiter(const std::string &newPathDelimiter)
//{
//    impl_->path_delimiter = newPathDelimiter;
//}

magno::uri::~uri() = default;
