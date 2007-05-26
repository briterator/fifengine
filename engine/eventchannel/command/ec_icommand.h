/***************************************************************************
 *   Copyright (C) 2005-2007 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

#ifndef FIFE_EVENTCHANNEL_ICOMMAND_H
#define FIFE_EVENTCHANNEL_ICOMMAND_H

// Standard C++ library includes
//

// 3rd party library includes
//

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
//
#include "../base/ec_ievent.h"
#include "ec_commandids.h"

namespace FIFE {

	/**  Interface for commands
	 * Commands are arbitrary events e.g. send from one subsystem to another
	 */
	class ICommand: public IEvent {
	public:
		/** Gets the type of this command
		 * @return type of this command
		 */
		virtual CommandType getCommandType() = 0;

		/** Gets the code of this command. Meaning of code depends on the command type
		 * @return code of this command
		 */
		virtual int getCode() = 0;

		/** Gets the data pointer 1 of this command. Meaning of data depends on the command type
		 * @return data 1 of this command
		 */
		virtual void* getData1() = 0;

		/** Gets the data pointer 2 of this command. Meaning of data depends on the command type
		 * @return data 2 of this command
		 */
		virtual void* getData2() = 0;

		virtual ~ICommand() {}
	};

} //FIFE

#endif