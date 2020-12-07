#pragma once

#include "depthai/openvino/OpenVINO.hpp"
#include "depthai/pipeline/Node.hpp"

// standard
#include <fstream>

// shared
#include <depthai-shared/pb/properties/NeuralNetworkProperties.hpp>

namespace dai {
namespace node {
class NeuralNetwork : public Node {
    dai::NeuralNetworkProperties properties;

    std::string getName() override;
    std::vector<Output> getOutputs() override;
    std::vector<Input> getInputs() override;
    nlohmann::json getProperties() override;
    std::shared_ptr<Node> clone() override;
    tl::optional<OpenVINO::Version> getRequiredOpenVINOVersion() override;
    // void loadAssets(AssetManager& assetManager) override;

    void loadBlob(const std::string& path);

    std::string blobPath;
    OpenVINO::Version networkOpenvinoVersion;

   public:
    NeuralNetwork(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId);

    Input input{*this, "in", Input::Type::SReceiver, {{DatatypeEnum::Buffer, true}}};
    Output out{*this, "out", Output::Type::MSender, {{DatatypeEnum::NNData, false}}};

    // Specify local filesystem path to load the blob (which gets loaded at loadAssets)
    void setBlobPath(const std::string& path);
    void setNumPoolFrames(int numFrames);
};

}  // namespace node
}  // namespace dai
