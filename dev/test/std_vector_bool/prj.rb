require 'mxx_ru/cpp'
MxxRu::Cpp::exe_target {
	required_prj 'rapidjson_mxxru/prj.rb'

	target( "_unit.test.std_vector_bool" )

	cpp_source( "main.cpp" )
}

