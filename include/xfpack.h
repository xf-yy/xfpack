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

#ifndef __xfpack_xfpack_h__
#define __xfpack_xfpack_h__

#include "xfpack/type.h"
#include "xfpack/strview.h"
#include "xfpack/block_list.h"
#include "xfpack/pack.h"
#include "xfpack/unpack.h"

#if __cplusplus < 201103L
#error "only support c++ 11 or later, use -std=c++11 option for compile"
#endif

namespace xfpack 
{

//使用前需初始化
bool Init(uint32_t block_size, uint32_t block_cache_num);

//版本号字符串格式
const char* GetVersionString();

//版本号整型格式
uint32_t GetVersion();

} 

#endif

