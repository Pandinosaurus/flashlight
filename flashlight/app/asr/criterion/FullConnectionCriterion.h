/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "flashlight/app/asr/criterion/CriterionUtils.h"
#include "flashlight/app/asr/criterion/Defines.h"
#include "flashlight/fl/flashlight.h"

namespace fl {
namespace app {
namespace asr {

class FullConnectionCriterion : public fl::BinaryModule {
 public:
  explicit FullConnectionCriterion(
      int N,
      fl::lib::seq::CriterionScaleMode scalemode =
          fl::lib::seq::CriterionScaleMode::NONE);

  fl::Variable forward(const fl::Variable& input, const fl::Variable& target)
      override;

  std::string prettyString() const override;

 private:
  friend class AutoSegmentationCriterion;
  FullConnectionCriterion() = default;

  int N_;
  fl::lib::seq::CriterionScaleMode scaleMode_;

  FL_SAVE_LOAD_WITH_BASE(
      fl::BinaryModule,
      fl::serializeAs<int64_t>(N_),
      scaleMode_)
};

typedef FullConnectionCriterion FCCLoss;
} // namespace asr
} // namespace app
} // namespace fl

CEREAL_REGISTER_TYPE(fl::app::asr::FullConnectionCriterion)
