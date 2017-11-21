#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <iostream>
#include <limits>
#include <type_traits>

#include <rapidjson/document.h>

#include <json_dto/pub.hpp>

using namespace json_dto;

struct floats_t
{
	float m_num_float;
	double m_num_double;

	template< typename Json_Io >
	void
	json_io( Json_Io & io )
	{
		io
			& optional( "num_float", m_num_float, 0.0f )
			& optional( "num_double", m_num_double, 0.0 );
	}
};

TEST_CASE( "default init" , "[init]" )
{
	{
		const char * json_str = "{}";

		auto dto = json_dto::from_json< floats_t >( json_str );

		REQUIRE( Approx(0.0) == dto.m_num_float );
		REQUIRE( Approx(0.0) == dto.m_num_double );
	}
}

TEST_CASE( "point notation" , "[point_notation]" )
{
	{
		const char * json_str = "{"
			"\"num_float\": 3.14,"
			"\"num_double\": 2.718281828459"
		"}";

		auto dto = json_dto::from_json< floats_t >( json_str );

		REQUIRE( std::fabs( 3.14 - dto.m_num_float ) < 0.0001 );
		REQUIRE( std::fabs( 2.718281828459 - dto.m_num_double ) < 0.0000000000001 );
	}
}
