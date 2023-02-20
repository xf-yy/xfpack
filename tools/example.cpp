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

#include <iostream>
#include <vector>
#include <string>
#include "xfpack.h"

using namespace xfutil;

class TestStruct
{
public:
    StrView name;
    int age;
    int sex;

    static void Pack(xfpack::Packer& pack, TestStruct* data)
    {
        pack.Pack(data->name);
        pack.Pack(data->age);
        pack.Pack(data->sex);
    }
    static bool Unpack(xfpack::Unpacker& unpack, TestStruct* data)
    {
        if(!unpack.Unpack(data->name))
        {
            return false;
        }
        if(!unpack.Unpack(data->age))
        {
            return false;
        }
        if(!unpack.Unpack(data->sex))
        {
            return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    xfpack::Init(16*1024, 4);

    //序列化
    xfpack::Packer pack;

    pack.Pack((bool)true);
    pack.Pack((int32_t)0xabcdef);
    pack.Pack((uint32_t)0x12345678);
    pack.Pack((uint64_t)0x1234567890abcdef);

    pack.Pack((float)3.1415926);
    pack.Pack((double)9999.123456789);

    TestStruct old_s;
    old_s.name.Set("testname");
    old_s.age = 40;
    old_s.sex = 1;
    TestStruct::Pack(pack, &old_s);

    //反序列化
    xfpack::Unpacker unpack(pack.GetBlockList());

    bool b;
    unpack.Unpack(b);

    int32_t i32;
    unpack.Unpack(i32);

    uint32_t u32;
    unpack.Unpack(u32);

    uint64_t u64;
    unpack.Unpack(u64);

    float f;
    unpack.Unpack(f);

    double d;
    unpack.Unpack(d);

    TestStruct new_s;
    TestStruct::Unpack(unpack, &new_s);

	return 0;
}

