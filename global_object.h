#ifndef MJS_GLOBAL_OBJECT_H
#define MJS_GLOBAL_OBJECT_H

#include "value.h"

namespace mjs {

class global_object : public object {
public:
    static std::shared_ptr<global_object> make();
    virtual ~global_object() {}

    virtual const object_ptr& object_prototype() const = 0;
    virtual object_ptr make_raw_function() = 0;
    virtual object_ptr make_function(const native_function_type& f, int named_args) = 0;
    virtual object_ptr to_object(const value& v) = 0;

    static void put_function(const object_ptr& o, const native_function_type& f, int named_args);

protected:
    using object::object;
};

extern string index_string(uint32_t index);

} // namespace mjs

#endif
