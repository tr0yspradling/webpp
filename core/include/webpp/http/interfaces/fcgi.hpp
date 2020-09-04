#ifndef WEBPP_INTERFACE_FCGI
#define WEBPP_INTERFACE_FCGI

#include "../../std/internet.hpp"
#include "../../std/set.hpp"
#include "../../std/vector.hpp"
#include "../request.hpp"
#include "./common/server.hpp"
#include "basic_interface.hpp"


namespace webpp {

    template <typename Traits>
    class fcgi : public basic_interface<Traits, fcgi<Traits>> {
      public:
        static_assert(
          is_traits_v<Traits>,
          "The specified template parameter is not a valid traits type.");
        using traits_type = Traits;
        using endpoint_t  = stl::net::ip::tcp::endpoint;

      private:
        stl::set<traits_type, endpoint_t> _endpoints;
        common::server               _server;

        auto get_endpoints() noexcept {
            stl::net::ip::tcp::resolver resolver(_server.io);
            stl::error_code             ec;
            //        std::net::ip::tcp::resolver::results_type _endpoints;
            //        if (_fcgi->endpoints().empty()) {
            //            _endpoints = resolver.resolve(
            //                default_fcgi_listen_addr,
            //                std::to_string(default_fcgi_listen_port));
            //        } else {
            //            _endpoints = std::net::ip::tcp::v4();
            //        }
            return stl::vector<traits_type, stl::net::ip::tcp::endpoint>{};
        }


      public:
        webpp::router_t<traits_type, fcgi> router;

        fcgi() noexcept;

        void operator()() noexcept;

        /**
         * This will only work before you run the operator()
         */
        void add_endpoint(endpoint_t _endpoint) noexcept {
            _endpoints.insert(stl::move(_endpoint));
        }

        /**
         * This will only work before you run the operator()
         */
        void add_endpoint(stl::string_view const& addr,
                          uint_fast8_t            port) noexcept {
            _endpoints.emplace(stl::net::ip::make_address(addr), port);
        }

        /**
         * Clear the endpoints
         */
        void clear_endpoints() noexcept {
            _endpoints.clear();
        }

        /**
         * Return the endpoints.
         */
        auto const& endpoints() const noexcept {
            return _endpoints;
        }
    };

    template <typename Traits>
    class basic_request<Traits, fcgi<Traits>> {
      private:
      public:
    };

} // namespace webpp

#endif
