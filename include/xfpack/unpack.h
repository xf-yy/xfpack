/*************************************************************************
Copyright (C) 2022 The xfpack Authors. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***************************************************************************/

#ifndef __xfpack_unpack_h__
#define __xfpack_unpack_h__

#include "xfpack/type.h"
#include "xfpack/strview.h"
#include "xfpack/block_list.h"

using namespace xfutil;

namespace xfpack 
{

class Unpacker
{
public:
    Unpacker(BlockListPtr& buf_list);
    
public:
    bool Unpack(bool& v)
    {
        uint8_t uv;
        bool ret = Unpack(uv);
        v = uv;
        return ret;
    }
    bool Unpack(int8_t& v)
    {
        uint8_t uv;
        bool ret = Unpack(uv);
        v = uv;
        return ret;

    }
    bool Unpack(uint8_t& v);

    bool Unpack(int16_t& v);
    bool Unpack(uint16_t& v);
    bool UnpackFixed(uint16_t& v);

    bool Unpack(int32_t& v);
    bool Unpack(uint32_t& v);
    bool UnpackFixed(uint32_t& v);

    bool Unpack(int64_t& v);
    bool Unpack(uint64_t& v);
    bool UnpackFixed(uint64_t& v);

    bool Unpack(float& v)
    {
        union 
        { 
            float f; 
            uint32_t i; 
        }uv;
        bool ret = UnpackFixed(uv.i);
        v = uv.f;
        return ret;
    }    
    bool Unpack(double& v)
    {
        union 
        { 
            double d; 
            uint64_t i; 
        }uv;
        bool ret = UnpackFixed(uv.i);
        v = uv.d;
        return ret;

    }

    bool Unpack(StrView& v);
    bool Unpack(UnpackStructCallback cb, void* arg)
    {
        return cb(*this, arg);
    }

private:
    bool NextBlock();

private:
    BlockListPtr m_block_list;

    ssize_t m_block_list_idx;
    const byte_t* m_ptr;
    const byte_t* m_buf_end;

private:
	Unpacker(const Unpacker&) = delete;
	Unpacker& operator=(const Unpacker&) = delete;
};


} 

#endif

