#include <stdio.h>

//X-Plane API
#include "XPLMPlugin.h"
#include "XPLMProcessing.h"
#include "XPLMDataAccess.h"
#include "XPLMUtilities.h"

//Custom library for publish Dataref
#include "owneddata.h"

OwnedData<int> mydata("andres/example");


static float MyFlightLoopCallback(
        float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop,
        int inCounter, void * inRefcon);

bool RegisterInPlugin(std::string, std::string, long const);


/*
 * XPluginStart
 *
 * Our start routine registers our window and does any other initialization we
 * must do.
 *
 */
PLUGIN_API int XPluginStart(char * outName, char * outSig, char * outDesc) {

    std::string name_plugin = "X-Plane Plugin by Andres B.G";
    strcpy(outName, name_plugin.c_str());
    strcpy(outSig, "Andres B.G");
    strcpy(outDesc, "X-Plane Plugin example");


    XPLMRegisterFlightLoopCallback(MyFlightLoopCallback, /* Callback */
                                   1.0, /* Interval */
                                   nullptr); /* refcon not used. */

    return 1;
}

/*
 * XPluginStop
 *
 * Our cleanup routine deallocates our window.
 *
 */
PLUGIN_API void XPluginStop(void) {
    printf("XPluginStop ha sido llamada al cerrar XPlane\n");
    XPLMUnregisterFlightLoopCallback(MyFlightLoopCallback, nullptr);

    mydata.unregister();
}

/*
 * XPluginDisable
 *
 * We do not need to do anything when we are disabled, but we must provide the handler.
 *
 */
PLUGIN_API void XPluginDisable(void)
{
}

/*
 * XPluginEnable.
 *
 * We don't do any enable-specific initialization, but we must return 1 to indicate
 * that we may be enabled at this time.
 *
 */
PLUGIN_API int XPluginEnable(void)
{

    mydata.registerReadWrite();

    return 5;
}

/*
 * XPluginReceiveMessage
 *
 * We don't have to do anything in our receive message handler, but we must provide one.
 *
 */
PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFromWho, long inMessage,
                                      void * inParam) {

}


float	MyFlightLoopCallback(
        float                inElapsedSinceLastCall,
        float                inElapsedTimeSinceLastFlightLoop,
        int                  inCounter,
        void *               inRefcon)
{

    //Read value from X-Plane
    int value = XPLMGetDatai(XPLMFindDataRef("andres/example"));


    /* Return 1.0 to indicate that we want to be called again in 1 second.*/
    return -1.0;
}
