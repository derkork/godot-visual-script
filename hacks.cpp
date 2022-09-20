#include "hacks.h"

#include <godot_cpp/classes/translation_server.hpp>

String vformat(const String &p_text, const Variant &p1, const Variant &p2, const Variant &p3, const Variant &p4, const Variant &p5) {
    Array args;
    if (p1.get_type() != Variant::NIL) {
        args.push_back(p1);

        if (p2.get_type() != Variant::NIL) {
            args.push_back(p2);

            if (p3.get_type() != Variant::NIL) {
                args.push_back(p3);

                if (p4.get_type() != Variant::NIL) {
                    args.push_back(p4);

                    if (p5.get_type() != Variant::NIL) {
                        args.push_back(p5);
                    }
                }
            }
        }
    }

    bool error = false;
    String fmt = p_text.format(args, "%s");

    ERR_FAIL_COND_V_MSG(error, String(), fmt);

    return fmt;
}

Dictionary from_property_info(const PropertyInfo& info) {
    Dictionary d;
    d["name"] = info.name;
    d["class_name"] = info.class_name;
    d["type"] = info.type;
    d["hint"] = info.hint;
    d["hint_string"] = info.hint_string;
    d["usage"] = info.usage;
    return d;
}

String RTR(const String &p_text, const String &p_context) {
    // FIXME: no tool_translate available in TranslationServer
    /*if (TranslationServer::get_singleton()) {
        String rtr = TranslationServer::get_singleton()->tool_translate(p_text, p_context);
        if (rtr.is_empty() || rtr == p_text) {
            return TranslationServer::get_singleton()->translate(p_text, p_context);
        } else {
            return rtr;
        }
    }*/

    return p_text;
}