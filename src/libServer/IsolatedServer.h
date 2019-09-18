/*
 * Copyright (C) 2019 Zilliqa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ZILLIQA_SRC_LIBSERVER_ISOLATEDSERVER_H_
#define ZILLIQA_SRC_LIBSERVER_ISOLATEDSERVER_H_

#include "LookupServer.h"

class Mediator;

class IsolatedServer : public LookupServer,
                       public jsonrpc::AbstractServer<IsolatedServer> {
  uint128_t m_blocknum;

 public:
  IsolatedServer(Mediator& mediator, jsonrpc::AbstractServerConnector& server,
                 const uint128_t& blocknum);
  ~IsolatedServer() = default;

  inline virtual void CreateTransactionI(const Json::Value& request,
                                         Json::Value& response) {
    response = this->CreateTransaction(request[0u]);
  }

  inline virtual void IncreaseBlocknumI(const Json::Value& request,
                                        Json::Value& response) {
    response = this->IncreaseBlocknum(request[0u].asUInt());
  }

  Json::Value CreateTransaction(const Json::Value& _json);
  std::string IncreaseBlocknum(const uint32_t& delta);
};

#endif  // ZILLIQA_SRC_LIBSERVER_ISOLATEDSERVER_H_
