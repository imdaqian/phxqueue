/*
Tencent is pleased to support the open source community by making PhxQueue available.
Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.
Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

<https://opensource.org/licenses/BSD-3-Clause>

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
*/



/* lock_server_config.cpp

 Generated by phxrpc_pb2server from lock.proto

*/

#include "lock.pb.h"
#include "lock_server_config.h"


LockServerConfig::LockServerConfig() {}

LockServerConfig::~LockServerConfig() {}

bool LockServerConfig::Read(const char *config_file) {
    bool ret{ep_server_config_.Read(config_file)};

    if (0 == strlen(ep_server_config_.GetPackageName())) {
        ep_server_config_.SetPackageName(phxqueue::comm::proto::GetLockInfoRequest::
                                         default_instance().GetDescriptor()->
                                         file()->package().c_str());
    }

    // read Extra
    phxrpc::Config config;
    if (!config.InitConfig(config_file)) {
        return false;
    }
    ret &= config.ReadItem("Lock", "Topic", topic_, sizeof(topic_));
    ret &= config.ReadItem("Lock", "DataDirPath", data_dir_path_, sizeof(data_dir_path_));
    ret &= config.ReadItem("Lock", "PhxQueueGlobalConfigPath", phxqueue_global_config_path_, sizeof(phxqueue_global_config_path_));
    ret &= config.ReadItem("Lock", "PaxosPort", &paxos_port_);

    return ret;
}

phxrpc::HshaServerConfig &LockServerConfig::GetHshaServerConfig() {
    return ep_server_config_;
}


const char *LockServerConfig::GetTopic() const {
    return topic_;
}

const char *LockServerConfig::GetDataDirPath() const {
    return data_dir_path_;
}

const char *LockServerConfig::GetPhxQueueGlobalConfigPath() const {
    return phxqueue_global_config_path_;
}

int LockServerConfig::GetPaxosPort() const {
    return paxos_port_;
}
