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
  ReturnCode dapiGotoAzEl(AzEl& azeltest) {
    // Data we are sending to the server.
    // AzEl request;
    // request.set_return_code(azeltest.return_code());
    // request.set_az(azeltest.az());
    // request.set_el(azeltest.el());

    // Container for the data we expect from the server.
    ReturnCode reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->dapiGotoAzEl(&context, azeltest, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply;
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      ReturnCode fail;
      int rcf(666);
      fail.set_return_code(rcf);
      return fail;
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
  AzEl azeltest;
  int rc(0);
  double a(10);
  double e(20);
  azeltest.set_return_code(rc);
  azeltest.set_return_code(a);
  azeltest.set_return_code(e);
  ReturnCode result = x2dome.dapiGotoAzEl(azeltest);
  std::cout << "X2Dome received: " << static_cast<char>(result.return_code()) << std::endl;

  return 0;
}
