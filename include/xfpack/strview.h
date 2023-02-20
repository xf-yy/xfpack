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

#ifndef __xfutil_strview_h__
#define __xfutil_strview_h__

#include <string.h>
#include <string>
#include <cassert>
#include <cstddef>
#include <errno.h>
#include <stdlib.h>
#include "xfpack/type.h"

namespace xfutil
{

#ifdef __linux__
static inline void StrCpy(char* dst, size_t dst_len, const char* src)
{
	memccpy(dst, src, '\0', dst_len);
	dst[dst_len-1] = '\0';
}
#else
static inline void StrCpy(char* dst, size_t dst_len, const char* src)
{
	_memccpy(dst, src, '\0', dst_len);
	dst[dst_len-1] = '\0';
}
#endif

static inline void StrCpy(char* dst, size_t dst_len, const char* src, size_t src_len)
{
	size_t min_len = MIN(dst_len, src_len);
	memcpy(dst, src, min_len);
	dst[min_len-1] = '\0';
}

////////////////////////////////////////////////////////
struct StrView
{
	const char* data;
	size_t size;

public:
	StrView()
	{
		data = "";
		size = 0;
	}

	explicit StrView(const char* data_)
	{
        Set(data_, strlen(data_));
	}

	explicit StrView(const char* data_, size_t size_)
	{
        Set(data_, size_);
	}
	
	explicit StrView(const std::string& str)
	{
        Set(str.data(), str.size());
	}
public:
	inline const char* Data() const 
	{
		return data;
	}

	inline size_t Size() const 
	{ 
		return size;
	}

	inline bool Empty() const 
	{ 
		return size == 0; 
	}
    
	char operator[](size_t idx) const
	{
		assert(idx < size);
		return data[idx];
	}

	inline void Clear() 
	{
		data = "";
		size = 0;
	}
	inline void Set(const char* data_, size_t size_)
	{
		data = data_;
		size = size_;
	}
	inline void Set(const char* data_)
	{
		data = data_;
		size = strlen(data_);
	}
	inline void Skip(size_t n) 
	{
		assert(n <= size);
		data += n;
		size -= n;
	}

	int Compare(const StrView& dst) const;
	
	bool operator<(const StrView& dst) const
	{
		return Compare(dst) < 0;
	}
	bool operator==(const StrView& dst) const
	{
		return (size == dst.size) && (memcmp(data, dst.data, dst.size) == 0);
	}
	bool operator!=(const StrView& dst) const
	{
		return (size != dst.size) || (memcmp(data, dst.data, dst.size) != 0);
	}
	
	bool StartWith(const StrView& str) const 
	{
		return ((size >= str.size) && (memcmp(data, str.data, str.size) == 0));
	}
	bool EndWith(const StrView& str) const
	{
		return ((size >= str.size) && (memcmp(data+(size-str.size), str.data, str.size) == 0));
	}
	uint32_t GetPrefixLength(const StrView& str) const;

};


}

#endif

