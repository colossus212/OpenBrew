/*
 * This file is part of OpenBrew.
 *
 * OpenBrew is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenBrew is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenBrew.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (c) 2012 James McLean <james.mclean@gmail.com>
 *
 */

#ifndef PUMP_H_
#define PUMP_H_

class Pump {
protected:
	int pumpRelaySysFsPath;

public:
	Pump();
	virtual ~Pump();

	int getPumpRelaySysFsPath() const {
		return pumpRelaySysFsPath;
	}

	void setPumpRelaySysFsPath(int pumpRelaySysFsPath) {
		this->pumpRelaySysFsPath = pumpRelaySysFsPath;
	}
};

#endif /* PUMP_H_ */
