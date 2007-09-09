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

// Standard C++ library includes
#include <assert.h>

// 3rd party library includes

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
#include "hexgrid.h"

namespace FIFE {
	HexGrid::HexGrid(): CellGrid() {
	}

	HexGrid::~HexGrid() {
	}

	bool HexGrid::isAccessible(const Point& curpos, const Point& target) {
		if (curpos == target)
			return true;
		if ((curpos.x == target.x) && (curpos.y - 1 == target.y))
			return true;
		if ((curpos.x == target.x) && (curpos.y + 1 == target.y))
			return true;
		if ((curpos.x + 1 == target.x) && (curpos.y == target.y))
			return true;
		if ((curpos.x - 1 == target.x) && (curpos.y == target.y))
			return true;

		if ((curpos.x - 1 == target.x) && (curpos.y - 1 == target.y))
			return true;
		if ((curpos.x + 1 == target.x) && (curpos.y + 1 == target.y))
			return true;

		return false;
	}

	float HexGrid::getAdjacentCost(const Point& curpos, const Point& target) {
		assert(isAccessible(curpos, target));
		if (curpos == target) {
			return 0;
		}
		return 1;
	}
	
	const std::string& HexGrid::getName() const {
		static std::string hexGrid("Hex Grid");
		return hexGrid;
  	}

	DoublePoint HexGrid::getOffset(const Point& curpos, const Point& target, double distance) {
		assert(1);
		return DoublePoint(0,0);
	}

	DoublePoint HexGrid::toElevationCoordinates(const DoublePoint& layer_coords) {
		assert(1);
		return m_matrix * layer_coords;
	}

	DoublePoint HexGrid::toExactLayerCoordinates(const DoublePoint& elevation_coord) {
		assert(1);
		return m_inverse_matrix * elevation_coord;
	}

	Point HexGrid::toLayerCoordinates(const DoublePoint& elevation_coord) {
		assert(1);
		return Point(0,0);
	}
	
	void HexGrid::getVertices(std::vector<DoublePoint>& vtx, const Point& cell) {
		assert(1);
	}
}