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

#include "common.h"
#include "xfpack.h"
#include "block_pool.h"

using namespace xfutil;

namespace xfpack 
{


//库版本号
#define XFPACK_MAJOR_VERSION		0       //<65536
#define XFPACK_MINOR_VERSION		1       //<256
#define XFPACK_PATCH_VERSION		0       //<256
#define XFPACK_VERSION_DESC		    "0.1.0"

static BlockPool s_block_pool;

const char* GetVersionString()
{
	return XFPACK_VERSION_DESC;
}

uint32_t GetVersion()
{
	return (XFPACK_MAJOR_VERSION<<16) | (XFPACK_MINOR_VERSION<<8) | XFPACK_PATCH_VERSION;
}

bool Init(uint32_t block_size, uint32_t block_cache_num)
{
    return s_block_pool.Init(block_size, block_cache_num);
}

BlockPool& GetBlockPool()
{
    return s_block_pool;
}

}  


