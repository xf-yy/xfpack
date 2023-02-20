# ●项目介绍   
***   
    xfpack是一个高效的序列化库，采用c++11语言开发。   
    作者：xiaofan <75631302@qq.com>   
   
# ●特性   
***    
    已实现：  
        1、支持多种类型数据的序列化操作   
        2、支持多种类型数据的反序列化操作   
				3、支持自定义类型数据的序列化/反序列化操作  
				4、采用内存池存储序列化结果     
   
# ●编译方法   
***   
    注：当前版本仅支持linux环境编译，且gcc版本最低4.8.5版本，编译方法如下：   
    mkdir build   
    cd build    
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./ ..   
    make   
    make install   
   
# ●使用样例   
***   
 
```  
    xfpack::Init(16*1024, 4);

    xfpack::Packer pack;

    pack.Pack((bool)true);
    pack.Pack((uint32_t)0x12345678);
    pack.Pack((uint64_t)0x1234567890abcdef);

    pack.Pack((float)3.1415926);
    pack.Pack((double)9999.123456789);

    xfpack::Unpacker unpack(pack.GetBlockList());

    bool b;
    unpack.Unpack(b);

    uint32_t u32;
    unpack.Unpack(u32);

    uint64_t u64;
    unpack.Unpack(u64);

    float f;
    unpack.Unpack(f);

    double d;
    unpack.Unpack(d);
```  

   
# ●版权信息   
***   
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
   
