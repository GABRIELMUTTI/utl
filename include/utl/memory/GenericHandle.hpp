#pragma once

#include "Handle.hpp"

namespace utl
{
    template<class TPool, typename TObj> 
    class GenericHandle : public Handle<TPool>
    {
    public:
	GenericHandle(const TPool& pool, uint index, bool validity) :
	    Handle<TPool>(pool, index, validity)
	{
	    
	}
	
	inline TObj* operator ->()
	{ 
	    return static_cast<TObj*>(Handle<TPool>::pool.get(Handle<TPool>::index));
	}

	inline TObj operator *()
	{ 
	    return *static_cast<TObj*>(Handle<TPool>::pool.get(Handle<TPool>::index));
	}
    };
}
