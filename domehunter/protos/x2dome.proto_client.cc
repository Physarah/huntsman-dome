/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "/home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/x2dome.grpc.pb.h"
#else
#include "x2dome.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using x2dome::ReturnCode;
using x2dome::AzEl;
using x2dome::IsComplete;
using x2dome::BasicString;
using x2dome::X2Dome;

class X2DomeClient {
 public:
  X2DomeClient(std::shared_ptr<Channel> channel)
      : stub_(X2Dome::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string dapiGotoAzEl(const std::string& az, el) {
    // Data we are sending to the server.
    AzEl request;
    request.set_az(az);
    request.set_el(el);

    // Container for the data we expect from the server.
    ReturnCode reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->dapiGotoAzEl(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.return_code();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<X2Dome::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).
  X2DomeClient x2dome(grpc::CreateChannel(
      "localhost:50051", grpc::InsecureChannelCredentials()));
  double az(10);
  double el(20):
  int reply = x2dome.dapiGotoAzEl(az, el);
  std::cout << "X2Dome received: " << reply << std::endl;

  return 0;
}
