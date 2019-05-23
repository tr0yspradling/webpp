#ifndef WEBPP_COOKIES_H
#define WEBPP_COOKIES_H

/*
 * Documentations about cookies:
 *
 *
 *  Standard RFC:
 *    https://tools.ietf.org/html/rfc6265
 *  Set-Cookie:
 *    https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Set-Cookie
 *  Cookie:
 *    https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Cookie
 *
 *
 * -----------------------------------------------------------------------------
 * Other close implementations:
 *
 *  Drogon:
 *    https://github.com/an-tao/drogon/blob/master/lib/inc/drogon/Cookie.h
 *    https://github.com/an-tao/drogon/blob/master/lib/src/Cookie.cc
 *
 *  Pistache:
 *    https://github.com/oktal/pistache/blob/master/include/pistache/cookie.h
 *    https://github.com/oktal/pistache/blob/master/src/common/cookie.cc
 *
 *  Cgicc:
 *    https://github.com/cmakified/cgicc/blob/master/cgicc/HTTPCookie.h
 *    https://github.com/cmakified/cgicc/blob/master/cgicc/HTTPCookie.cpp
 */

#include <string>
#include <unordered_set>

namespace webpp {

    class cookie {
      private:
        std::string _name = "";
        std::string _value = "";
        std::string _comment = "";
        std::string _domain = "";
        std::string _path = "/";
        unsigned long _max_age;
        bool _secure = false;
        bool _host_only = false;
        bool _encrypted = false;

      public:
        /**
         * empty cookie
         */
        cookie() = default;
        cookie(std::string source) noexcept;

        inline decltype(_name) const& name() const noexcept { return _name; }
        inline decltype(_value) const& value() const noexcept { return _value; }
        inline decltype(_comment) const& commnet() const noexcept {
            return _comment;
        }
        inline decltype(_domain) const& domain() const noexcept {
            return _domain;
        }
        inline decltype(_max_age) const& max_age() const noexcept {
            return _max_age;
        }
        inline decltype(_secure) const& secure() const noexcept {
            return _secure;
        }
        inline decltype(_host_only) const& host_only() const noexcept {
            return _host_only;
        }

        inline cookie& name(std::string const& __name) noexcept {
            _name = __name;
            return *this;
        }

        inline cookie& name(std::string&& __name) noexcept {
            _name = std::move(__name);
            return *this;
        }

        inline cookie& value(std::string&& __value) noexcept {
            _value = std::move(__value);
            return *this;
        }

        inline cookie& value(std::string const& __value) noexcept {
            _value = __value;
            return *this;
        }

        inline cookie& comment(std::string const& __comment) noexcept {
            _comment = __comment;
            return *this;
        }

        inline cookie& comment(std::string&& __comment) noexcept {
            _comment = std::move(__comment);
            return *this;
        }

        inline cookie& domain(std::string const& __domain) noexcept {
            _domain = __domain;
            return *this;
        }
        inline cookie& domain(std::string&& __domain) noexcept {
            _domain = std::move(__domain);
            return *this;
        }

        inline cookie& path(std::string const& __path) noexcept {
            _path = __path;
            return *this;
        }

        inline cookie& path(std::string&& __path) noexcept {
            _path = std::move(__path);
            return *this;
        }

        inline cookie& remove() noexcept {
            // TODO
            return *this;
        }

        inline decltype (_encrypted) encrypted() const noexcept {
            return _encrypted;
        }

        inline cookie& encrypted(decltype (_encrypted) __encrypted) noexcept {
            _encrypted = __encrypted;
            return *this;
        }

        decltype(_value) encrypted_value() const noexcept;

        friend inline void swap(cookie& first, cookie& second) noexcept {
            using std::swap;
            swap(first._name, second._name);
            swap(first._value, second._value);
            swap(first._comment, second._comment);
            swap(first._domain, second._domain);
            swap(first._path, second._path);
            swap(first._max_age, second._max_age);
            swap(first._secure, second._secure);
            swap(first._host_only, second._host_only);
        }
    };

    using cookies = std::unordered_set<webpp::cookie>;

} // namespace webpp

#endif // WEBPP_COOKIES_H