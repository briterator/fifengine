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

#ifndef FIFE_OBJECT_H
#define FIFE_OBJECT_H

// Standard C++ library includes

// 3rd party library includes

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
#include "location.h"

namespace FIFE { namespace model {

	class Layer;

	class Object;

	/**
	 *  An Instance is an "instantiation" of an Object at a Location. 
	 */
	class Instance {
		public:

			/** Constructor
			 */
			Instance(const Object* object, const Location& location)
				: m_object(object), m_location(location)
			{ }

			const Object* getObject();

			void setPosition(const Point& p);

			const Point& getPosition() const;
			Layer* getLayer() const;
			const Location& getLocation() const;

		private:

			const Object* m_object;

			Location m_location;

			Instance(const Instance&);
			Instance& operator=(const Instance&);

			friend class Layer;
	};

	inline
	const Object* Instance::getObject() {
		return m_object;
	}

	inline
	void Instance::setPosition(const Point& p) {
		m_location.position = p;
	}

	inline
	const Point& Instance::getPosition() const {
		return m_location.position;
	}
	
	inline
	Layer* Instance::getLayer() const {
		return m_location.layer;
	}

	inline
	const Location& Instance::getLocation() const {
		return m_location;
	}

} } // FIFE::model

#endif
