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

#include "xfpack/strview.h"

namespace xfutil
{

int StrView::Compare(const StrView& dst) const
{
	const size_t min_size = MIN(size, dst.size);
	int ret = memcmp(data, dst.data, min_size);
	if(ret == 0)
	{
		if(size < dst.size)
		{
			ret = -1;
		}
		else if(size > dst.size)
		{
			ret = 1;
		}
	}
	return ret;
}

uint32_t StrView::GetPrefixLength(const StrView& str) const
{
	uint32_t min_len = MIN(size, str.size);
	for(uint32_t i = 0; i < min_len; ++i)
	{
		if(data[i] != str.data[i])
		{
			return i;
		}
	}
	return min_len;
}

} 

