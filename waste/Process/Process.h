/****************************************************************************
 * lulzKey. Let's close those effin Windows so penguins won't enter.        *
 *                                                                          *
 * Copyright (C) 2009  meh. [http://meh.doesntexist.org]                    *
 *                                                                          *
 * This program is free software: you can redistribute it and/or modify     *
 * it under the terms of the GNU Affero General Public License as published *
 * by the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                      *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU Affero General Public License for more details.                      *
 *                                                                          *
 * You should have received a copy of the GNU Affero General Public License *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 ****************************************************************************/

/**
 * @file Process/Process.h
 *
 * @brief Process header
 *
 * @see Kernel::Process::Context
 * @see Kernel::Process::State
 */

#ifndef _LKEY_SCHEDULER_PROCESS_
#define _LKEY_SCHEDULER_PROCESS_

#include <Type.h>

namespace Kernel {

class Process
{
  public:
    #include <Process/State.h>
    #include <Process/Context.h>

  private:
    Type::u32        _pid;
    Process::State   _state;
    Process::Context _context;

  public:
    Process (void);

    void      pid (Type::u32 pid);
    Type::u32 pid (void);

    void           state (Process::State state);
    Process::State state (void);

    void             context (Process::Context context);
    Process::Context context (void);
};

}

#endif
