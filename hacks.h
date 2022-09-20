/**
 * This is an assortment of hacks that need to be removed eventually, but right now I need them to get the project working.
 */
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/core/property_info.hpp>


using namespace godot;

// Variant's vformat function is not exposed right now, so I copy/pasted it here.
String vformat(const String &p_text, const Variant &p1 = Variant(), const Variant &p2 = Variant(), const Variant &p3 = Variant(), const Variant &p4 = Variant(), const Variant &p5 = Variant());

// PropertyInfo has no dictionary conversion operator, so I copy/pasted it here.
Dictionary from_property_info(const PropertyInfo& info);

// we don't have access to the Callable::CallError struct/enum, so right now I copy the values from the main engine.
// i can change this back once the Callable::CallError structure is exposed.
#define CALL_ERROR_TYPE HackCallError

struct HackCallError {
    enum Error {
        CALL_OK,
        CALL_ERROR_INVALID_METHOD,
        CALL_ERROR_INVALID_ARGUMENT, // expected is variant type
        CALL_ERROR_TOO_MANY_ARGUMENTS, // expected is number of arguments
        CALL_ERROR_TOO_FEW_ARGUMENTS, // expected is number of arguments
        CALL_ERROR_INSTANCE_IS_NULL,
        CALL_ERROR_METHOD_NOT_CONST,
    };
    Error error = Error::CALL_OK;
    int argument = 0;
    int expected = 0;
};

String RTR(const String &p_text, const String &p_context = "");
