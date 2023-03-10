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

#include "xfpack/block_list.h"
#include "xfpack/type.h"
#include "block_pool.h"

namespace xfutil
{

BlockList::BlockList(BlockPool& block_pool)
	: m_block_pool(block_pool)
{
	assert(m_block_pool.BlockSize() >= 1024);
	m_bufs.reserve(32);
}

BlockList::~BlockList() 
{
	Free();
}

void BlockList::Free()
{
	for(size_t i = 0; i < m_bufs.size(); ++i) 
	{
        BlockBuffer& buf = m_bufs[i];
        if(buf.capacity == m_block_pool.BlockSize())
        {
            m_block_pool.Free(buf.buf);
        }
        else
        {
            xfree(buf.buf);
        }
	}
	m_bufs.clear();
}

BlockBuffer* BlockList::Alloc(uint32_t size) 
{
    BlockBuffer buf;
    buf.size = 0;

	if(size <= m_block_pool.BlockSize())
	{
		buf.buf = m_block_pool.Alloc();
        buf.capacity = m_block_pool.BlockSize();
    }
    else
    {
        size = ALIGN_UP(size, 4096);

		buf.buf = xmalloc(size);
		buf.capacity = size;
	}
	
    m_bufs.push_back(buf);

    return &m_bufs.back();
}

} 

