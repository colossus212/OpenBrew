
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

#include <iostream>
#include <fstream>
#include <string>
#include <syslog.h>

#include "defines.h"

#include "batch/Batch.h"
#include "step/hltAutoFill.h"
#include "step/hltBoil.h"

using namespace std;

int main ()
{

	// Syslog
	openlog("openbrew", LOG_PID|LOG_CONS, LOG_USER);

	syslog(LOG_INFO, "OpenBrew. Starting up. ");

	// This looks a bit funky because the slashes all need to be escaped.
	cout << "-------------------------------------------------  " << endl;
	cout << "  ___                   ____                       " << endl;
	cout << " / _ \\ _ __   ___ _ __ | __ ) _ __ _____      __   " << endl;
	cout << "| | | | '_ \\ / _ \\ '_ \\|  _ \\| '__/ _ \\ \\ /\\ / /   " << endl;
	cout << "| |_| | |_) |  __/ | | | |_) | | |  __/\\ V  V /    " << endl;
	cout << " \\___/| .__/ \\___|_| |_|____/|_|  \\___| \\_/\\_/     " << endl;
	cout << "      |_|                                          " << endl;
	cout << "-------------------------------------------------  " << endl;
	cout << "Author: James McLean <james.mclean@gmail.com       " << endl;
	cout << "-------------------------------------------------  " << endl;

    char * recipePath = "docs/step_mash_recipe.xml";

    ifstream recipe(recipePath, ifstream::in);

    if(recipe.good()) {
        // File is OK and readable. Pass it to the Batch function
        // to generate this batch.

        Batch batch(recipePath);
        batch.run();

    } else {
        // Define steps. So, this loads objects.
        hltAutoFill hltAutoFill;
        hltBoil hltBoil;
        // Add them.

        // This loads the batch object and populates it.
        Batch batch;
        batch.addStep(hltAutoFill);
        batch.addStep(hltBoil);
        batch.run();

    }

    // Main processing loop. Run until forever.
//  while(1) {
//      batch.run();
//
//      // can we call some kind of CLI function here?
//    }


    syslog(LOG_INFO, "OpenBrew. Shutting down. Thanks for brewing with OpenBrew! ");

    closelog();
    return 0;
}
