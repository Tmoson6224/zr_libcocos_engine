/****************************************************************************
 Copyright (c) 2021-2023 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
****************************************************************************/

#pragma once

#include "primitive/PrimitiveDefine.h"

namespace cc {
/**
 * @en
 * The definition of the parameter for building a circle.
 * @zh
 * 圆形参数选项。
 */
struct ICircleOptions : public IGeometryOptions {
    // The segments. Default to 64.
    uint32_t segments{64};
};

/**
 * @en
 * Generate a circle with radius 1, centered at origin,
 * but may be repositioned through the `center` option.
 * @zh
 * 生成一个圆，其半径是单位1，中心点在原点。
 * @param options 参数选项。
 */
IGeometry circle(ccstd::optional<ICircleOptions> &options);

} // namespace cc
