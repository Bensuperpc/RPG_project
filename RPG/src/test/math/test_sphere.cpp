#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE sphere

extern "C"
{
#include "quadmath.h"
}

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/float128.hpp>
#include <boost/test/unit_test.hpp>
#include "../../lib/math/sphere.hpp"

BOOST_AUTO_TEST_CASE(test_sphere_volume_1)
{
    BOOST_REQUIRE_MESSAGE(sphere::sphereVolume<uint64_t>(10000) == static_cast<uint64_t>(4188790204786),
        sphere::sphereVolume<uint64_t>(10000) << " instead: " << static_cast<uint64_t>(4188790204786));

    BOOST_REQUIRE_MESSAGE(sphere::sphereVolume<uint64_t>(151) == static_cast<uint64_t>(14421799), sphere::sphereVolume<uint64_t>(151)
                                                                                                      << " instead: " << static_cast<uint64_t>(14421799));
    BOOST_REQUIRE_MESSAGE(
        sphere::sphereVolume<uint64_t>(0) == static_cast<uint64_t>(0), sphere::sphereVolume<uint64_t>(0) << " instead: " << static_cast<uint64_t>(0));
}

BOOST_AUTO_TEST_CASE(test_sphere_volume_2)
{
    BOOST_REQUIRE_MESSAGE(sphere::sphereVolume<int>(32) == static_cast<int>(137258), sphere::sphereVolume<int>(32) << " instead: " << static_cast<int>(137258));
    BOOST_REQUIRE_MESSAGE(
        sphere::sphereVolume<int>(151) == static_cast<int>(14421799), sphere::sphereVolume<int>(151) << " instead: " << static_cast<int>(14421799));
    BOOST_REQUIRE_MESSAGE(sphere::sphereVolume<int>(0) == static_cast<int>(0), sphere::sphereVolume<int>(0) << " instead: " << static_cast<int>(0));
}

// 1086832411937628777542115
BOOST_AUTO_TEST_CASE(test_sphere_volume_3)
{
    BOOST_REQUIRE_MESSAGE(
        static_cast<boost::multiprecision::uint1024_t>(sphere::sphereVolume<boost::multiprecision::float128>(EARTH_RADIUS) / 1000000) == 1086832411937628777,
        static_cast<boost::multiprecision::uint1024_t>(sphere::sphereVolume<boost::multiprecision::float128>(EARTH_RADIUS) / 1000000)
            << " instead: " << 1086832411937628777);
}

BOOST_AUTO_TEST_CASE(test_sphere_surface_1)
{
    BOOST_REQUIRE_MESSAGE(sphere::sphereSurface<uint64_t>(10000) == static_cast<uint64_t>(125663), sphere::sphereSurface<uint64_t>(10000)
                                                                                                       << " instead: " << static_cast<uint64_t>(125663));
    BOOST_REQUIRE_MESSAGE(sphere::sphereSurface<uint64_t>(151) == static_cast<uint64_t>(1897), sphere::sphereSurface<uint64_t>(151)
                                                                                                   << " instead: " << static_cast<uint64_t>(1897));
    BOOST_REQUIRE_MESSAGE(
        sphere::sphereSurface<uint64_t>(0) == static_cast<uint64_t>(0), sphere::sphereSurface<uint64_t>(0) << " instead: " << static_cast<uint64_t>(0));
}

BOOST_AUTO_TEST_CASE(test_sphere_surface_2)
{
    BOOST_REQUIRE_MESSAGE(
        sphere::sphereSurface<int>(6598) == static_cast<int>(82912), sphere::sphereSurface<int>(6598) << " instead: " << static_cast<int>(82912));
    BOOST_REQUIRE_MESSAGE(sphere::sphereSurface<int>(151) == static_cast<int>(1897), sphere::sphereSurface<int>(151) << " instead: " << static_cast<int>(1897));
    BOOST_REQUIRE_MESSAGE(sphere::sphereSurface<int>(0) == static_cast<int>(0), sphere::sphereSurface<int>(0) << " instead: " << static_cast<int>(0));
}

BOOST_AUTO_TEST_CASE(test_sphere_surface_3)
{
    BOOST_REQUIRE_MESSAGE(static_cast<uint64_t>(sphere::sphereSurface<boost::multiprecision::float128>(6.3781 * 10e6)) == static_cast<uint64_t>(8.01495684e+08),
        static_cast<uint64_t>(sphere::sphereSurface<boost::multiprecision::float128>(6.3781 * 10e6)) << " instead: " << static_cast<uint64_t>(8.01495684e+08));
}
