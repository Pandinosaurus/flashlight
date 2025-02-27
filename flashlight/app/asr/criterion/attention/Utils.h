/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "flashlight/fl/flashlight.h"

namespace fl {
namespace app {
namespace asr {

fl::Variable maskAttention(
    const fl::Variable& input,
    const fl::Variable& sizes);
} // namespace asr
} // namespace app
} // namespace fl
