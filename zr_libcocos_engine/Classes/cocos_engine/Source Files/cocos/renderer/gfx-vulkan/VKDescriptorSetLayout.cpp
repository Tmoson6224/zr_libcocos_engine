/****************************************************************************
 Copyright (c) 2020-2023 Xiamen Yaji Software Co., Ltd.

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

#include "VKDescriptorSetLayout.h"
#include "VKCommands.h"
#include "VKDevice.h"

namespace cc {
namespace gfx {

CCVKDescriptorSetLayout::CCVKDescriptorSetLayout() {
    _typedID = generateObjectID<decltype(this)>();
}

CCVKDescriptorSetLayout::~CCVKDescriptorSetLayout() {
    destroy();
}

void CCVKDescriptorSetLayout::doInit(const DescriptorSetLayoutInfo & /*info*/) {
    _gpuDescriptorSetLayout = ccnew CCVKGPUDescriptorSetLayout;
    _gpuDescriptorSetLayout->id = generateID();
    _gpuDescriptorSetLayout->descriptorCount = _descriptorCount;
    _gpuDescriptorSetLayout->bindingIndices = _bindingIndices;
    _gpuDescriptorSetLayout->descriptorIndices = _descriptorIndices;
    _gpuDescriptorSetLayout->bindings = _bindings;

    for (auto &binding : _bindings) {
        if (hasAnyFlags(binding.descriptorType, DESCRIPTOR_DYNAMIC_TYPE)) {
            for (uint32_t j = 0U; j < binding.count; j++) {
                _gpuDescriptorSetLayout->dynamicBindings.push_back(binding.binding);
            }
        }
    }

    cmdFuncCCVKCreateDescriptorSetLayout(CCVKDevice::getInstance(), _gpuDescriptorSetLayout);
}

void CCVKDescriptorSetLayout::doDestroy() {
    _gpuDescriptorSetLayout = nullptr;
}

void CCVKGPUDescriptorSetLayout::shutdown() {
    if (defaultDescriptorSet != VK_NULL_HANDLE) {
        CCVKDevice::getInstance()->gpuRecycleBin()->collect(id, defaultDescriptorSet);
    }

    cmdFuncCCVKDestroyDescriptorSetLayout(CCVKDevice::getInstance()->gpuDevice(), this);
}

} // namespace gfx
} // namespace cc
