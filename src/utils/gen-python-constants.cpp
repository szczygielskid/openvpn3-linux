//  OpenVPN 3 Linux client -- Next generation OpenVPN client
//
//  Copyright (C) 2017      OpenVPN, Inc. <sales@openvpn.net>
//  Copyright (C) 2017      David Sommerseth <davids@openvpn.net>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as
//  published by the Free Software Foundation, version 3 of the
//  License.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

/**
 * @file   gen-python-constants.cpp
 *
 * @brief  Generates a Enum classes of constants defined in
 *         dbus/constants.hpp
 */

#include <cstdint>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>

#include "dbus/constants.hpp"

using namespace std;


template <class T>
struct ConstantMapping
{
    ConstantMapping(const string name, T value)
        : name(name), value(value) {}

    const string name;
    T value;
};

#define MAP(t, m, n, v)  m.push_back(ConstantMapping<t>(n, t::v))

template <class T>
void Generator(string name, vector<ConstantMapping<T>> mapping)
{
    stringstream c;

    c << "class " << name << "(Enum):" << endl;
    for (auto& m : mapping)
    {
         c << "    " << m.name << " = " << (unsigned int)m.value << endl;
    }

    cout << c.str() << endl;
    cout << endl;
}


int main(int argc, char **argv)
{


    cout << "from enum import Enum" << endl << endl;

    vector<ConstantMapping<StatusMajor>> maj;
    MAP(StatusMajor, maj, "UNSET", UNSET);
    MAP(StatusMajor, maj, "CFG_ERROR", CONFIG);
    MAP(StatusMajor, maj, "CONNECTION", CONNECTION);
    MAP(StatusMajor, maj, "SESSION", SESSION);
    MAP(StatusMajor, maj, "PKCS11", PKCS11);
    MAP(StatusMajor, maj, "PROCESS", PROCESS);
    Generator("StatusMajor", maj);

    vector<ConstantMapping<StatusMinor>> min;
    MAP(StatusMinor, min, "UNSET", UNSET);
    MAP(StatusMinor, min, "CFG_ERROR", CFG_ERROR);
    MAP(StatusMinor, min, "CFG_OK", CFG_OK);
    MAP(StatusMinor, min, "CFG_INLINE_MISSING", CFG_INLINE_MISSING);
    MAP(StatusMinor, min, "CFG_REQUIRE_USER", CFG_REQUIRE_USER);
    MAP(StatusMinor, min, "CONN_INIT", CONN_INIT);
    MAP(StatusMinor, min, "CONN_CONNECTING", CONN_CONNECTING);
    MAP(StatusMinor, min, "CONN_CONNECTED", CONN_CONNECTED);
    MAP(StatusMinor, min, "CONN_DISCONNECTING", CONN_DISCONNECTING);
    MAP(StatusMinor, min, "CONN_DISCONNECTED", CONN_DISCONNECTED);
    MAP(StatusMinor, min, "CONN_FAILED", CONN_FAILED);
    MAP(StatusMinor, min, "CONN_AUTH_FAILED", CONN_AUTH_FAILED);
    MAP(StatusMinor, min, "CONN_RECONNECTING", CONN_RECONNECTING);
    MAP(StatusMinor, min, "CONN_PAUSING", CONN_PAUSING);
    MAP(StatusMinor, min, "CONN_PAUSED", CONN_PAUSED);
    MAP(StatusMinor, min, "CONN_RESUMING", CONN_RESUMING);
    MAP(StatusMinor, min, "CONN_DONE", CONN_DONE);
    MAP(StatusMinor, min, "SESS_NEW", SESS_NEW);
    MAP(StatusMinor, min, "SESS_BACKEND_COMPLETED", SESS_BACKEND_COMPLETED);
    MAP(StatusMinor, min, "SESS_REMOVED", SESS_REMOVED);
    MAP(StatusMinor, min, "SESS_AUTH_USERPASS", SESS_AUTH_USERPASS);
    MAP(StatusMinor, min, "SESS_AUTH_CHALLENGE", SESS_AUTH_CHALLENGE);
    MAP(StatusMinor, min, "SESS_AUTH_URL", SESS_AUTH_URL);
    MAP(StatusMinor, min, "PKCS11_SIGN", PKCS11_SIGN);
    MAP(StatusMinor, min, "PKCS11_ENCRYPT", PKCS11_ENCRYPT);
    MAP(StatusMinor, min, "PKCS11_DECRYPT", PKCS11_DECRYPT);
    MAP(StatusMinor, min, "PKCS11_VERIFY", PKCS11_VERIFY);
    MAP(StatusMinor, min, "PROC_STARTED", PROC_STARTED);
    MAP(StatusMinor, min, "PROC_STOPPED", PROC_STOPPED);
    MAP(StatusMinor, min, "PROC_KILLED", PROC_KILLED);
    Generator("StatusMinor", min);

    return 0;
}
